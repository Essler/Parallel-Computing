#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main ( int argc, char *argv[] )
{
    int rank, n; /* Rank of thread and number of total threads. */
    double stime, etime; /* Start and end time of program. */
    omp_set_num_threads(6);

    stime = omp_get_wtime();
    #pragma omp parallel default ( shared ) private ( rank, n )
    {
        n = omp_get_num_threads();
        rank = omp_get_thread_num();

        printf( "Hello CBEA from %i of %i!\n", rank+1, n );
    }
    etime = omp_get_wtime();

    printf( "\nTotal Execution Time: %f\n", etime - stime );

    return 0;
}
