#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<sys/wait.h>
#include  <sys/types.h>
#include <fcntl.h>
 
struct items {
   char  description[50];
   float  price [50];
   int   item_count;
};


int main( int argc, char **argv) {

  
   int return_value, fd[2];
   int return_value1, fd1[2];
  
   int n;
   int num;

   return_value = pipe(fd);
   return_value1 = pipe(fd1);
    /* books  specification */
	struct items catalog[20] = {
                            {"Book1", 10 , 2},
                            {"Book2", 15, 2},
							{"Book3", 20, 2},
                            {"Book4", 23, 2},
							{"Book5", 17, 2},
                            {"Book6", 19, 2},
							{"Book7", 22, 2},
                            {"Book8", 18, 2},
							{"Book9", 26, 2},
                            {"Book10", 16, 2},
							{"Book11", 29, 2},
                            {"Book12", 15, 2},
							{"Book13", 28, 2},
                            {"Book14", 14, 2},
							{"Book15", 27, 2},
                            {"Book16", 13, 2},
							{"Book17", 24, 2},
                            {"Book18", 12, 2},
							{"Book19", 21, 2},
                            {"Book20", 11, 2}
                        };


	int i;
   //for( i = 0; i < 20; i++) {
	   
//printf( "Book %d count: %s\n", i ,catalog[i].description);
	  // strcpy( catalog[i].description, "Book");
		//catalog[i].price = i + i + i;
     //fscanf(fp,"%s", ch[i]);
     //printf("\n %s", ch[i]);
   // }

	if(return_value == -1)
    {
        perror("Error");
        exit(1);
    }
    if(return_value1 == -1)
    {
        perror("Error");
        exit(1);
    }



 	//for( i = 0; i < 20; i++) {
		//printf( "Book %d title : %s\n", i ,catalog[i].description);
 
	//}
     pid_t pid;
	for ( i = 0; i < 5; i++)
    {
        
        pid = fork(); //fork() : creates a new process
        
      if(pid == 0) //child process
        {
           break;
         exit;
	    }
    }
if ( pid < 0)
    {
        perror("Error");
        exit(1);
    }

    if(pid == 0) //child process
    {
	    
     for( i = 0; i < 10; i++) {
            int buf;
 
            close(fd[0]); //we clode fd[0] since we are not going to use it
            n = rand()%21;
            buf = n;
            printf("child write %d\n", buf);
		    write(fd[1], &buf, sizeof(buf));
		
		   // close(fd[1]);
            sleep(0.5);
        
           
        }
        exit;
    }

	
	// parent proccess
    if ( pid > 0)
    {
        int buf;
        int bytes;
        
        close(fd[1]); //we clode fd[0] since we are not going to use it
        sleep(0.5);
        // read(fd[0], &buf, sizeof(buf)); 
         bytes = read(fd[0], &buf, sizeof(buf));
    printf("Read %d bytes: %s\n", bytes, buf);

		//read(fd[0], &num, sizeof(num));
       // printf("(Parent) Eshop : read %d\n", buf); 
        //printf("%d\n", num);
        
	//	close(fd[0]);
        
		/*close(fd[0]); 
		write(fd[1], &num, sizeof(num));
		close(fd[1]); */
      
    	
		
    	
        
    }

  
    



	return 0;
}