#include <iostream>
#include<string.h>
using namespace std;

class ExceptionHandling
{
public:
int age,vehicle;
long income;
string city;
void getdata()
{
cout<<"Enter the Age:";
cin>>age;
cout<<"Enter the Income:";
cin>>income;
cout<<"Enter the City:";
cin>>city;
cout<<"Enter the type of Vehicle:";
cin>>vehicle;
}
void check()
{
try 
    {
  if (age<18|age>55)
  {
      throw"Age should be between 18 and 55";
  }
      
    }
catch (const char* msg) 
    {
    cout<<msg<<endl;
    }

try 
    {
        if (50000<income|income>100000)
        {
            throw"Income should be between 5,000 and 1,00,000";
        }
    
    } 
catch (const char* msg) 
    {
        cout<<msg<<endl;
    
    }

try 
    {
        if(city=="Pune"||city=="Mumbai"||city=="Banglore"||city=="Chennai")
            {

            }
        else
            {
                throw"City should be among Pune, Mumbai, Banglore, Chennai";
            }
    
    } 
catch (const char* msg)
    {
        cout<<msg<<endl;
    }
try
{
    if(vehicle=4)
    {}
    else
    {
        throw"Vehicle should be 4 wheeler";
    }
}
catch (const char* msg)
{
    cout<<msg<<endl;
}
}
};
int main()
{
    ExceptionHandling eh;
    eh.getdata();
    eh.check();
    return 0;
}
