#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Hash table open addressing logic 
int main(void) {
const int countSize = 10;
int arr[10] = { 3,5,1,2,8,9,7,4,8};
int counter =0;
for ( int i=0;i<countSize;i++)
printf("%d\t",arr[i]);
printf("\n");
static int hashTable[10] ;
int key = 0;

for ( int i=0;i<countSize;i++) {
  key = arr[i]%10;
 d: if ( hashTable[key] == 0) {
  hashTable[key] =arr[i];
  printf("%d\t",hashTable[key]);
  }
  
  else
  if ((hashTable[key] == arr[i]) || (hashTable[key]!=0) ) {
  counter+=1;
  if (counter ==1 )
  printf("\nThe first value repeated is :: %d\n", arr[i]);
  //break;
 
  if ( key == countSize-1 && hashTable[key]!=0) {
  key =0;
  goto d;
  }
   key =key+1; 
   goto d;
 }
  else
  continue;
}

printf("\n");
for ( int i=0;i<countSize;i++)
printf("%d\t %d\n", i,hashTable[i]);
printf("\n");
return 0;
}
