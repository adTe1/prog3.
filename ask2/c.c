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
 struct items catalog[20] 

 int i;//printf("catalog.desc %s\n", catalog[i].description ); 
for( i = 0; i < 20; i++) 
 { 
	 catalog[i].item_count=2; 
	 // printf( "Book %d count: %s\n", 1 ,catalog[1].item_count); 
	 } 
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
	  int ch[10]; 
	  int arr[10];
	  int buf; 
	  sleep(1); 
	  for( i = 0; i < 10; i++) { 
		  close(fd[1]); //we clode fd[0] since we are not going to use it 
		  read(fd[0], ch, sizeof(ch)); 
		  printf("(Parent) Eshop : read %d\n", ch[i]); 
		  close(fd[0]);
		  catalog[ch[i]].item_count--;

			if (catalog[ch[i]].item_count >= 0 ){
            	printf( "paragkelia me arithmo  %d pragmatopoihthike \n", ch[i]);

            	no=1;
				arr[i]=no;
				printf( "no =  %d  \n", no);
				a= a+1;
        	}
			else
			{
				printf( "Den pragmatopoihthike h paragkelia me arithmo  %d  \n", ch[i]);
            	no=0;
				arr[i]=no;
				printf( "no =  %d  \n", no);
				n= n+1;
			}

	    }	
			 for( i = 0; i < 10; i++) {
	   
			close(fd1[0]); //we clode fd[0] since we are not going to use it 	
            //printf("parent  write  %d\n", no);
		    write(fd1[1], arr, sizeof(arr));
		
		    close(fd1[1]);
    		sleep(1);
		}
			
		 // if (catalog[ch[i]].item_count != 0 ){ 
	 	 // printf( "Book %d item count : %s\n",ch[i], catalog[ch[i]].item_count); 
 		 //}
 		  //for( i = 0; i < 20; i++) { 
	 //printf( "Book %d title : %s\n", i ,catalog[i].item_count); 
	 //} 
	 sleep(0.5);
	 printf("total number of succes orders : %d\n", a);
	 printf("total number of not succes orders : %d\n", n);
	}

  

 if(pid==0) //child process 
 {
 int buf; 
 int ch[10];
 int arr[10];
 int no;
 int m=0;

 int o;
 
 for( i = 0; i < 10; i++) 
   { 
	 ch[i] = rand()%21;
	}
	int j;
	//for( j = 0; j < 5; j++) 
   //{ 
	   for( i = 0; i < 10; i++) 
	   { 
		   close(fd[0]);
		    //we clode fd[0] since we are not going to use it 
		    printf("child write %d\n", ch[i]);
			write(fd[1], ch, sizeof(ch));
			m = m+1;
		//}
			close(fd[1]); 
		//	 for( i = 0; i < 10; i++) 
	   //{ 
			close(fd1[1]); //we clode fd[0] since we are not going to use it 
		  read(fd1[0], arr, sizeof(arr)); 
		  printf("(children) : read %d\n", arr[i]); 
		  close(fd1[0]);
	   }


		printf("total number of orders %d\n", m);
 } 
 //}







 return 0;
 
}

