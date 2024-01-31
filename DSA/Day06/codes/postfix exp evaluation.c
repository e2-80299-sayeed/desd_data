// postfix exp evaluation
#include<stdio.h>
#include"stack.h"
#include<math.h>

int calculate(int op1,int op2,char op);
int is_operand(char ch);
int postfix_evaluation(char postfix[]);

int main()
{
    char postfix[] = "59+4862/-*-173-$+";
    int result = postfix_evaluation(postfix);
    printf("Result = %d\n ",result);
    return 0;
}

int postfix_evaluation(char postfix[])
{
    stack s;
    init_stack(&s);
    // Start scanning the postfix exp from left to right
    for(int i = 0;postfix[i] != '\0'; i++)
    {
        //If current element is an operand
        if(is_operand(postfix[i]))
        {
            //Push it onto the stack
            push(&s,postfix[i] - '0');
        }
        else //current element is an operator
        {
        //Pop two elements (operands) from the stack.
		//1st popped element will be 2nd operand : op2
            int op2 = peek(&s); pop(&s);
		//2nd popped element will be 1st operand : op1
            int op1 = peek(&s);pop(&s);
		//Perform cur element operation between op1 and op2
            int res = calculate(op1,op2,postfix[i]);
        //Push back result onto the stack
            push(&s,res);
        //Repeat the above steps till end of postfix exp
        }
    }
     // Pop final result from the stack.  
      int result = peek(&s);
       pop(&s);
       return result;
}

int is_operand(char ch)
{
    return (ch >= 48 && ch <=57);
}

int calculate(int op1,int op2,char op)
{
    switch(op)
    {
        case '*' :  return op1 * op2;
        case '/' :  return op1 / op2;
        case '%' :  return op1 % op2;
        case '+' :  return op1 + op2;
        case '-' :  return op1 - op2;
        case '$' :  return pow(op1,op2);
        default : return 0;
    }
}