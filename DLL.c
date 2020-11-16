
#include<stdio.h>
#include<stdlib.h>
#include"LinuxConio.h"
#include<malloc.h>
#include<string.h>
void Insert();
void Delete();
void Display();
void ReverseDisplay();
void ReverseIteration();
void MaxMin(int,int);
struct  Node 
{
  int data;
  struct Node *next;
  struct Node *prev;
};

struct Node *head =NULL;
struct Node *rev;
int main (void)
{
  
  int choice;
  
  while(1)
  {
   printf("\nenter corresponding values for operation \n 1.Insert \n 2.Delete \n 3.Search\n 4.ReverseDisplay\n ");
   printf("\n enter your choice:: ");
   scanf("%d",&choice);
    switch(choice)
   {
    case 1: Insert();  
    break;
    case 2: Delete();
    break;
    case 3 : Display();
    break;
    case 4: ReverseDisplay();
    break;
    default: 
    {
    printf("Enter correct choice\n ");
     break;
    }
    }
   } 
  return 0;
 }
 
 void Insert()
 {
   int x;
   printf("enter any element");
   scanf("%d",&x);
   struct Node *temp1;
   struct Node *temp;
   temp = (struct Node *) malloc(sizeof(struct Node));
   temp->data  =x;
   temp->next=NULL;
   temp->prev=NULL;
   if(head==NULL)
   head=temp;
   else
   {
    temp1=head;
    while(temp1->next!=NULL)
    {
     temp1=temp1->next;
    }
   temp->prev =temp1;
   temp1->next=temp;
   
   }
 }
 
 void Display()
 {
   struct Node *temp1;
   int max=0,min=0;
   temp1=head;
   max=temp1->data;
   if(head==NULL)
   printf("No element is entered");
   else
   if (temp1->next==NULL)
   printf("Only one element %d\n",temp1->data);
   else
   {
     printf("\nLinkedlist values\n");
    while(temp1!=NULL)
    {
     printf("%d\t",temp1->data);
     
     if ( max<temp1->data)
     max=temp1->data; 
     temp1=temp1->next; 
    }
    temp1=head;
    min=temp1->data;
    while(temp1!=NULL)
    {
     
     if ( min>temp1->data)
     min=temp1->data;  
     temp1=temp1->next;
    }
    
    int flag;
    puts("\nenter  1 for maximum and 0 for minimum value in the lisked list");
    scanf("%d", &flag);
    switch(flag){
    
    case 1: MaxMin(max,flag);
    break;
    case 0: MaxMin(min,flag);
    break;
    default:
    {
      printf("\nEnter the correct choice to find the value");
    }
    
    }
   
   }
 } 

void Delete()
{
   struct Node *temp1;
   struct Node *temp2;
   struct Node *temp3;
   int count=0;
   int del;
   temp1=head;
   printf("\nenter the value to be deleted\n");
   scanf("%d",&del);
   if(head==NULL)
   printf("No element is entered");
   else
   if ((temp1->data ==del) && temp1->next ==NULL)
   {
   printf("Only one element deleted %d\n",temp1->data);
   free(temp1);
   head =NULL;
   } 
   else
   {
    while(temp1!=NULL)
    {
     
     if ((temp1==head) && (temp1->data==del))
     {
       head=temp1->next;
       head->prev=NULL;
       free(temp1);
       break;
     }
     else
     if (temp1->data == del)
     {
       temp3=temp1;
       temp3->prev=temp2;
       temp2->next = temp3->next;
       temp1->prev =NULL;
       free(temp1);
       break;
     }
     else
     {
      temp2=temp1;
      temp1=temp1->next;
      count++; 
     } 
    }
     if (temp1 == NULL ){
      puts("item not found"); 
      }
   }
     
}

void RD(struct Node*);
void ReverseDisplay() {

rev =head;
if (head == NULL)
printf(" No element is in the linked list");

else {
puts("reverse elements in the linked list in recursion\n");
   RD(rev);
}
}
void RD(struct Node* r) {

if (r == NULL){
return ;
}
else {
  RD(r->next);
  printf("%d\t" , r->data);
}
}

void MaxMin(int value,int swap){

if (swap ==1 )
printf("Maximum value :: %d " , value);
else
printf(" Minimum value :: %d" , value);
}





