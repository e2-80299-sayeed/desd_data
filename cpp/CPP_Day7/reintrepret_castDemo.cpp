
#include<iostream>
using namespace std;
class complex
{
	int real, imag;
public :
	complex(int r = 1,int im=1)
	{
		this->real = r;
		this->imag = im;
	}
	void print()
	{
		cout << "\nnum=" << real << "+J" << imag;
	}
};

int main()
{
	complex c1(22,33);
	int * ptrNum = reinterpret_cast<int*>(&c1);
	cout << "ptr num=" << *ptrNum;// print c1.real number
	*ptrNum = 99;//change value of c1.real to 99
	c1.print();
	return 0;
}








