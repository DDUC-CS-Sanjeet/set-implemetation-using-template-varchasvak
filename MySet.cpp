#include<iostream>
using namespace std;
template <typename T>
class MySet
{  
    int cardinality;
    T *arr;
    public:

    MySet()
    {
        cardinality=0;
        arr=new T [0];
    }
    MySet(int a)
    {
        cardinality=a;
        arr=new T [cardinality];
    }
    void input()
    {
        arr=new T [cardinality];
        cout<<"Enter the elements: \n";
        for(int i=0;i<cardinality;i++)
        cin>>arr[i];
    }
    void removeduplicate()
    {
        for(int i=0;i<cardinality;i++)
        {
            for(int j=i+1;j<cardinality;)
            {
            if(arr[i]==arr[j])
            {
                for(int k=j;k<cardinality-1;k++)
                {
                arr[j]=arr[j+1];
                cardinality--;
                }
            }
            else
            j++;
            }    
        }
    }
    MySet operator +( MySet obj)//Union
    { int j=0;
       MySet s3(cardinality+obj.cardinality);
       for(int i=0;i<cardinality;i++)
       {
           s3.arr[j++]==arr[i];
       }
       for(int i=0;i<obj.cardinality;i++)
       {
           s3.arr[j++]==obj.arr[i];
       }
       s3.removeduplicate();
       return s3;
    }
    
    MySet operator *(MySet obj)//Intersection
    {   int c;
        if(cardinality>obj.cardinality)
        c=obj.cardinality;
        else
        c=cardinality;
        MySet s3(c);
        int j;
        for(int i=0;i<c;i++)
        {
            if(obj.check(arr[i]))
            s3.arr[j++]=arr[i];
        }
        s3.cardinality=j;
        return s3;
    }
    MySet operator -(MySet obj)// Difference
    {
        MySet s3(cardinality+obj.cardinality);
        int j=0;
        for(int i=0;i<cardinality;i++)
        {
            if(!obj.check(arr[i]))
            s3.arr[j++]=arr[i];
        }
        cardinality=j;
        return s3;
    }
    MySet operator ^(MySet obj)// Symmetric Difference
    {
        MySet s3(obj.cardinality+cardinality);
        int j=0;
        for(int i=0;i<cardinality;i++)
            if(!obj.check(arr[i]))
            s3.arr[j++]=arr[i];
        for(int i=0;i<obj.cardinality;i++)
            if(!check(obj.arr[i]))
                s3.arr[j++]=obj.arr[i];
        cardinality=j;
        return s3;
    } 
    bool check(T element)
    {
        for(int i=0;i<cardinality;i++)
        {if (arr[i]==element)
            return true;
        }
        return false;
    }  
    void display()
    {
        cout<<"{ ";
        for(int i=0;i<cardinality;i++)
        cout<<arr[i];
        cout<<" }";
    }
};

int main()
{
    int choice;
    int num;
    cout<<"Enter the size of the set: ";
    cin>>num;
    MySet<int> set1(num);
    set1.input();
    set1.removeduplicate();
    cout<<"Enter the size of the second set: ";
    cin>>num;
    MySet<int> set2(num);
    set2.input();
    set2.removeduplicate();
    MySet<int> set3;
	char ans;
	do
    {
        cout<<"What operation do you want to perform on the given sets: \n 1.Intersection \n 2.Union\n 3.Difference\n 4.Symmetric Difference\n ";
        cin>>choice;
        switch(choice)
        {  
            case 1:set3=set1*set2;
                   set3.display(); 
                break;

            case 2:set3=set1+set2;
                    set3.display();
                break;

            case 3:set3=set1-set2;
                    set3.display();
                break;

            case 4:set3=set1^set2;
                   set3.display(); 
                break;

            default:cout<<"Invalid entry. ";
        }
        cout<<"To continue press 0, else press any other number.";
        cin>>ans;
    }while(ans=='0');
    return 0;
}
