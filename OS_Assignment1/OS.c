#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>


char *global;
void *hello (void*arg)
{
  char *hax = (char*)arg;
  int j = system(hax);

  
  return NULL;
}
void thread (char*args)
{
  char*jai = malloc(sizeof(char)*2000);
  strcpy(jai,global);
  strcat(jai,"/");
  strcat(jai,args);
  pthread_t nayadhaaga;
  pthread_create(&nayadhaaga,NULL,hello,jai);
  pthread_join(nayadhaaga,NULL);
}

int fork_callermkdir(char **inp_parts)
{
    pid_t pid, wpid;
    int stat;
    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr,"Fork Failed");
        return 1;
    }
    else if (pid == 0)
    {
      char *halo = malloc(sizeof(char)*1000);
      strcpy(halo,global);
      strcat(halo,"/mkdir");
      execl(halo,inp_parts[1],inp_parts[2],NULL);
    }
    else
    {
        wpid = wait(NULL);
        return 0;
    }
    return 0; 
}
int fork_callerdate(char **inp_parts)
{
    pid_t pid, wpid;
    int stat;
    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr,"Fork Failed");
        return 1;
    }
    else if (pid == 0)
    {
      char *halo = malloc(sizeof(char)*1000);
      strcpy(halo,global);
      strcat(halo,"/date");
        execl(halo,inp_parts[1],NULL);
    }
    else
    {
        wpid = wait(NULL);
        return 0;
    }
    return 0; 
}
int fork_callerrm(char **inp_parts)
{
    pid_t pid, wpid;
    int stat;
    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr,"Fork Failed");
        return 1;
    }
    else if (pid == 0)
    {
      char *halo = malloc(sizeof(char)*1000);
      strcpy(halo,global);
      strcat(halo,"/rm");
        execl(halo,inp_parts[1], inp_parts[2],inp_parts[3],NULL);
    }
    else
    {
        wpid = wait(NULL);
        return 0;
    }
    return 0; 
}
int fork_callercat(char **inp_parts)
{
    pid_t pid, wpid;
    int stat;
    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr,"Fork Failed");
        return 1;
    }
    else if (pid == 0)
    {
      char *halo = malloc(sizeof(char)*1000);
      strcpy(halo,global);
      strcat(halo,"/cat");
        execl(halo,inp_parts[1], inp_parts[2], inp_parts[3],NULL);
    }
    else
    {
        wpid = wait(NULL);
        return 0;
    }
    return 0; 
}
int fork_callerls(char **inp_parts)
{
    pid_t pid, wpid;
    int stat;
    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr,"Fork Failed");
        return 1;
    }
    else if (pid == 0)
    {
      char *halo = malloc(sizeof(char)*1000);
      strcpy(halo,global);
      strcat(halo,"/ls");
        execl(halo,halo,inp_parts[1],NULL);
    }
    else
    {
        wpid = wait(NULL);
        return 0;
    }
    return 0; 
}
char *read_input(){
    int inpsize = 1000;
    int rank = 0;
    char *inp_mem = malloc(sizeof(char)*1000);
    int ascii;
    while(1)
    {
        ascii = getchar();
        if (ascii != '\n')
        {
            inp_mem[rank] = ascii;
        }
        else{
            inp_mem[rank] = '\0';
            return inp_mem;
        }
        rank +=1;
    }
}
char **parting_inp(char *input){
    int bufsize = 16;
    int rank = 0;
    char **inp_array = malloc(16*sizeof(char*));
    char *inp_array_elem;
    inp_array_elem = strtok(input, " ");
    do
    {
        inp_array[rank] = inp_array_elem;
        rank++;
        inp_array_elem = strtok(NULL, " ");
    }    
    while (inp_array_elem != NULL);
    inp_array[rank ] = NULL;
    return inp_array;
  }
void echo(char **inp_parts){
  
  if (strcmp(inp_parts[1],"-n")==0)
  {
    int i = 2;
    while (inp_parts[i]!=NULL)
    {    
        printf("%s ",inp_parts[i]); 
        i++;  
    }     
  }
  else if (strcmp(inp_parts[1],"-b")==0)
  {
    int i =2;
    while (inp_parts[i]!=NULL)
    {
        printf("%s\n",inp_parts[i]); 
        i++;  
    }   
}
  
  else{
  int i = 1;    
  while (inp_parts[i]!=NULL)
    {
      printf("%s ",inp_parts[i]); 
      i++;  
    }
  printf("\n");
    }
      
  }

void pwd(char** inp_parts){
  char*hru = malloc(1000*sizeof(char));
    if (getcwd(hru, 1000)!=NULL)
    {
        printf("Current working Directory is: %s\n",hru);
    }
    else
    {
        printf("Error\n");
    } 
}
void cd(char**inp_parts){
    
  if(strcmp(inp_parts[1],"~")==0)
  {
    int g = chdir(getenv("HOME"));
    if (g==-1)
    {
      perror("Error");
    }
    }
    else{
      int g = chdir(inp_parts[1]);
    if (g==-1)
    {
      perror("Error");
    } 
    }  
}

int exec(char **inp_parts)
{
    
    int j;
    if (inp_parts[0] == NULL)
    {
        return 1;
    }
    else if (strcmp(inp_parts[0],"pwd")==0)
    {
      
        pwd(inp_parts);
      
    }
      else if(strstr(inp_parts[0],"&t")!=NULL)
      {
        inp_parts[0][strlen(inp_parts[0])-2] = '\0';
        char* ash = malloc(sizeof(char)*1000);
        int i = 0;
        while(inp_parts[i]!=NULL)
          {
            strcat(ash,inp_parts[i]);
          i++;
          }
        thread(ash);
      }
    else if (strcmp(inp_parts[0],"echo")==0)
    {
        echo(inp_parts);
      }
      
     else if (strcmp(inp_parts[0],"cd")==0)
    {
      
        cd(inp_parts);
                
    } 
     else if (strcmp(inp_parts[0],"mkdir")==0)
    {
        fork_callermkdir(inp_parts);        
    }  
    else if (strcmp(inp_parts[0],"date")==0)
    {
        fork_callerdate(inp_parts);        
    }  
  else if (strcmp(inp_parts[0],"rm")==0)
    {
        fork_callerrm(inp_parts);        
    }
  else if (strcmp(inp_parts[0],"cat")==0)
    {
      if(inp_parts[1]==NULL)
      {
        printf("Error: Enter a filename\n");
      }
      else{
        fork_callercat(inp_parts);     
        }
    }  
  else if (strcmp(inp_parts[0],"ls")==0)
    {
        fork_callerls(inp_parts);        
    }  
}
void main_loop(){
    while (1)
    {
        printf("~/ItsNothing/hello$>> ");
        char *input = read_input();
        char **inp_parts = parting_inp(input);
        int execute = exec(inp_parts);
    }
}
int main(int argc, char const *argv[])
{
  global = malloc(sizeof(char)*100);  
  getcwd(global,100);
  
  main_loop();
    return 0;
}
