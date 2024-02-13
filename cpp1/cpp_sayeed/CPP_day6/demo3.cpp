
#include<iostream>
using namespace std;



int main()
{
    
    int n,d;
    try
    {
        cout<<"\n Enter n and d";
        cin>>n>>d;
        if (d==0)
            throw "Error";
        int r=n/d;
        cout<<"\n result="<<r;
    }
    catch(int e)
    {
        cout<<"\n divid by Zero error--(int)---";
    }
    catch(char v)
    {
        cout<<"\n divid by Zero error---(char)---";
    }    
    catch(...)
    {
        cout<<"\n divid by Zero error---(...)---";
    }
    cout<<"\n";
    return 0;
}