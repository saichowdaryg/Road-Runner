#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include"superio.h"
#include <termios.h> 


int n=0;
char readBuff[4];



char rec(int);

void main() {
	unsigned char ch;
	unsigned int motorEnableWrite1 = 1; //Output pin to Enable motor
	unsigned int motorEnableWrite2 = 6; //Output pin to Enable motor

	unsigned int directionWrite1 = 2; //Output pin to Enable motor
	unsigned int directionWrite2 = 3;

	unsigned int directionWrite21 = 4; //Input pin to read the direction to run the motor
	unsigned int directionWrite22 = 5; //Input pin to read whether to enable the motor or not
	
	//write_gpio(motorEnableRead, 1, 1);  // make motorEnableRead pin as Input
	//write_gpio(directionRead, 1, 1);    // make directionRead pin as Input
	
	
 
           write_gpio(motorEnableWrite1, 0,1);  // give Enable instruction to motor
           write_gpio(motorEnableWrite2, 0,1);  // give Enable instruction to motor
	
	//Server Code		
			int i,j;
			//int k;
			//k = 0;
			char key;

			int listenfd = 0, connfd = 0,n;
	   		char con =1;
    		struct sockaddr_in serv_addr;
    		unsigned char sendBuff[120*90];		// Initialize send Buffer
    		//char readBuff[4]; 					// Initialize read Buffer



// --------------------- Create listening Socket ------------------------------

    listenfd = socket(AF_INET, SOCK_STREAM, 0); 			// Creates a socket; Returns an integer value as a socket descriptor
    if(listenfd == -1)
    {
    	printf("Could not create socket\n");
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff));
    memset(readBuff, '0', sizeof(readBuff));

    serv_addr.sin_family = AF_INET;							// Sets the parameters for an address to a socket
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(9999);						// Sets the port no. as 8888 which is unique across all applications running on processor
    														// and using sockets

    if(bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))<0)  // associates an address to the socket described by listenfd
    	{printf("Bind failed\n");return(0);}

    listen(listenfd, 10);									// Sets the socket listenfd as a listening socket.
    														// listenfd is now ready to accept the connection request from Client
    printf("Waiting for incoming connection.... \n");

// ------------------------------- Waiting for Connection ---------------------------


    while(con)
    {
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);   // Accepts the request from Client and assigns a new socket
        															// to this connection with a desriptor named connfd. Any further
        															// communication on this connection is done using this socket
        if(connfd<0)
        {
        	printf("accept failed\n");
        }
        else {
        	printf("Connection Accepted\n");
        	con=0;
        }
      
     }
// ------------------------------- Connection Established---------------------------------

	while(1){
		
                   ch=rec(connfd);
                   //printf(" %c\n",ch);


		switch(ch){
			case 'a'://left turn
           			write_gpio(motorEnableWrite1, 0,1);  // give Enable instruction to motor
           			write_gpio(motorEnableWrite2, 0,1);  // give Enable instruction to motor
				// write_gpio(motorEnableWrite, 0,1);  // give Enable instruction to motor
				write_gpio(directionWrite1, 0,1);  //give direction instruction to motor
				write_gpio(directionWrite2, 0,0);  //give direction instruction to motor
				// motor2
				write_gpio(directionWrite21, 0,0);  //give direction instruction to motor
				write_gpio(directionWrite22, 0,1);  //give direction instruction to motor
			
				break;
			//straight movt.
			case 's'://write_gpio(motorEnableWrite, 0,1);  // give Enable instruction to motor
				write_gpio(motorEnableWrite1, 0,1);  // give Enable instruction to motor
				write_gpio(motorEnableWrite2, 0,1);  // give Enable instruction to motor
				write_gpio(directionWrite1, 0,1);  //give direction instruction to motor
				write_gpio(directionWrite2, 0,0);  //give direction instruction to motor
				// motor2
				write_gpio(directionWrite21, 0,1);  //give direction instruction to motor
				write_gpio(directionWrite22, 0,0);  //give direction instruction to motor
				break;
			case 'w'://backward movt.
				//write_gpio(motorEnableWrite, 0,1);  // give Enable instruction to motor
				write_gpio(motorEnableWrite1, 0,1);  // give Enable instruction to motor
				write_gpio(motorEnableWrite2, 0,1);  // give Enable instruction to motor
				write_gpio(directionWrite1, 0,0);  //give direction instruction to motor
				write_gpio(directionWrite2, 0,1);  //give direction instruction to motor
				// motor2
				write_gpio(directionWrite21, 0,0);  //give direction instruction to motor
				write_gpio(directionWrite22, 0,1);  //give direction instruction to motor
				break;
			case 'd'://right turn
				//write_gpio(motorEnableWrite, 0,1);  // give Enable instruction to motor
				write_gpio(motorEnableWrite1, 0,1);  // give Enable instruction to motor
				write_gpio(motorEnableWrite2, 0,1);  // give Enable instruction to motor
				write_gpio(directionWrite1, 0,0);  //give direction instruction to motor
				write_gpio(directionWrite2, 0,1);  //give direction instruction to motor
				// motor2
				write_gpio(directionWrite21, 0,1);  //give direction instruction to motor
				write_gpio(directionWrite22, 0,0);  //give direction instruction to motor
				break;
			case 'p'://exit
				write_gpio(motorEnableWrite1, 0,0);  // give Enable instruction to motor
				write_gpio(motorEnableWrite2, 0,0);  // give Enable instruction to motor
				write_gpio(directionWrite1, 0,0);  //give direction instruction to motor
				write_gpio(directionWrite2, 0,0);  //give direction instruction to motor
				// motor2
				write_gpio(directionWrite21, 0,0);  //give direction instruction to motor
				write_gpio(directionWrite22, 0,0); 
				close(connfd);
				exit(1);
                        default :
				write_gpio(motorEnableWrite1, 0,0);  // give Enable instruction to motor
				write_gpio(motorEnableWrite2, 0,0);  // give Enable instruction to motor
                                write_gpio(directionWrite1, 0,0);  //give direction instruction to motor
				write_gpio(directionWrite2, 0,0);  //give direction instruction to motor
				// motor2
				write_gpio(directionWrite21, 0,0);  //give direction instruction to motor
				write_gpio(directionWrite22, 0,0); 

                           }

                    //usleep(1000);
                    ch='q';

                   }

}



char rec(int connfd) 
{
  while(1)
    {
    	

    	n = recv(connfd,readBuff,1,0);

    	if (n < 0) printf("ERROR reading from socket");

	printf("%c\n",readBuff[0]);
	//readBuff[0]=0x00;
	//else{
	//	if n>
	//return(readBuff[0]);}
	if(n>0){
		return readBuff[0];
	}

}

}

