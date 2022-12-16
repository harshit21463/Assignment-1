#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

    int main(int argc, char const *argv[])
    {  
        int i = 0;
        int v = 0;
        int n = 0;
        int h ;
        while (argv[i]!=NULL) 
        {  
            if (strcmp(argv[i],"-v") == 0)
        {
            v = 1;
        }
        else if (strcmp(argv[i],"-n") == 0)
        {
            n = 1;
        }
        
            i++;
        }
            h = 0777;
        if (n==1)
        {
            scanf("%d",&h);                       
        }   
        if (mkdir(argv[i-1],h)==-1)
        {
            perror("Error");
            return -1;
        }
        else if (v == 1)
        {
            printf("%s \n",argv[i-1]);
        }  
      else{
        mkdir(argv[i-1],h);
      }
        return 0;
    }
