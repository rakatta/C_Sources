#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>

void Insert();

void Display();
void delete();

static int counter=0;
int value = -1;
struct Node        // tree skeleton 
{
  int data;
  struct Node *left;
  struct Node *right;
};
struct Node *head = NULL;
struct Node *rev;
void BST(struct Node*);
int Height(struct Node*);
int main (void) {
int choice;
rev=head;
int height=0;
 while(1) {
   printf("\n 1.Insert \n 2.Delete \n 3.Display ( Depth First search ) \n 4.To check Binary Tree is BST \n 5.Height of a tree \n 6.Total elements\n");
   printf("Enter a choice");
   scanf("%d",&choice);
   switch(choice) {
   case 1 :  Insert();
   break;
   case 2: delete();
   break;
   case 3: Display();
   break;
   case 4 : BST(rev);
   break;
   case 5 : height = Height(rev);
   printf("\n The height of the tree is: %d\n" , height);
   break;
   case 6 : printf("\nThe total elements in a Binary tree : %d\n", counter);
   break;
   default : printf("Enter correct choice");
   exit(0);
   break;
  }
 }
 return 0;
} 
void Delete(struct Node* ,int a);

void delete() {
 printf("\nEnter the item to Delete :");
   int y;
   
   struct Node *curr;
   scanf("%d",&y);
   rev=head;
   Delete(rev,y);
   if ( value == -1 )
   printf(" item not found");
}
  
  

  
void Insert() {   //inserting the values in a BST
   int x;
   struct Node *curr;
   struct Node *temp1;
   struct Node *prev;
   printf("Enter the element to enter");
   scanf("%d",&x);
   temp1 = (struct Node *) malloc(sizeof(struct Node));
   temp1->data =x;
   temp1->left =NULL;
   temp1->right = NULL;
    if (head == NULL )
    head=temp1;
    else {
       if ((x > head->data) && (head->right==NULL))
      head->right=temp1;
      else
      if ((x < head->data) && (head->left==NULL))
      head->left=temp1;
     
    else 
    {
      curr =head;
      while ( (curr!=NULL)) { 
      if ( (x > curr->data) ) {
       
        if (curr->right==NULL)
        prev=curr;
        else
        prev=curr;
        curr=curr->right;
        
       }
      else
      if ( (x < curr->data) ) {
        if (curr->left==NULL)
        prev=curr;
        else
        prev=curr;
       curr=curr->left;
       
       }
        
      }
     
      if ( (x > prev->data) && (prev->right==NULL))
      prev->right= temp1; 
      else
      if ( (x < prev->data) && (prev->left==NULL))
      prev->left = temp1;
      
     } 
     
   }
   counter+=1;  //to incement the static counter to count the total no of elements after insertion
}
void InOrder(struct Node*);
void PreOrder(struct Node*);
void PostOrder(struct Node*);

void Display() {
	int choice;
	rev=head;
	printf(" 1. Inorder\n 2. Pre Order\n 3. PostOrder \n");
	printf("Enter choice");
	scanf("%d",&choice);
	switch(choice) {
	 case 1: printf("\nInorder Traversal\n");
	 InOrder(rev);
	 break;
	 case 2: printf("\nPreOrder Traversal\n");
	 PreOrder(rev);
	 break;
	 case 3 : printf("\nPostorder Traversal\n");
	 PostOrder(rev);
	 break;
	 default: printf("\nEnter correct choice : ");
	 break;
	}


}
//INorder Traversal

void InOrder(struct Node* r) {
   //printf("inorder function");
  if (r == NULL )
  return ;
  else {
  InOrder(r->left);     // recursion implementation of inroder traversal
  printf("%d\t" , r->data);
  InOrder(r->right);
  
  }
}  

  void PreOrder(struct Node *r) {
   // printf("preorder function");
  if (r == NULL )
  return ;
  else {
  printf("%d\t" , r->data);
  PreOrder(r->left); // recursion implementation of preorder traversal
  PreOrder(r->right);
  
  }
}
  
void PostOrder(struct Node *r) {
    //printf("postorder function");
  if (r == NULL )
  return ;
  else {
  PostOrder(r->left); // recursion implementation of postorder traversal
  PostOrder(r->right);
  printf("%d\t" , r->data);
  
  }
}

struct Node *prev,*curr;
 struct Node* FindMin( struct Node*);
  struct Node* FindMax( struct Node*);
