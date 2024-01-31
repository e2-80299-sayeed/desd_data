
void ADD(double op1,char opr, double op2)
{
	//int res;

	opr=='+'?printf("Addition= %.2lf\n",op1+op2):printf("Invalid operator");
/*
	if(opr=='+')
	{
	res = op1 + op2;	
	printf("Addition= %d\n",res);
	}
	
else	
	{
	printf("invalid operator!!\n");
}

*/
}

void SUB(double op1,char opr,double op2)
{

	opr=='-'?printf("Subtraction= %.2lf\n",op1-op2):printf("Invalid operator");

}
void MUL(double op1,char opr,double op2)
{


	opr=='*'?printf("Multiplication= %.2lf\n",op1*op2):printf("Invalid operator");

}

void DIV(double op1,char opr,double op2)
{


	opr=='/'?printf("Division= %.2lf\n",op1/op2):printf("invalid operator!!\n");

}
