#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    int i = 0;
    int h = 0;
    int k = 0;
    while (argv[i]!=NULL)
    {
        if (strcmp(argv[i],"-h") == 0)
        {
            h=1;
        }

       else if (strcmp(argv[i],"-k") == 0)
        {
            k=1;
        }
      i++;
    }
    
    if (k == 1)
    {
        
        int hmu = rmdir(argv[i-1]);
        if(hmu == -1)
        {    
            printf("ERROR\n");
            return 0;
        }          
    }
  else{
    int x = remove(argv[i-1]);
    if(x != 0)
    {
      printf("Error\n");
      return 0;
    }
    }
  if(h ==1)
  {
    printf("%s\n",argv[i-1]);
  }
    return 0;
}
