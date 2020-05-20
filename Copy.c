/* This program copies the file contents to another file
     Similar to cp command in unix */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main (int argc, char *argv[])

{
  int count = argc;
   
 if (argc==1)
  {
    puts("Enter source file path at the commandline");
 
 // take an input at command for the file path and serve the file to the pointer to copy contents.
  char s[150],d[150],ch;
  gets(s); 
   puts("Enter destination file path");
   gets(d);
  FILE* file1 = fopen(s, "r");
  FILE* file2 = fopen(d, "w");
  
   if (file1 != NULL )
   {
    while ( (ch=fgetc(file1) ) != EOF  )
    {
     fputc(ch,file2);;
    }
   }
   fclose(file1);
   fclose(file2);
   puts("\n"); 
  }
 
  // TO copy a single file from source to destination path.
 else
  if (argc==3)
  {
   FILE* file3 = fopen(argv[1], "r");
   FILE* file4 = fopen(argv[2], "w");
   
   char ch;
   if (file3 != NULL )
   {
    while ( (ch=fgetc(file3) ) != EOF  )
    {
     fputc(ch,file4);
    }
   }
   fclose(file3);
   fclose(file4); 
   
  }
 //To copy multiple files at a single command
 else
 {
   FILE* file_S; 
   FILE* file_D;
   
   char ch,ptr[100];
   for (int i=0;i<count-2;i++)
   {
    strcpy(ptr,argv[count-1]);
    file_S = fopen(argv[i+1], "r");
    file_D = fopen(strcat(ptr,argv[i+1]), "w");
   if (file_S != NULL )
   {
    while ( (ch=fgetc(file_S) ) != EOF  )
    {
     fputc(ch,file_D);
    }
   }
    fclose(file_D);
    fclose(file_S); 
   }
   
 } 
  return 0;
}
