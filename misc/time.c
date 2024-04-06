#include <stdio.h>
#include <time.h>

int main ( void )
{
    clock_t start, end;
    time_t stime, etime;
    int i, j;
    unsigned int sum = 0;

    time( &stime );
    start = clock();
    for ( i = 0; i < 10000; i++ )
    {
        for ( j = 0; j < 10000; j++ )
        {
            sum += i;
        }
    }
    end = clock();
    time( &etime );

    printf( "wall: %6.3f\n", (double)difftime( etime, stime ) );
    printf( " cpu: %6.3f\n", (double)(end - start)/CLOCKS_PER_SEC);
    printf( " sum: %u\n", sum );

    return 0;
}
