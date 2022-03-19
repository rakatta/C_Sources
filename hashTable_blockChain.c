#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

// Hash Table Block Chain Using Single Linked List
// This program takes the entered string and stores in a hash Table at a particular index on the hashCode Algorithm, if collison happens with another string at an index then it forms a singlelinked list and stores the values

const int SIZE=10;
int hashFunction(char *);

struct Node 
{
  char *st;
  struct Node *next;
};
struct Node *head=NULL;

void hashInsert(char * ,int);
void hashDelete(char * ,int);
void hashDisplay(int ,char *,int);

struct Node *hashT[10];

static void init()
{
  for ( int i=0;i<SIZE;i++)
   hashT[i] = (struct Node *) malloc( sizeof(struct Node)) ;
   
   for ( int i=0;i<SIZE;i++)
 hashT[i]->next = NULL;

}

int main(void) {

int choice;
init();
char *str;

int key,flag;
while (1){
printf("\nenter corresponding values for Hash table operation \n 1.Insert \n 2.Delete \n 3.Search\n 4.Display at Key index");
   printf("\n enter your choice:: ");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1: str = (char *)malloc ( 20 * sizeof (char ));
            printf(" \n Enter any String \n");
            scanf ("%s", str);
            key = hashFunction(str);
            hashInsert(str,key);
            
     break;
    case 2: str = (char *)malloc ( 20 * sizeof (char ));
            printf(" \n Enter any String \n");
            scanf ("%s", str);
            key = hashFunction(str);
            hashDelete(str,key);
    break;
    case 3 : printf(" \n Enter a string to search \n");
             str = (char *) malloc ( 20*sizeof(char ));     
             scanf("%s", str);
             key=hashFunction(str);
             flag=0;
             hashDisplay(key,str,flag);
             
    break;
    case 4 : flag=1;
             d : printf(" \n Enter a key to display hash Table values from 0 to 9 : \n");
             scanf("%d",&key);
             if ( (key >=0) && (key <=9) )
              hashDisplay(key, str,flag);
             else
             goto d;
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
// Hash Function Algorithm

int hashFunction( char *str ) {
int hashCode=0, i=0;
 while ( str[i]!='\0' )
 {
   hashCode = hashCode + (int)str[i];
   i++;
 }
 printf("HashCode %d\n",hashCode % SIZE);
 return hashCode % SIZE;
}

//Inserting strings into a key Index generated from hashCode
void hashInsert(char *s,int key) {

   struct Node *temp ;
   temp = (struct Node *) malloc(sizeof(struct Node ));
   struct Node *trav;
   temp->st = s;
   temp->next = NULL;
     
   if (head == NULL )
   head = temp;
   
   if ( hashT[key]->next == NULL )
   {
     hashT[key]->next = temp;
   }
   else
   {
   trav = hashT[key];
    while ( trav->next != NULL )
     {
      trav=trav->next;
            
     }
     trav->next = temp;
   }   
}

void hashDelete(char *str,int key)
{
  printf("---Delete---- \n");
  struct Node *trav=NULL;
  struct Node *prev= NULL;
   int position=0;
   int countList =0;
   
   if ( hashT[key]->next == NULL )
    printf("List is empty on hash[Key] %d\t ",key );
   else
   {
     trav = hashT[key];
     while( trav->next != NULL )
     {
       prev = trav;
       trav = trav->next;
       position+=1;
       if ( strcmp(trav->st ,str) ==0 )
       {
         countList+=1;
         prev->next=trav->next;
         printf(" Node deleted at  keyIndex value ::%d\t hash[Key] :: %p\t Position :: %d\t %s\n",key ,hashT[key],position,trav->st);
         free(trav);
         break;
       }
     }
     if ( countList == 0)
     printf("No string to delete \n");
   } 
}

void hashDisplay(int key, char *str,int flag)
{
  printf("---------Display-----------\n");
  struct Node *trav=NULL;
   int position=0;
   int countList =0;
   
    if ( hashT[key]->next == NULL )
   {
    printf("List is empty on hash[Key] %d\t ",key );
   }
   else
   {
   trav = hashT[key];
   if (flag == 1 )
   {
    while ( trav->next != NULL )
     {
      trav=trav->next;  
      position+=1;
      printf(" String found at keyIndex value ::%d\t hash[Key] :: %p\t Position :: %d\t %s\n",key ,hashT[key],position,trav->st);
     }
   }
   else
   {
    while ( trav->next != NULL )
     {
      trav=trav->next;  
      position+=1;
      if ( strcmp(trav->st ,str) ==0 )
       {
        countList+=1;
        printf(" String found at keyIndex value ::%d\t hash[Key] :: %p\t Position :: %d\t %s\n",key ,hashT[key],position,trav->st);
       }
     }
    if ( countList == 0 )
    printf("\n No String FOUND\n");   
   }
  }
}
