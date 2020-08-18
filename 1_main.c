#include<stdlib.h>
#include<ncurses.h>
#include<string.h>
#include "2_header.h"


int main()
{
char ch, operator;
struct node* new_num = NULL;
initscr();
raw();
keypad(stdscr, TRUE);

again1:

printw("\n\n1. Addition of Large Integers\n2. Multiplication of Large Integers\n3. Expression Evaluation\n4. Again\n5. Exit\n\nPress one option: ");
ch=getch();

if(ch < 49 || ch > 53 )
{
printw("\nInvalid Option!!! Enter a valid option...");
goto again1;
}

else
{
	if(ch == 53)
	{
	endwin();
	return 0;
	}
	
	if(ch == 52)
	{
	goto again1;
	}
	
	if(ch == 51)
	{
	struct node *new_num1 = NULL, *new_num2 = NULL, *result;
	printw("\n\nEnter expression in Base 10000 format (dddd,dddd,...,dddd$), getting terminated by '=' symbol :\n");
	new_num1 = get_number(new_num1);
		while((operator = getch()) != 61)
		{
			if(operator != 42 && operator != 43)
			{
			printw("\n\nInvalid operator!!!");
			goto again1;
			}
			
		new_num2 = get_number(new_num2);
			
			if(operator == 43)
			{
			new_num1 = add_number(new_num1, new_num2);
			new_num2 = NULL;
			}
			else
			{
			new_num1 = multiply_number(new_num1, new_num2);
			new_num2 = NULL;			
			}
		}
	printw("\n\nResult of Expression: \n");
	put_number(new_num1);
	}
	else
	{
	struct node *new_num1 = NULL, *new_num2 = NULL, *result;
	printw("\n\nEnter first number in Base 10000 format (dddd,dddd,...,dddd$) :\n");
	new_num1 = get_number(new_num1);
	printw("\n\nEnter second number in Base 10000 format (dddd,dddd,...,dddd$) :\n");
	new_num2 = get_number(new_num2);
		
		if(ch == 49)
		{
		result = add_number(new_num1, new_num2);
		printw("\n\nResult after addition: \n");
		put_number(result);
		}
		
		else
		{
		result = multiply_number(new_num1, new_num2);
		printw("\n\nResult after multiplication: \n");
		put_number(result);
		}
	}
}

getch();
goto again1;

endwin();
return 0;
}
