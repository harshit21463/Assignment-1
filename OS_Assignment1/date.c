#include <stdio.h>
#include <time.h>
#include <string.h>

int main(int argc, char const *argv[])
{   
    int i = 0;
    int r = 0;
    int u = 0;
    time_t ghadi;
    char bfr[30];
    struct tm* samay_ki_jaankari;
    ghadi = time(NULL);
    samay_ki_jaankari = localtime(&ghadi);
    struct tm* gmt;
    gmt = gmtime(&ghadi);
  
    while (argv[i]!=NULL)
    {
        if (strcmp(argv[i],"-u") == 0)
    {
        u =1;
    }
        else if (strcmp(argv[i], "-r") == 0)
        {
            r =1;
        } 
    i++;
    }
    if (r==1)
    {
      if(samay_ki_jaankari == NULL)
      {
        perror("Error: ");
      }
      else{
        strftime(bfr, 30, "%F %r\n", samay_ki_jaankari);
        printf("%s",bfr);
        }
    }
    
    else if (u ==1)
    {
        if(gmt == NULL)
        {
          perror("Error: ");
        }
      else{
        strftime(bfr, 30, "%F %r\n",gmt);
         printf("%s",bfr);
        }
    }

    
    else if(strlen(argv[0]) == 0)
    {
      time_t t;
      time (&t);
      
      printf("%s\n",ctime(&t));
      
    }

    else{
          printf("Error\n");
        }
  
    return 0;
}