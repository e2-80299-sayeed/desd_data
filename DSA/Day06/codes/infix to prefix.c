// infix to prefix
#include<stdio.h>
#include"stack.h"
#include<string.h>

void infix_to_prefix(char infix[],char prefix[]);
int priority(char ch);
int is_operand(char ch);

int main()
{
    char infix[] = "5+9-4*(8-6/2)+1$(7-3)";
    char prefix[30];
    printf("Infix = %s\n",infix);
    infix_to_prefix(infix,prefix);
    printf("prefix = %s\n",prefix);

    return 0;
}

void infix_to_prefix(char infix[],char prefix[])
{
    stack s;
    init_stack(&s);
    int j = 0;
    //start scanning from right to left
    for(int i = strlen(infix)-1; i >=0 ; i--)
    {
	//If(current element is an operand)
        if(is_operand(infix[i]))
        {
	    //Append it to the prefix expression
          prefix[j++] = infix[i];
        }
	// Else if (current element is closing bracket ')'  )
        else if(infix[i] == ')')
        {
            //Push it onto the stack
            push(&s,')');
        }
	//Else if (current element is opening bracket '('  )
		else if(infix[i] == '(')
        {
            // Pop elements from the stack and append them to prefix exp
            // till its corresponding closing brackets does not occur
            char ch;
            while((ch = peek(&s)) != ')')
            {
                prefix[j++] = ch;
                pop(&s);
            }
            //Pop closing brackets from the stack and discard both the brackets
            pop(&s);
        }
         else // (current element is an operator)
         {
	//	While(stack is not empty  &&  priority of topmost element > priority of current element)
		while(!stack_empty(&s) && priority(peek(&s)) > priority(infix[i]))
        {
		//	Pop element from the stack and append it to prefix expression
            prefix[j++] = peek(&s);
            pop(&s);
        }
		//Push current element onto the stack.
        push(&s,infix[i]);
         }
  // Repeat the above steps till end of infix expression
    }
    // Pop all the remaining elements from the stack one by one and append them to prefix expression.
	while(!stack_empty(&s))
    {
        prefix[j++] = peek(&s);
        pop(&s);
    }
    // Reverse the prefix expression.
    prefix[j] = '\0';
    strrev(prefix);
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
        default : return 0;
    }
}