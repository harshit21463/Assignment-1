#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{   
    int i = 0;
    int n = 0;
    int f = 0;
    char ch;
    char h;
    while (argv[i]!=NULL)
    {
        if (strcmp(argv[i],"-n")==0)
        {
            n = 1;
        }
         if (strcmp(argv[i],"-f")==0)
        {
            f = 1;
        }   
      i++;
    }
  FILE*file_pointer;
  file_pointer = fopen(argv[i-1],"r");
  if(file_pointer == NULL)
    {
      printf("ERROR");
    }
  int lines = 1;
   if (n==1){
          char k;
          int j =1;
          printf("%d ",j);
          do{
            k = fgetc(file_pointer);
            if(k=='\n')
            {
              j++;
              printf("\n%d ",j);
              
            }
            else {
              printf("%c",k);
            }
          }while(k!=EOF);
     }
  
    
    else if (f == 1 )
        {
            h = fgetc(file_pointer);
          while(h!=EOF){
            h = fgetc(file_pointer);
            if(h == '\n')
            {
              lines ++;
            }
          }
            printf("No. of lines : %d\n",lines - 1);    
        }
    
    else{
      ch = fgetc(file_pointer);
    while (ch != EOF)
    {
        if (ch == '\n')
        {
            lines++;
        }
        printf("%c",ch);
      ch = fgetc(file_pointer);
    } 
     
    }
    return 0;
}
