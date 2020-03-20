/***

10A) Write a program that creates a file and then goes into an infinite loop. Catch the following signals in the program:

	a) SIGABRT, SIGFPE, SIGINT, SIGQUIT, SIGSEGV, SIGTERM: For these signals program should print a message giving details about the signal 	   caught and then delete the file created in the beginning and finally terminate.

	b) SIGALRM, SIGCHLD, SIGCONT, SIGPIPE, SIGUSR1, SIGUSR2: For these signals, print a message giving details about signal caught and then 	   continue with program execution (don't terminate).

	For testing the program create conditions (may require program modification for some signals) which generate following signals: SIGABRT, 	 SIGINT, SIGQUIT, SIGCHLD, SIGCONT, SIGPIPE. For testing with other signals use kill command from another terminal.


	***************************************************************************************************************************
					Submitted by UMA SANKAR(Regd. No.: 16008)
	***************************************************************************************************************************


***/


#include "apue.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>

int flag = 0;


static void signal_handler(int signo)
{
	printf("pid : %d\n", getpid());
	if(signo == SIGABRT)
	{
		signal(SIGABRT, signal_handler);
		printf("SIGABRT is recieved\n");
		flag = 1;
	}

	else if(signo == SIGFPE)
	{
		signal(SIGFPE, signal_handler);
		printf("SIGFPE is recieved\n");
		flag = 1;
	}

	else if(signo == SIGINT)
	{	
		signal(SIGINT, signal_handler);
		printf("SIGINT is recieved\n");
		flag = 1;
	}

	else if(signo == SIGSEGV)
	{
		signal(SIGSEGV, signal_handler);
		printf("SIGSEGV is recieved\n");
		flag = 1;
	}

	else if(signo == SIGPIPE)
	{
		signal(SIGPIPE, signal_handler);
		printf("SIGPIPE is recieved\n");
	}

	else if(signo == SIGQUIT)
	{
		signal(SIGQUIT, signal_handler);
		printf("SIGQUIT is recieved\n");
		flag = 1;
	}

	else if(signo == SIGTERM)
	{
		signal(SIGTERM, signal_handler);
		printf("SIGTERM is recieved\n");
		flag = 1;
	}

	else if(signo == SIGALRM)
	{
		signal(SIGALRM, signal_handler);
		printf("SIGALRM is recieved\n");
	}

	else if(signo == SIGCHLD)
	{
		signal(SIGCHLD, signal_handler);
		printf("SIGCHLD is recieved\n");
	}

	else if(signo == SIGCONT)
	{
		signal(SIGCONT, signal_handler);
		printf("SIGCONT is recieved\n");
	}

	else if(signo == SIGUSR1)
	{
		signal(SIGUSR1, signal_handler);
		printf("SIGUSR1 is recieved\n");
	}

	else if(signo == SIGUSR2)
	{
		signal(SIGUSR2, signal_handler);
		printf("SIGUSR2 is recieved\n");
	}

	if(flag == 1)
	{
		remove("newfile");
		exit(0);
	}

	flag = 0;

}




void assign_signal_handler()
{

	if(signal(SIGABRT, signal_handler) == SIG_ERR)
		err_sys("can't catch SIGABRT\n");

	if(signal(SIGINT, signal_handler) == SIG_ERR)
		err_sys("can't catch SIGINT\n");

	if(signal(SIGQUIT, signal_handler) == SIG_ERR)
		err_sys("can't catch SIGQUIT\n");

	if(signal(SIGCHLD, signal_handler) == SIG_ERR)
		err_sys("can't catch SIGCHLD\n");

	if(signal(SIGCONT, signal_handler) == SIG_ERR)
		err_sys("can't catch SIGCONT\n");

	if(signal(SIGPIPE, signal_handler) == SIG_ERR)
		err_sys("can't catch SIGPIPE\n");

	if(signal(SIGFPE, signal_handler) == SIG_ERR)
		err_sys("can't catch SIGFPE\n");

	if(signal(SIGSEGV, signal_handler) == SIG_ERR)
		err_sys("can't catch SIGSEGV\n");

	if(signal(SIGTERM, signal_handler) == SIG_ERR)
		err_sys("can't catch SIGTERM\n");

	if(signal(SIGALRM, signal_handler) == SIG_ERR)
		err_sys("can't catch SIGALRM\n");

	if(signal(SIGUSR1, signal_handler) == SIG_ERR)
		err_sys("can't catch SIGUSR1\n");

	if(signal(SIGUSR2, signal_handler) == SIG_ERR)
		err_sys("can't catch SIGUSR2\n");

}



int main()
{


	int filedes;

	if( (filedes = open("newfile", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR )) == -1)
	{
		printf("\nSORRY !!! File could not be opened.\n");
		return 0;
	}

	close(filedes);

	assign_signal_handler();

	while(1)
	{
		int choice;

		printf("Choose from the following options -----------------> : \n");
		printf(" 1.SIGABRT\n 2.SIGINT\n 3.SIGQUIT\n 4.SIGCHLD\n 5.SIGCONT\n 6.SIGPIPE\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1 :   raise(SIGABRT);
				   break;

			case 2 :   raise(SIGINT);
				   break;

			case 3 :   raise(SIGQUIT);
				   break;

			case 4 :   raise(SIGCHLD);
				   break;

			case 5 :   raise(SIGCONT);
				   break;

			case 6 :   raise(SIGPIPE);
				   break;
		}
	}

	return 0;


}

