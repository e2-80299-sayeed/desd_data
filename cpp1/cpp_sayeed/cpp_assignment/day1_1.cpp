#include<stdio.h>

struct account
{
char name[10];
char account_number[10];
char account_type[10];  //[saving/loan/ppf/nps]
int balance; // [minimun balance = 1000]
};	

void AcceptData(struct account *ac)
{
    printf("Enter name of Account Holder : ");
    scanf("%*c%[^\n]s",ac->name);
    printf("Enter Account Number : ");
    scanf("%*c%[^\n]s",ac->account_number);
    printf("Enter Account type [saving/loan/ppf/nps]: ");
    scanf("%*c%[^\n]s",ac->account_type);
    ac->balance = 1000;
} 
void Deposit(struct account *ac)
{
    int amt;
    printf("Enter Deposit Amount : ");
    scanf("%d",&amt);

    ac->balance += amt;
    printf("Current balance = %d\n",ac->balance);
}
void Withdraw(struct account *ac)
{
    int amt;
    printf("Enter withdraw amount  : ");
    scanf("%d", &amt);
    if((ac->balance-amt) < 1000)
        printf("Minimum A/C balance cannot be below 1000\n");
    else
        ac->balance -= amt;
    printf("Current balance = %d\n",ac->balance);
}
void Display(struct account ac)
{
    printf("name of Account Holder : %s \n",ac.name);
    printf("Account Number : %s \n",ac.account_number);
    printf("Account Type : %s \n",ac.account_type);
    printf("Balance : %d \n",ac.balance);
}

int main()
{
    struct account ac;
    int ch;
   do
   {
    printf("0.Exit\n1.Accept_data\n2.Deposit\n3.Withdraw\n4.Display\n");
    printf("Enter Choice : ");
    scanf("%d",&ch);
        
        switch (ch)
        {   
        case 0: goto EXIT;
                break;
        case 1: 
                AcceptData(&ac);
                break;
        case 2 : 
                Deposit(&ac);
                break;
        case 3 : 
                Withdraw(&ac);
                break;
        case 4 :
                Display(ac);
                break;
        default:
            printf("Enter valid choice !!\n");
            break;
        }
    
    }while(ch != 0);

EXIT:   
    return 0;
}
