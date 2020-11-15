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
void MaxMin();
struct  Node 
{
  int data;
  struct Node *next;
};

struct Node *head =NULL;
struct Node *rev;
int flag=0;
int main (void)
{
  
  int choice;
  
  while(1)
  {
   printf("\nenter corresponding values for operation \n 1.Insert \n 2.Delete \n 3.Display\n 4.Reverse_Recursion\n 5.ReverseIteration\n ");
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
    case 4 : 
     ReverseDisplay();
    break;
    case 5 : ReverseIteration();
    break;
    default: 
    {
    printf("Enter correct choice\n ");
    exit(0);
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
   if(head==NULL)
   head=temp;
   else
   {
    temp1=head;
    while(temp1->next!=NULL)
    {
     temp1=temp1->next;
    }
   temp1->next=temp;
   }
 }
 
 void Display()
 {
   struct Node *temp1;
   temp1=head;
   int max=temp1->data;
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
     if (max<temp1->data)
     max = temp1->data; 
     temp1=temp1->next;
      
    }
    temp1=head;
    int min= temp1->data;
     while(temp1!=NULL)
    {
      if (min>temp1->data)
     min = temp1->data; 
     temp1=temp1->next;
      
    }
    
     printf("\n Enter 1 or 0 to find max or min value in a list:::: ");
     scanf("%d",&flag);
     switch(flag)
     {
      case 1:MaxMin(max,flag);
      break;
      case 0: MaxMin(min,flag);
      break;
      default : printf("\nEnter correct choice");
      break;
      }
   }
 } 

void Delete()
{
   struct Node *temp1;
   struct Node *temp2;
   int count=0;
   int del;
   temp1=head;
   printf("\nenter the value to be deleted\n");
   scanf("%d",&del);
   if(head==NULL)
   printf("No element is entered");
   else
   if (temp1==head && temp1->next ==NULL)
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
       free(temp1);
       break;
     }
     else
     if (temp1->data == del)
     {
       temp2->next = temp1->next;
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
void ReverseDisplay(){
rev = head;

if(head==NULL)
   printf("No element is entered");
   else{
   puts("reverse elements in the linked list in recursion\n");
   RD(rev);
   }
 } 
void RD(struct Node* r){
if (r== NULL){
return ;
}

else {

  RD(r->next);   // Recursive implementation
  printf("%d\t",r->data);
  }
}


void ReverseIteration() {
  struct Node* curr;
  struct Node* prev;
  struct Node* temp;
  struct Node* ri;
  temp=head;
  curr=head;
  prev=NULL;
   while(curr!= NULL) {
    temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
   }
   head =prev;
   ri=head;
	if(head==NULL)
	   printf("No element is entered");
	else{
	   puts("the reversal of linked list in iterative manner");
	while(ri!=NULL){
	printf("%d\t",ri->data);
	ri=ri->next;
      }
   }
}

void MaxMin(int value, int swap) {
  if ( swap == 1)
  printf("\nmaximum value %d",value); 
  else
  printf("\nminimum value %d",value); 
  
}
