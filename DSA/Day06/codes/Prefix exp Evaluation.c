// Prefix exp Evaluation 
#include<stdio.h>
#include"stack.h"
#include<math.h>
#include<string.h>

int prefix_evaluation(char prefix[]);
int is_operand(char ch);
int calculate(int op1, int op2, char op);

int main()
{
    char prefix[] = "+-+59*4-8/62$1-73";
    int result = prefix_evaluation(prefix);
    printf("Result = %d\n",result);
    return 0;
}

int prefix_evaluation(char prefix[])
{
    stack s;
    init_stack(&s);
    //Start scanning the prefix expression from right to left
    for(int i = strlen(prefix)-1; i>=0; i--)
    {
        //If current element is an operand
        if(is_operand(prefix[i]))
        {
            //Push it onto the stack
            push(&s,prefix[i] - '0');
        }
        else //current element is an operator
        {
            //pop two elements (operands) from the stack.
		    //1st popped element will be 1st operand : op1
            int op1 = peek(&s);pop(&s);
		    //2nd popped element will be 2nd operand : op2
            int op2 = peek(&s); pop(&s);
            //Perform cur element operation between op1 and op2
            int res = calculate(op1,op2,prefix[i]);
            //Push back result onto the stack
            push(&s,res);
            //Repeat the above steps till end of prefix exp
        }
        
    }
    //Pop final result from the stack.
    int result = peek(&s); pop(&s);
    return result;
} 

int is_operand(char ch)
{
    return (ch >= 48 && ch <= 57);
}

int calculate(int op1, int op2, char op)
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
