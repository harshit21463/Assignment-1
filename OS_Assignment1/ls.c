#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void lister(const char *ghar,int a,int l)
{
	struct dirent *gg;
	DIR *dhor = opendir(ghar);
  gg  = readdir(dhor);
	while (gg != NULL)
	{
    
		if (!a && gg->d_name[0] == '.')
            {
				gg = readdir(dhor);
			    continue;
            }
		printf("%s  ", gg->d_name);
		if(l) 
        {
            printf("\n");
        }
  gg = readdir(dhor);
    }
	if(!l){
	    printf("\n");
    }

  
}

int kuchbhi(int argc, const char *argv[])
{
  char*hru = malloc(1000*sizeof(char));
     getcwd(hru, 1000)
	if (argc == 1)
	{
		lister(hru,0,0);
	}
    
	else if (argc && argv[1]!= NULL)
	{
		if (argv[1][0] == '-')
		{
			int a = 0, l = 0;
      int i = 1;
			while(argv[i])
            {
				if(strcmp(argv[i],"-a") == 0) 
                {
                    a = 1;
                }
				else if(strcmp(argv[i],"-l") == 0) 
                {
                    l = 1;
                }
              i++;
			}
			lister(hru,a,l);
		}
	}
}

int main(int argc, const char *argv[])
{
  
	kuchbhi(argc,argv);
	return 0;
}
