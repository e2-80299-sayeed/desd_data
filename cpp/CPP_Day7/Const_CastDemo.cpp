
#include <iostream>
using namespace std;
void print(const int &i)
{
	int& iref=const_cast<int&>(i);
	iref=100;
	cout<<"\n iref="<<iref;
}

int main()
{
	int c=99;
	print(c);

}

