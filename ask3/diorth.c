#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <netinet/in.h> 
#include <sys/socket.h>

#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

struct items
{

	char description[50];
	int price;
	int item_count;
};

int main(int argc, char **argv)
{

	int return_value, fd[5][2];
	int return_value1, fd1[5][2];
	pid_t pid;
	int n = 0;
	int no;
	int a = 0;
	int tzi = 0;
	int i;

	int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
  
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    len = sizeof(cli); 

	for (i = 0; i < 5; i++)
	{
		return_value = pipe(fd[i]);
		return_value1 = pipe(fd1[i]);
	}

	int arr[20];
	for (i = 0; i < 20; i++)
	{
		arr[i] = 1;
	}

	if (return_value == -1)
	{
		perror("Error");
		exit(1);
	}
	if (return_value1 == -1)
	{
		perror("Error");
		exit(1);
	}

	for (i = 0; i < 5; i++)
	{
		//printf("child %d \n", i);
		connfd = accept(sockfd, (SA*)&cli, &len);
		pid = fork();
		//fork() : creates a new process sleep(1);
		if (pid == 0) //child process
		{
			break;
		}

		close(connfd);
	}

	close(sockfd);
	if (pid < 0)
	{
		perror("Error");
		exit(1);
	}

	if (pid > 0)
	{
		int ch;
		int cho;
		int buf;
		int arrAit[20];
		int tot;
		int i;
		int j;
		int list[5][20];

		/* books specification */
		struct items catalog[20] = {
			{"Book1", 10, 2},
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
			{"Book20", 11, 2}};

		for (i = 0; i < 20; i++)
		{
			arrAit[i] = 0;
		}

		for (i = 0; i < 5; i++)
		{
			close(fd[i][1]);  //we clode fd[0] since we are not going to use it
			close(fd1[i][0]); //we clode fd[0] since we are not going to use it

			for (j = 0; j < 10; j++)
			{
				read(fd[i][0], &ch, sizeof(ch));
				//printf("(parent) : read %d\n", ch);

				//sleep(0.5);
				// arr[ch]= arr[ch]-1;
				//
				//

				if (catalog[ch].item_count > 0)
				{
					//printf("paragkelia me arithmo  %d pragmatopoihthike \n", ch);
					//  printf( "paragkelia   %d  \n",catalog[ch].item_count );\

					catalog[ch].item_count--;
					arrAit[ch] = arrAit[ch] + 1;
					tzi = tzi + catalog[ch].price;
					no = 1;
					//arr[i]=no;
					//printf( "no =  %d  \n", no);
					a = a + 1;
				}
				else if (catalog[ch].item_count == 0)
				{
					//printf("Den pragmatopoihthike h paragkelia me arithmo  %d  \n", ch);
					no = 0;
					arrAit[ch] = arrAit[ch] + 1;
					list[i][ch] = i;
					//arr[i]=no;
					//printf( "no =  %d  \n", no);
					n = n + 1;
				}

				//printf("parent  write  %d\n", no);
				write(fd1[i][1], &no, sizeof(no));

				//sleep(1);
			}
			close(fd[i][0]);
			close(fd1[i][1]);
		}
		//
		//
		//sleep(1);
		//sleep(0.5);
		for (i = 0; i < 20; i++)
		{
			printf("item description : %s\n", catalog[i].description);
			printf("arithmos aithmatwn : %d\n", arrAit[i]);

			if (catalog[i].item_count == 0)
			{
				printf("poulithikan 2 temaxia \n");
			}
			else if (catalog[i].item_count > 0)
			{
				printf("poulithike 1 temaxio \n");
			}
			printf("lista xrhstwn pou den exipiretithikan : \n");
			for (j = 0; j < 5; j++)
			{
				if (list[j][i] > 0 && list[j][i] < 20)
				{

					printf(": %d\n", list[j][i]);
				}
			}
		}

		tot = n + a;
		printf("total number of  orders : %d\n", tot);
		printf("total number of succes orders : %d\n", a);
		printf("total number of not succes orders : %d\n", n);
		printf("total tziros : %d E\n", tzi);
	}

	if (pid == 0) //child process
	{
		int buf;
		int ch;
		int arr;
		int no;
		int m = 0;

		int o;
		int j;

		for (j = 0; j < 10; j++)
		{
			//Read
			read(connfd, &ch, sizeof(ch)); 
			//printf("child write %d\n", ch);
			write(fd[i][1], &ch, sizeof(ch)); // 0-19   -> 0-19     //  0-1  <-

			//Receive
			read(fd1[i][0], &arr, sizeof(arr));

			write(connfd, &arr, sizeof(arr)); 
			//printf("Result %d\n", arr);
		}
		close(fd[i][0]);
		close(fd[i][1]);
		//sleep(1);

		//printf("(children) : read %d\n", arr);
		close(fd1[i][1]); //we clode fd[0] since we are not going to use it
		close(fd1[i][0]);

		close(connfd);
	}

	return 0;
}