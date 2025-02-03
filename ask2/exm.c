
   #include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>


struct items {
   char  description[50];
   float  price [50];
   int   item_count[2];
};


int main (int argc, char **argv)
{

    pid_t Cpid;
    int fd[2]; 
    int  rVal;

    // Create the pipe BEFORE forking.
    pipe(fd);    

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
    for ( i = 0; i < 5; i++)
    {
        //pid will store the value of fork()
        Cpid = fork();
        if(Cpid == 0) //child process
        {
            break;
        }
    }

    if( Cpid == 0) 
    {

        //CHILD
        rVal = rand()%100;
    ;
//this is in child process
    close (fd[0]);
    int i;
    for( i = 0; i < 10; i++) {
     rVal = rand()%21;
     write(fd[1], &rVal,sizeof (rVal));
     printf(" children  send : %d\n", rVal);
     
    }
    close (fd[1]);


    sleep(0.5);
    }

    if ( Cpid < 0)
    {
        perror("Error");
        exit(1);
    }


    else if(Cpid != 0 )
    {

       
        //this is the parent process
        close(fd[1]);
        //read(fd[0], &rVal, sizeof(rVal));
        while (read(fd[0], &rVal, sizeof(rVal)) );
    {
        printf("parent : read %s  \n", rVal);
        // printf("File descriptor associated with output stream is: %d\n", fileno(stdout));
    }
        printf(" parent  recieved : %d\n", rVal);
        close(fd[0]);
       
    sleep(0.5);
    }



    return 0;


}