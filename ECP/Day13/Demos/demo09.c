#include<stdio.h>
#include<stdlib.h>

typedef enum category
{
	GROCERY, CLOTHING, ELECTRONICS, FURNITURE
}cat_t;

typedef struct product 
{
	char name[20];
	unsigned int qnt;
	float price;
	cat_t category;
}prod_t;

int menu_list(void);
void accept_product(prod_t *);
void print_product(prod_t *);
int add_product(prod_t);
void print_products(int);
void print_products_cat(int, cat_t);
char *to_string(cat_t);

prod_t *products;

int main(void)
{
	//printf("sizeof(prod_t) = %ld\n",sizeof(prod_t));

	int count, choice, cnt = 0, c;
	prod_t p;  //Declaration of structure variable to access strcture member.//sizeof(p) = 32bytes

	printf("Enter number of products : ");
	scanf("%d", &count);	//1
				   
				    //1		32bytes
	products = (prod_t *)calloc(count, sizeof(prod_t));
	
	//Choice = menu_list();		

	while((choice = menu_list()) != 0) // calling to menu_list function for accepting choice
	{		
			//1, 2
		switch(choice)
		{
			case 1:
				accept_product(&p); //sending address of struct variable
				cnt  = add_product(p);// sending value of struct variable. and no. of products count will be returned from the add_product() and will be stored in cnt.
				break;
			case 2:		       //1
				print_products(cnt); //sending no. of products
				break;
			case 3:
				
				printf("Enter Category(0-Grocery, 1-Clothing, 2-Electronics, 3- Furniture) : ");
				scanf("%d", &c); // c = 0;
				print_products_cat(cnt, c); // cnt = 1, c = 0
		}

	}
	
	free(products);

	return 0;
}

int menu_list(void)
{
	int choice;

	printf("0. Exit\n");
	printf("1. Add product\n");
	printf("2. List products\n");
	printf("3. List products by category\n");

	printf("Enter your choice : ");
	scanf("%d", &choice);

	return choice;// will return choice in while loop
}

void accept_product(prod_t *p)
{
	printf("Enter Product Info : ");
	printf("(Name, Qnt, Price) : ");
	scanf("%s %u %f", p->name, &p->qnt, &p->price);// taking product info from user.
	printf("Category(0-Grocery, 1-Clothing, 2-Electronics, 3- Furniture) : ");
	scanf("%u", &p->category); // 0
}
void print_product(prod_t *p) 
{
	printf("%-20s %-4u %-6.2f %-20s\n", p->name, p->qnt, p->price, to_string(p->category));//  calling to_string() to convert integer to string and storing it into category variable.
}

int add_product(prod_t p) //no. of products added
{
	static int i = 0;// scope is limited to add_product() and its life is throughout program.
	products[i++] = p; // here 32bytes are reserved per call. first value of i = 0 will be assigned and then it will be incremented.

	return i; // value of i = 1 will be returned in first call.
}

void print_products(int cnt)
{
	printf("Products : \n");
	for(int i = 0 ; i < cnt ; i++)   //cnt = 1
		print_product(&products[i]); // calling print_product() by passing address of allocated memory by calloc.		
}
			  // 1         0
void print_products_cat(int cnt, cat_t c)
{
	printf("Products : \n");
	for(int i = 0 ; i < cnt ; i++)
		if(c == products[i].category)
			print_product(&products[i]);		
}

char *to_string(cat_t c)  // in first call, c = 0
{
	switch(c)
	{
		case GROCERY: return "Grocery";
		case CLOTHING: return "Clothing";
		case ELECTRONICS: return "Electronics";
		case FURNITURE: return "Furniture";
	}
	return NULL;
}


























