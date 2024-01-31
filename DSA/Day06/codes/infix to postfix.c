// infix to postfix
#include<stdio.h>
#include"stack.h"

int priority(char ch);
void infix_to_postfix(char infix[],char postfix[]);
int is_operand(char ch);

int main()
{
    char infix[] = "5+9-4*(8-6/2)+1$(7-3)";
    char postfix[30];
    printf("Infix = %s\n",infix);
    infix_to_postfix(infix,postfix);
    printf("Postfix = %s\n",postfix);
    
    return 0;
}

void infix_to_postfix(char infix[],char postfix[])
{
    stack s;
    init_stack(&s);
    int j = 0;
    //start scanning from left to right
    for(int i =0; infix[i] != '\0'; i++)
    {
    //If(current element is an operand)
    if(is_operand(infix[i]))
    {
    //Append it to the postfix expression
        postfix[j++] = infix[i];
    }
    //Else if (current element is opening bracket '('  )
    else if(infix[i] == '(')
    {
    //Push it onto the stack
        push(&s,'(');
    }
    //Else if current element is closing bracket ')' 
	else if(infix[i] == ')')
    {
    //Pop elements from the stack and append them to postfix exp till its corresponding opening brackets does not occur
        char ch;
        while((ch = peek(&s)) != '(')
        {
            postfix[j++] = ch;
            pop(&s);
        }
     //Pop opening brackets from the stack and discard both the brackets
        pop(&s);
    }
   
    //Else (current element is an operator)
    else
    {
	//While(stack is not empty  &&  priority of topmost element >= priority of current element)
	while(!stack_empty(&s) && priority(peek(&s)) >= priority(infix[i]))
   	 {
        //Pop element from the stack and append it to postfix expression
        postfix[j++] = peek(&s);
        pop(&s);        
	}
		//Push current element onto the stack.
        push(&s,infix[i]);
    }
    //Repeat the above steps till end of infix expression
    }
    //Pop all the remaining elements from the stack one by one 
    //and append them to postfix expression
 while(!stack_empty(&s))
    {
        postfix[j++] = peek(&s);
        pop(&s);
    }
    postfix[j] = '\0';
    
}

int is_operand(char ch)
{
    return (ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122);
}

int priority(char ch)
{
    switch(ch)
    {
        case '$' : return 10;
        case '*' :
        case '/' :
        case '%' : return 9;
        case '+' :
        case '-' : return 8;
        case '(' :
        case ')' :
        default : return 0;
    }
}
