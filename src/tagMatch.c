/*Project developed by Esha & Manjiri in July 2009*/
/* TAG ANALYSIS*/
#define MAX 8
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int push(char stack[], int *top, char value)
{
   if(*top < MAX)
   {
      *top = *top +1;
      stack[*top]=value;
      return 1;
   }
   else
   {
      printf("The stack is full.\n");
      return 0;
   }
}
int pop(char stack[], int *top, char *value)
{
   if(*top >=0)
   {
       *value = stack[*top];
       *top = *top -1;
       return 1;
   }
   else
   {
        printf("The stack is empty.\n");
              return 0;
   }
}
int strupr(char string[])
{
   int i = 0;
   while (string[i] != '\0')
   {
       if(string[i] >= 'a' && string[i] <= 'z')
          string[i] -= 32;
       ++i;
   }
}
int main()
{  
    system("clear");
    printf("\nTAG ANALYSIS project developed at K.I.T.E. by Esha & Manjiri in July 2009.\n");
    printf("\nEsha Paradkar is a student of YCCE in 3rd Semester, ETC.\n");
    printf("\nManjiri Tapaswi is a student of NYSS in 3rd Semester, CSE.\n");
    FILE *file1;
    char c, tmp, stack[MAX], word[400], first_letter, tag[40], dummy, filename[20];
    int stack_top = -1, open_tag = 0, close_tag = 0, error_ctr = 0, is_correct = 1;
    printf("\nEnter filename of desired file\n");
    gets(filename);
    file1 = fopen(filename,"r");
    if(file1 == NULL)
    { 
      printf("Could not open %s for reading.\n", filename);
      return(1);
    }
    
    fscanf(file1, "%c", &first_letter);
    if(first_letter == '<')
    {
       fscanf(file1, "%[^>]", tag);
       strupr(tag);
    } 
    else
    {
       fscanf(file1, "%[^<]%c", word, &dummy);
       fscanf(file1, "%[^>]", tag);
       strupr(tag);
    }
    while(!feof(file1))
    {
      if( (!strcmp(tag, "HTML")) )
      {
      
         c='H';
         is_correct = push(stack, &stack_top, c);
         ++open_tag;
         if(!is_correct)
         ++error_ctr;
      }
      if( (!strcmp(tag, "HEAD")) )
      {  
         c='D';
         is_correct = push(stack, &stack_top, c);
         ++open_tag;
         if(!is_correct)
         ++error_ctr;
      }
      if( (!strcmp(tag, "TITLE")) )   
      {
         c='T';
        
         is_correct = push(stack, &stack_top, c);
         ++open_tag;
         if(!is_correct)
         ++error_ctr;
      }
      if( (!strcmp(tag, "BODY")) )
      {
         c='B';
         
         is_correct = push(stack, &stack_top, c);
         ++open_tag;
         if(!is_correct)
         ++error_ctr;
      }
      if( (!strcmp(tag, "/BODY")) )
      {  
         is_correct = pop(stack, &stack_top, &tmp);
         ++close_tag;
         if(!is_correct)
         ++error_ctr;
      }
      if( (!strcmp(tag, "/TITLE")) )
      { 
         is_correct = pop(stack, &stack_top, &tmp);
         ++close_tag;
         if(!is_correct)
         ++error_ctr;
      }
                                                                                                    
      if( (!strcmp(tag, "/HEAD")) )
      {
         is_correct = pop(stack, &stack_top, &tmp);
         ++close_tag;
         if(!is_correct)
         ++error_ctr;
      }
                                                                                                    
      if( (!strcmp(tag, "/HTML")) )
      {
         is_correct = pop(stack, &stack_top, &tmp);
         ++close_tag;
         if(!is_correct)
         ++error_ctr;
      }
      fscanf(file1, "%[^<]%c", word, &dummy);
      fscanf(file1, "%[^>]", tag);
      strupr(tag);
   }
    if(open_tag != close_tag)
      ++error_ctr;
    if(error_ctr)
     printf("\nError found! The tags in the entered file are not proper.\n");
    else
     printf("\nCongratulations! The tags in the entered file are proper.\n");
    return 0;
}
