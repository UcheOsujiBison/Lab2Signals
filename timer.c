/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int alarm_count = 0;

void handler(int signum)
{ //signal handler
  alarm_count ++;
  printf("Hello World!\n");
  printf("Turing was right!\n");
  alarm(1); //exit after printing
}

void sigINT_handler(int signum){
  printf("Total Execution Time: %d seconds\n", alarm_count);
  exit(0);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(signum, sigINT_handler); // handler to handle sigINT 
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1){
    sleep(1)
  }; //busy wait for signal to be delivered
  return 0; //never reached
}