/*-------------------------------------------------------------------*/
/* Fork() on CBEA                                                    */
/*-------------------------------------------------------------------*/
/* Description:                                                      */
/*                                                                   */
/* This program tests the functionality of the fork() function while */
/* running on the Cell Broadband Engine Architecture.                */
/*-------------------------------------------------------------------*/
/*                                     Brandon Essler - 24 June 2010 */
/*-------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int main ( void )
{
	pid_t child_pid, p;

    child_pid = fork();
    p = getpid();

    if ( child_pid == -1 )
    {
        printf( "Fork error, aborting...\n" );
    }
    else if ( child_pid == 0 )
    {
        printf( "child process %d; parent process %d\n", p, getppid() );
    }
    else if ( child_pid > 0 )
    {
        printf( "original process %d; parent process %d\n", p, getppid() );
    }

    return EXIT_SUCCESS;
}
