
#include<stdio.h>
#include"LinuxConio.h"

// to find the third largest number in an unsorted array in O(n) time complexity
// This can be done using hash table

int arrayList[18] = {8,4,1,10,9,6,7,3,2,56,23,78,54,21,89,76,47,0};

int main() {
const int size=18;

int hashTable[4],counter;
for (int i=0;i<4; i++)
hashTable[i]=0;

counter = arrayList[0];
int hashCount=0;
x:for (int i=1;i<size;i++) {
   if ( counter > arrayList[i])
   continue;

   else {
     hashTable[hashCount] = arrayList[i];
     counter = arrayList[i];
   }
//printf("\n loop largest number %d",hashTable[hashCount]);
 }
   hashCount++;

for ( int i=0;i<size;i++)
 if ( arrayList[i] == counter )
  arrayList[i]=0;

if (hashCount==3 )
 printf("\n the third largest number is :: %d\n",hashTable[hashCount-1]);

else {
 counter = arrayList[0];   
 goto x;
}

return 0;
}
