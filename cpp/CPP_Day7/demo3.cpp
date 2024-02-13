#include<iostream>
using namespace std;

int main()
{

    int n,d;
    cout<<"\nenter n and d";
    try
    {
        cin>>n>>d;
        if(d==0)
            throw "error";
        cout<<"\n result="<<n/d;
    }
    catch(char e)
    {
        cout<<"\n invalid input (char)";
    }
    catch(int e)
    {
        cout<<"\n invalid input (int)";
    }
    catch(...)
    {
        cout<<"\n invalid input (...)";
    } 
    cout<<"\n";
    return 0;
}