#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	printf("P1: id: %d id przodka: %d\n", getpid(), getppid());
	switch( fork() )
	{
		case 0:
		printf("P2: id: %d id przodka: %d\n", getpid(), getppid());
		switch ( fork() ) 
		{
			case 0:
			printf("P5: id: %d id przodka: %d\n", getpid(), getppid());
			wait(NULL);
			exit(0);
			
			case -1:
			printf("blad");
			exit (1);
			
			default:
			switch ( fork () )
			{
				case 0:
				switch ( fork () )
				{
					case 0:
					printf("P10: id: %d id przodka: %d\n", getpid(), getppid());
					wait(NULL);
					exit(0);
			
					case -1:
					printf("blad");
					exit (1);
			
					default:
					printf("P6: id: %d id przodka: %d\n", getpid(), getppid());
					wait(NULL);
					exit(0);
				}
				wait(NULL);
				exit(0);
				
				case -1:
				printf("blad");
				exit (1);
				
				default:
				switch ( fork () )
				{
					case 0:
					printf("P7: id: %d id przodka: %d\n", getpid(), getppid());
					exit(0);
			
					case -1:
					printf("blad");
					exit (1);
			
					default:
					wait(NULL);
					exit(0);
				}
				wait(NULL);
				exit(0);
			}
			wait(NULL);
			exit(0);
		}
		wait(NULL);
		exit(0);
		
		case -1:
		printf("blad");
		exit (1);
		
		default:
		switch ( fork() )
		{
			case 0:
			switch ( fork() ) 
			{
				case 0:
				printf("P8: id: %d id przodka: %d\n", getpid(), getppid());
				exit(0);
			
				case -1:
				printf("blad");
				exit (1);
			
				default:
				printf("P3: id: %d id przodka: %d\n", getpid(), getppid());
				wait(NULL);
				exit(0);
			}
			wait(NULL);
			exit(0);
			
			case -1:
			printf("blad");
			exit (1);
			
			default:
			switch ( fork () )
			{
				case 0:
				switch ( fork() ) 
				{
					case 0:
					printf("P9: id: %d id przodka: %d\n", getpid(), getppid());
					exit(0);
			
					case -1:
					printf("blad");
					exit (1);
			
					default:
					printf("P4: id: %d id przodka: %d\n", getpid(), getppid());
					wait(NULL);
					exit(0);
				}
				wait(NULL);
				exit(0);
				
				case -1:
				printf("blad");
				exit (1);
				
				default:
				wait(NULL);
				exit(0);
			}
			wait(NULL);
			exit(0);
		}
		
		
		wait(NULL);
		exit(0);
	}
	
}
