
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<sys/wait.h>
#include  <sys/types.h>
#include <fcntl.h>

//#define die(e) do { fprintf(stderr, " %s\n ", e); exit(EXIT_FAILURE); } while (0);


int main(int argc, char **argv)
{
FILE *fp;

int lines =0;	
int return_value, re_val[12] , fd[2], fd1[1000][2];

 
    pid_t pid;
    int i;
	int num;
	
	return_value = pipe(fd);

      


    if(return_value == -1)
    {
        perror("Error");
        exit(1);
    }


	fp = fopen("nonsense_words.txt", "r");
	
    if (fp == NULL)
    {
        printf("Couldn't open file\n");
        return 1;
    }

//count the lines of nonsense.txt
	while (EOF != (fscanf(fp, "%*[^\n]"), fscanf(fp,"%*c")))
        ++lines;



	  char ch[lines][1000];
	

//start file from begining
    fseek (fp, 0 , SEEK_SET);

	for( i = 0; i < lines; i++) {
     fscanf(fp,"%s", ch[i]);
     //printf("\n %s", ch[i]);
    }

    for( i = 0; i < lines; i++) {
        re_val[i] = pipe(fd1[i]);
     if(re_val[i] == -1)
    {
       perror("Error");
       exit(1);
    } 
    }
	
    
	

	for ( i = 0; i < lines; i++)
    {
        
        pid = fork(); //fork() : creates a new process
      if(pid == 0) //child process
        {
            
            break;
        }
    }

	if ( pid < 0)
    {
        perror("Error");
        exit(1);
    }

	// parent proccess
    if ( pid > 0)
    {
       
        close(fd[0]); //we clode fd[0] since we are not going to use it
        for ( i = 0; i < lines; i++)
		{
            num = i;
            write(fd[1], &num, sizeof(num));
            //printf("Parent: written %d\n", num);   
        }
		close(fd[1]);

		
        char buffer[1000];
        for ( i = 0; i < lines; i++)
		{
              ssize_t size = read(fd1[i][0], buffer, 1000);
              if ( (size>0) && (size<sizeof(buffer)) )
              {
                     buffer[size]='\0';
                     printf("%s\n", buffer);
              }
        }
	
    	
		
    	wait(NULL);
        
    }

			//if(pid==0) //child process
    else
    {
        //find the row number  
        close(fd[1]);
        read(fd[0], &num, sizeof(num)); 
            printf("child : read %d from pipe \n", num);
        close(fd[0]);

       
            //redirect  stdout to pipe
            char *programName = "./find_correct_word";
            char *args[] = {programName, "dictionary.txt" , ch[num] , NULL};

              dup2(fd1[num][1], STDOUT_FILENO);
              
         execvp(programName, args);
    		
        exit(0);  

 
    }
       



	fclose(fp);

   
    return 0;
}

