

 /* This program displays the file contents to the console window
     SImilar to cat command in unix */


#include<stdio.h>
#include"LinuxConio.h"
#include<string.h>
#include<stdlib.h>

int main (int argc, char *argv[])

{
  clrscr();
  char ch;
  if (argc>=2)
  {
   FILE* file1 = fopen(argv[1], "r");
   if ( file1 == NULL )
   printf("File is not present\n");
   else{
    
    if (file1 != NULL )
    {
     while ( (ch=fgetc(file1) ) != EOF  )
     {
      printf("%c",ch);
     }
    }
    
   fclose(file1); 
  }
  return 0;
 }
  else
   puts("Enter any file at the commandline");
   
  // take an input at command for the file path and serve the file to the pointer to read contents.
  char s[150];
  gets(s); 
  FILE* file2 = fopen(s, "r");
  if ( file2 == NULL )
  printf("File is not present\n");
  else{
   
   if (file2 != NULL )
   {
    while ( (ch=fgetc(file2) ) != EOF  )
    {
     printf("%c",ch);
    }
   }
   
   fclose(file2); 
  }
  return 0;
 }
   
  
  
  
