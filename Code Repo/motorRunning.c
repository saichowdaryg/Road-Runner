#include<stdio.h>
#include<unistd.h>
#include"superio.h"
#include <termios.h> 




char linux_getch(void);
void main() {
	unsigned char ch;
	unsigned int motorEnableWrite = 1; //Output pin to Enable motor

	unsigned int directionWrite1 = 2; //Output pin to Enable motor
	unsigned int directionWrite2 = 3;

	unsigned int directionWrite21 = 4; //Input pin to read the direction to run the motor
	unsigned int directionWrite22 = 6; //Input pin to read whether to enable the motor or not
	
	//write_gpio(motorEnableRead, 1, 1);  // make motorEnableRead pin as Input
	//write_gpio(directionRead, 1, 1);    // make directionRead pin as Input
 
           write_gpio(motorEnableWrite, 0,0);  // give Enable instruction to motor
           write_gpio(directionWrite1, 0,0);  //give direction instruction to motor
	   write_gpio(directionWrite2, 0,0);  //give direction instruction to motor
	   // motor2
	   write_gpio(directionWrite21, 0,0);  //give direction instruction to motor
	   write_gpio(directionWrite22, 0,0);
	   
	while(1){
		

                   ch=linux_getch();
                   printf(" %c\n",ch);


		switch(ch){
			case 'a'://left turn
				// write_gpio(motorEnableWrite, 0,1);  // give Enable instruction to motor
				write_gpio(motorEnableWrite, 0,1);
				write_gpio(directionWrite1, 0,1);  //give direction instruction to motor
				write_gpio(directionWrite2, 0,0);  //give direction instruction to motor
				// motor2
				write_gpio(directionWrite21, 0,0);  //give direction instruction to motor
				write_gpio(directionWrite22, 0,1);  //give direction instruction to motor
			
				break;
			//straight movt.
			case 'w'://write_gpio(motorEnableWrite, 0,1);  // give Enable instruction to motor
				write_gpio(motorEnableWrite, 0,1);
				write_gpio(directionWrite1, 0,1);  //give direction instruction to motor
				write_gpio(directionWrite2, 0,0);  //give direction instruction to motor
				// motor2
				write_gpio(directionWrite21, 0,1);  //give direction instruction to motor
				write_gpio(directionWrite22, 0,0);  //give direction instruction to motor
				break;
			case 's'://backward movt.
				//write_gpio(motorEnableWrite, 0,1);  // give Enable instruction to motor
				write_gpio(motorEnableWrite, 0,1);
				write_gpio(directionWrite1, 0,0);  //give direction instruction to motor
				write_gpio(directionWrite2, 0,1);  //give direction instruction to motor
				// motor2
				write_gpio(directionWrite21, 0,0);  //give direction instruction to motor
				write_gpio(directionWrite22, 0,1);  //give direction instruction to motor
				break;
			case 'd'://right turn
				//write_gpio(motorEnableWrite, 0,1);  // give Enable instruction to motor
				write_gpio(motorEnableWrite, 0,1);
				write_gpio(directionWrite1, 0,0);  //give direction instruction to motor
				write_gpio(directionWrite2, 0,1);  //give direction instruction to motor
				// motor2
				write_gpio(directionWrite21, 0,1);  //give direction instruction to motor
				write_gpio(directionWrite22, 0,0);  //give direction instruction to motor
				break;
			case 'p':
				write_gpio(motorEnableWrite, 0,0);
                                write_gpio(directionWrite1, 0,0);  //give direction instruction to motor
				write_gpio(directionWrite2, 0,0);  //give direction instruction to motor
				// motor2
				write_gpio(directionWrite21, 0,0);  //give direction instruction to motor
				write_gpio(directionWrite22, 0,0);
				exit(1);
                        default :
                        	write_gpio(motorEnableWrite, 0,0);
                                write_gpio(directionWrite1, 0,0);  //give direction instruction to motor
				write_gpio(directionWrite2, 0,0);  //give direction instruction to motor
				// motor2
				write_gpio(directionWrite21, 0,0);  //give direction instruction to motor
				write_gpio(directionWrite22, 0,0); 

                           }
                   }
}



char linux_getch(void) 
{
  struct termios oldstuff;
  struct termios newstuff;
  int    inch;
  
  tcgetattr(STDIN_FILENO, &oldstuff);
  newstuff = oldstuff;                  /* save old attributes               */
  newstuff.c_lflag &= ~(ICANON | ECHO); /* reset "canonical" and "echo" flags*/
  tcsetattr(STDIN_FILENO, TCSANOW, &newstuff); /* set new attributes         */
  inch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldstuff); /* restore old attributes     */

 
  return inch;
}

