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
 /* books specification */ 
 struct items catalog[20]= { 
	 {"Book1", 10 , 3}, 
	 {"Book2", 15, 3}, 
	 {"Book3", 20, 3}, 
	 {"Book4", 23, 3}, 
	 {"Book5", 17, 3}, 
	 {"Book6", 19, 3}, 
	 {"Book7", 22, 3}, 
	 {"Book8", 18, 3}, 
	 {"Book9", 26, 3}, 
	 {"Book10", 16, 3}, 
	 {"Book11", 29, 3}, 
	 {"Book12", 15, 3}, 
	 {"Book13", 28, 3}, 
	 {"Book14", 14, 3}, 
	 {"Book15", 27, 3}, 
	 {"Book16", 13, 3}, 
	 {"Book17", 24, 3}, 
	 {"Book18", 12, 3}, 
	 {"Book19", 21, 3}, 
	 {"Book20", 11, 3} };
	

 int i;
 //printf("catalog.desc %s\n", catalog[i]. ); 
//for( i = 0; i < 20; i++) 
 //{ 
	 //catalog[i].item_count=2; 
	 // printf( "Book %d count: %s\n", i ,catalog[i].item_count); 
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
	// parent proccess 
 if ( pid > 0)
    { 
	  int ch;
      int cho; 
	  int arr[10];
	  int buf; 
	  //sleep(1); 
	 
		  close(fd[1]); //we clode fd[0] since we are not going to use it 
		  read(fd[0], &ch, sizeof(ch)); 
          printf("(parent) : read %d\n", ch); 
		  close(fd[0]);
		  
	 //sleep(0.5);

     catalog[ch].item_count--;

			if (catalog[ch].item_count > 1 ){
            	printf( "paragkelia me arithmo  %d pragmatopoihthike \n", ch);

            	no=1;
				//arr[i]=no;
				//printf( "no =  %d  \n", no);
				a= a+1;
        	}
			else if (catalog[ch].item_count = 1 ){
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
 //for( j = 0; j < 5; j++) 
   //{ 
 for( i = 0; i < 10; i++) 
   { 
	 ch = rand()%21;
	
	
	
	  // for( i = 0; i < 10; i++) 
	   //{ 
		   close(fd[0]);
		    //we clode fd[0] since we are not going to use it 
		   // printf("child write %d\n", ch);
			write(fd[1], &ch, sizeof(ch)); 
            }    
  // }  
			m = m+1;
     
   sleep(0.5);
			close(fd[1]); 
			//
		//	 for( i = 0; i < 10; i++) 
	   //{ 
			close(fd1[1]); //we clode fd[0] since we are not going to use it 
		  read(fd1[0], &arr, sizeof(arr)); 
		  //printf("(children) : read %d\n", arr); 
          if (arr == 0)
          {
            printf( "Den pragmatopoihthike h paragkelia  %d  \n", arr);
                             
            }
            else if (arr == 1)
            {
               // printf( "h paragkelia  pragmatopoihthike %d \n", arr);
            }
            
            
          
		  close(fd1[0]);

         
         // sleep(1);
		//printf("total number of orders %d\n", m);
 } 
 //}





//printf("total number of succes orders : %d\n", a);
	// printf("total number of not succes orders : %d\n", n);

 return 0;
 
}

