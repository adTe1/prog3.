#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

struct items {
    
    char description[50]; 
	int price ;
	int item_count;

};



int main( int argc, char **argv) {

 int return_value, fd[2]; 
 int return_value1, fd1[2]; 
 pid_t pid; 
 int n=0;
 int no;
 int a=0;
 return_value = pipe(fd); 
 return_value1 = pipe(fd1);
 int i;
   int arr[20];
  for ( i = 0; i < 20; i++) 
   { 
       arr[i]=1;
   }

 /* books specification */ 
 struct items catalog[20]= { 
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
	 {"Book20", 11, 2} };


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

    for ( i = 0; i < 5; i++) 
   { 
	 //printf("child %d \n", i);
	  pid = fork(); 
	  //fork() : creates a new process sleep(1);
	   if(pid == 0) //child process
	    { 
		 exit; 
		} 
	}
	 if ( pid < 0) 
   { 
	 perror("Error");
	  exit(1); 
	}

     if ( pid > 0)
    { 
	  int ch;
      int cho; 
	  int buf; 

     
	  //sleep(1); 
	 //sleep(0.5);
		  close(fd[1]); //we clode fd[0] since we are not going to use it 
		  read(fd[0], &ch, sizeof(ch)); 
          printf("(parent) : read %d\n", ch); 
		  close(fd[0]);
		  
	 //sleep(0.5);
           // arr[ch]= arr[ch]-1;
            catalog[ch].item_count--;

			if (catalog[ch].item_count > 0 ){
            	printf( "paragkelia me arithmo  %d pragmatopoihthike \n", ch);
              //  printf( "paragkelia   %d  \n",catalog[ch].item_count );
                
            	no=1;
				//arr[i]=no;
				//printf( "no =  %d  \n", no);
				a= a+1;
        	}
			else if (catalog[ch].item_count = 0 ){
				printf( "Den pragmatopoihthike h paragkelia me arithmo  %d  \n", ch);
            	no=0;
				//arr[i]=no;
				//printf( "no =  %d  \n", no);
				n= n+1;
            }

            close(fd1[0]); //we clode fd[0] since we are not going to use it 	
            //printf("parent  write  %d\n", no);
		    write(fd1[1], &no, sizeof(no));
		
		    close(fd1[1]);
    		sleep(0.5);
	 //printf("total number of succes orders : %d\n", a);
	 //printf("total number of not succes orders : %d\n", n);
	}

    if(pid==0) //child process 
 {
 int buf; 
 int ch;
 int arr;
 int no;
 int m=0;

 int o;
 int j;

    for( i = 0; i < 10; i++) 
    { 
	    ch = rand()%21;
	    close(fd[0]);
	    // printf("child write %d\n", ch);
	    write(fd[1], &ch, sizeof(ch)); 
    }    
       
	    close(fd[1]); 
 sleep(0.5);
		close(fd1[1]); //we clode fd[0] since we are not going to use it 
		read(fd1[0], &arr, sizeof(arr)); 
		//printf("(children) : read %d\n", arr); 
		close(fd1[0]);

         
       
} 
 




 

 return 0;

 
}