struct Node* FindMin( struct Node *min) {    // to find the minimum value in right sub tree with recursion

if ( min->left == NULL )
return min;
else {
 curr=min;
return FindMin(min->left);
 }
} 
 struct Node* FindMax( struct Node *min) {   // to find maximum value in left sub tree with recursion

if ( min->right == NULL )
return min;
else {
 curr=min;
return FindMax(min->right);
 }
}

void BST(struct Node* temp) {
   struct Node* curr = temp;
   struct Node *findMin = FindMin(curr->right);
   curr = temp;
   struct Node *findMax = FindMax(curr->left);
   
   if (  ( temp->data<findMin->data) && ( temp->data>findMax->data))
   printf("Binary tree is Binary search tree");
   
   // to check if tree is complete BST
   
  }
int max( int , int );
int Height(struct Node* temp) {
  if ( temp == NULL )
 return -1;
 else
 return max(Height(temp->left),Height(temp->right)) +1; 
}

int max(int a,int b) {

 if ( a > b)
 return a;
 else if ( a<b)
 return b;
 else
 return a;
}

  void Delete(struct Node *r,int x) {
     struct Node* temp;
     if ( r == NULL ) 
      return ;
     
     if ( x>r->data)   // tree traversal for deletion value greater than root node with recursion
     {
      prev=r;
      Delete(r->right,x);
      
      }
     else if( x<r->data)  // tree traversal for deletion value less than root node with recursion
     {
      prev =r;
      Delete(r->left,x);
            
      }
     else    // value found
     {
      
      if ( (r->left ==NULL ) && (r->right==NULL) )  // test case 1 :to delete leaf node
      {
       temp=r;
       if (x<prev->data)
       prev->left=NULL;
       else
       prev->right=NULL;
       free(temp);
      }
      else if( (r->left == NULL)  )   // test case 2: to delete value which doesnt have left subtree
      {
       temp = r;
       if ( x == head->data )   // if only two elements contain in tree and deletion node happens to be head node
       {
         r=r->right;
         head = r;
         free(temp);
       }
        else                 // if two or more elements in a right sub tree and deletion node apart from head node
        {
         r=r->right;
         if ( prev->data<r->data)
         prev->right=r;
         else 
         prev->left=r;
         free(temp);
        } 
       }
        else  if ( (r->right == NULL)  )   // test case 3: to delete value which doesnt have right subtree
        {
         temp = r;
         if ( x == head->data )    // if only two elements contain in tree and deletion node happens to be head node
         {
          r=r->left;
          head = r;
          free(temp);
         }
         else                            // if two or more elements in a left sub tree and deletion node apart from head node
         {
          r=r->left;
          if ( prev->data>r->data)
          prev->left=r;
          else 
          prev->right=r;
          free(temp);
         }
        }
      
      else         //  test case 4 : to delete a value which has both left and right sub trees
      {
       temp =r;
        printf("\n the element has both childs\n 1. replace  min value from right subtree or \n2. replace max value from left subtree : ");
        int choice;
        scanf("%d",&choice);
        struct Node* result;
        switch(choice)
        {
          case 1 : 
          result  = FindMin(r->right);    // to find minimum value in right sub tree with recursion
        printf("min value from right sub tree %d",result->data);
       
        if (result->right ==NULL && result->left ==NULL ) 
        {
         if ( x == head->data )    // if root node to be deleted with left sub tree being single child
         {
          temp->data = result->data;
          temp->right = NULL;
         }
         else
         {
          temp->data = result->data;
          curr->left=NULL;
         }
        }
        else
        {
         if ( temp->right == result )
          {
            temp->data = result->data;
            temp->right=result->right;
          }
          else {
          temp->data = result->data;
          curr->left =result->right;
         }
        }
        free(result);
        break;
        
        case 2 :
        result  = FindMax(r->left);    // to find the maximum value in left subtree with recursion
        printf("max value from left sub tree %d",result->data);
        
        if (result->right ==NULL && result->left ==NULL ) 
        {
         if ( x == head->data )   // if root node to be deleted with right sub tree being single child
         {
          temp->data = result->data;
          temp->left = NULL;
         }
         else
         {
          temp->data = result->data;
          curr->right=NULL;
         }
        }
        else
        {
          if ( temp->left == result )
          {
            temp->data = result->data;
            temp->left=result->left;
          }
          else {
         temp->data = result->data;
         curr->right =result->left;
         }
        }
        free(result);
        break;
        
        default : printf("\n enter correct choice");
        break;
        }
      
      }
      value =0;   // to return global value to 0 when  data  found to delete else value remains -1
      counter-=1; // to decrement the static counter to count the total no of elements after deletion
    }
     
  }

  
