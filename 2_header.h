struct node
{
  unsigned int data;
  struct node *next;
};

struct node* get_number(struct node* num);
void put_number(struct node* num);
struct node* add_number(struct node* new_num1, struct node* new_num2);
struct node* multiply_number(struct node* new_num1, struct node* new_num2);
