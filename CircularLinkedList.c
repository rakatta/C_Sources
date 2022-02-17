#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

int Insert();
int Delete();
void Display();

struct Node {
 int data;
 struct Node *next;
};
struct Node *head = NULL;
struct Node *temp = NULL;
struct Node *lastNode;
int count=0;
int main(void) {

int choice;
int totalCount=0;
while(1) {

printf("\n 1.Insert \n 2.Delete \n 3.Display \n");
printf("Enter a choice");
scanf("%d",&choice);

switch(choice) {
case 1 : totalCount = Insert();
break;
case 2:  totalCount = Delete();
break;
case 3: Display();
break;
default : printf("Enter correct choice");
exit(0);
break;

}

}

return 0;
}

int Insert() {

  int x;
  printf("Enter any value to insert :: ");
  scanf("%d",&x);
  struct Node *temp1;
    struct Node *curr ;

  temp1 = (struct Node* )malloc(sizeof(struct Node));
  temp1->data =x;
  temp1->next = NULL;
  temp =temp1;

  if (head == NULL ) {
  head=temp1;
  temp=head;
  count +=1;
  }
 
  else {
    
    curr = head;
     while(curr->next != NULL ) {
      curr = curr->next;
      if (curr->next == head ) {
      temp1->next=head;
      curr->next=temp1;
      count+=1;
      break;
     } 
    }
    if (curr->next == NULL ) 
    count+=1;
    
    curr->next =temp1;    
    temp1->next=head;
    
  }
        lastNode=temp;
  printf("count from insert function %d",count);
  return count;
}

void Display() {

 struct Node *local;
 local = head;
 if (head == NULL )
 printf("List is empty");
 else 
   if ( local->next == NULL ) {
   printf(" only one element in the list ");
   printf("%d",local->data);
   }
   
  else {
   while ( local->next != NULL ) {
      printf("%d\t",local->data);
      local = local->next;
      if (local->next == head ) {
      //count+=1;
      break; 
     }
   }
   printf("%d\t",local->data);
   printf(" \n number of elements in a circular list :: %d", count);
  }
}

int Delete() {
   int del;
   struct Node *curr;
   struct Node *temp1;
    temp1 = head;
    printf("\n ENter the node to delete : ");
    scanf("%d",&del);
    if ( head == NULL ) {
      printf("\n  NO element present in the linked list");
      return count;
   }
   else
     if ((temp1->next == NULL ) && (temp1==head)) {
     printf("\n only one element exists in the list and deleted");
     free(temp1);
     head = NULL;
     count -=1;
   }
 
  else
      if ( temp1->next!= NULL) {
       while (temp1->next!=head) {

       if ((temp1==head) && (temp1->data==del))
       {
         head=temp1->next;
         lastNode->next = head;
         free(temp1);
         puts("\nfirst Node delete");
         count-=1;
         break;
       }

     else if (temp1->data == del) {
      curr->next = temp1->next;
      count-=1;
      free(temp1);
      break;
    }
   else {
     curr = temp1;
     temp1=temp1->next;
       if ( (temp1->next  == head) && (temp1->data != del) ) 
       puts("\n No item found");
    }   
  }
      
   if ( (temp1->next  == head) && (temp1->data == del) ) {
     if ( (temp1->next == head ) && (temp1 == head) && (temp == head) && ( temp1->data == del ) ) {
     free(temp1);
     count-=1;
     head = NULL;
    }
   else{
    
    curr->next = head;
    lastNode=curr;
    temp=curr;
    count-=1;
    free(temp1);
   }
   printf(" last node in the cicular list to be deleted ");
  }
    
 } 
  return count;
}  
