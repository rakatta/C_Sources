
#include<stdio.h>
#include<stdlib.h>
#include<LinuxConio.h>
#include<malloc.h>

void Insert();
void Delete();
void Search();
struct  Node 
{
  int data;
  struct Node *next;
};

struct Node *head =NULL;
int main (void)
{
  
  int choice;
  
  while(1)
  {
   printf("\nenter corresponding values for operation \n 1.Insert \n 2.Delete \n 3.Search\n ");
   printf("\n enter your choice:: ");
   scanf("%d",&choice);
    switch(choice)
   {
    case 1: Insert();  
    break;
    case 2: Delete();
    break;
    case 3 : Search();
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
 
 void Search()
 {
   struct Node *temp1;
   int count=0;
   temp1=head;
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
     temp1=temp1->next;
     count++;   
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
     }
     else
     if (temp1->data == del)
     {
       temp2->next = temp1->next;
       free(temp1);
     }
     else
     {
     temp2=temp1;
     temp1=temp1->next;
     count++;  
     } 
    }
   }
}



