#include<stdlib.h>
#include<ncurses.h>
#include<string.h>
#include "2_header.h"

struct node* get_number(struct node* num)
{
char ch, digit[4];
int counter, i, int_digit = 0;
struct node *new_node, *next_node;

again:

counter = 0;
strncpy(digit, "    ", 4);

	do
	{
	ch=getch();
		if(((ch >= 48 && ch <= 57) && counter < 4) || ((ch == ',' || ch == 36) && counter == 4))
		{
			if(counter < 4)
			{
			digit[counter]=ch;
			}
			
			else
			{
			new_node = (struct node*)malloc(sizeof(struct node));
				
				for(i = 0, int_digit = 0; i <4; i++)
				{
				int_digit = (int_digit * 10) + ((int)digit[i] - 48);
				}
				
			new_node->data = int_digit;
			new_node->next = num;
			num = new_node;
			int_digit = 0;
			strncpy(digit, "    ", 4);
			/*	if(num == NULL)
				{
    				num=new_node;
    				}
    				
    				else
    				{
    				old = num;
    					while(old->next != NULL)
    					{
    					old = old->next;
    					}
    				old->next = new_node;
    				} */
			}
			
			counter=(counter+1)%5;
			
		}
		
		else
		{
			if(num != NULL) 
			{
				while(num->next != NULL)
				{
				next_node = num->next;
				num->next = num->next->next;
				free(next_node);
				}
			
			num = NULL;
			}
		
		printw("Invalid number, please enter again!\n");
		goto again;
		}
	}while(ch != 36);
	
return num;
/*	old = num;
	i=0;
	while(old != NULL)
  	{
  	i++;
  		if(old->next != NULL)
  		{
    		printw("%04d,",old->data);
    		}
    		else
    		{
    		printw("%04d",old->data);
    		}
    	old=old->next;
  	}
  printw("\nNumber of Nodes in list: %d", i);*/
}

void put_number(struct node* num)
{
char ch;
	if(num->next != NULL)
	{
	put_number(num->next);
	printw(",%04d",num->data);
	}
	else
	{
	printw("%04d",num->data);
	}
}

struct node* add_number(struct node* new_num1, struct node* new_num2)
{
struct node *sum = NULL, *old, *new_node;
int addition = 0, carry = 0;

	while(new_num1 != NULL && new_num2 != NULL)
	{
	addition = new_num1->data + new_num2->data + carry;
	carry = addition/10000;
	addition = addition % 10000;
	
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = addition;
	new_node->next = NULL;
		
		if(sum == NULL)
		{
    		sum=new_node;
		}
    				
		else
		{
		old = sum;
			while(old->next != NULL)
			{
    			old = old->next;
    			}
    		old->next = new_node;
    		}
    	new_num1 = new_num1->next;
    	new_num2 = new_num2->next;			
	}

	if(new_num1 != NULL)
	{
		while(new_num1 != NULL)
		{
		addition = new_num1->data + carry;
		
			if(addition > 9999)
			{
			carry = addition/10000;
			addition = addition % 10000;
			}
		
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = addition;
		new_node->next = NULL;
		
			if(sum == NULL)
			{
	    		sum=new_node;
			}
    				
			else
			{
			old = sum;
				while(old->next != NULL)
				{
	    			old = old->next;
	    			}
	    		old->next = new_node;
	    		}
	    	new_num1 = new_num1->next;				
		}
	}
	
	if(new_num2 != NULL)
	{
		while(new_num2 != NULL)
		{
		addition = new_num2->data + carry;
		
			if(addition > 9999)
			{
			carry = addition/10000;
			addition = addition % 10000;
			}
		
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = addition;
		new_node->next = NULL;
		
			if(sum == NULL)
			{
	    		sum=new_node;
			}
    				
			else
			{
			old = sum;
				while(old->next != NULL)
				{
	    			old = old->next;
	    			}
	    		old->next = new_node;
	    		}
	    	new_num2 = new_num2->next;				
		}
	}
	
	if(carry != 0)
	{
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = carry;
	new_node->next = NULL;
	old = sum;
		while(old->next != NULL)
		{
		old = old->next;
		}
	old->next = new_node;
	carry = 0;
	}
	
return sum;
}

struct node* multiply_number(struct node* new_num1, struct node* new_num2)
{
struct node *product1 = NULL, *product2 = NULL, *old, *new_node, *first_node;
unsigned int multiplication = 0, carry = 0;
int i, counter = 0;

first_node = new_num1;
	while(new_num2 != NULL)
	{
	new_num1 = first_node;
	
		while(new_num1 != NULL)
		{
		multiplication = (new_num2->data * new_num1->data) + carry;
		carry = multiplication/10000;
		multiplication = multiplication % 10000;
		
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = multiplication;
		new_node->next = NULL;

			if(product1 == NULL)
			{
	    		product1 = new_node;
			}
    				
			else
			{
			old = product1;
				while(old->next != NULL)
				{
	    			old = old->next;
	    			}
	    		old->next = new_node;
	    		}
	    	//printw("\nnew_num1: %lu\tnew_num2: %lu\tcarry: %lu\tproduct: %lu\n", new_num1->data, new_num2->data, carry, multiplication);
	    	//getch();
	    	new_num1 = new_num1->next;
		}
		
		if(carry != 0)
		{
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = carry;
		new_node->next = NULL;
		old = product1;
			while(old->next != NULL)
			{
			old = old->next;
			}
		old->next = new_node;
		carry = 0;
		}

		//printw("\nCarry node built");
		//getch();
		for(i=1; i<=counter; i++)
		{
		//printw("\nScaling pass %d.", i);
		//getch();
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = 0;
		new_node->next = product1;
		product1 = new_node;		
		}
		
	//printw("\nScaling done.");
	//getch();
	//printw("\n\nProduct1: ");
	//put_number(product1);
	//getch();
		if(product2 == NULL)
		{
		product2 = product1;
		}
		else
		{
		//printw("\n\nProduct2: ");
		//put_number(product2);
		//getch();
		product2 = add_number(product1, product2);
		}
	product1 = NULL;
	counter++;
	new_num2 = new_num2->next; 
	}
return product2;
}


