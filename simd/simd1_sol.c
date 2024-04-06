/* Calculates the sum between 1 and 1024 by performing SIMD operations.

   Since data type is int, SIMD operations can handle four values at a
   time. Thus, it is possible to partition the data (numbers from 1 to
   1024) into segments of four values. Calculate the partial sums for
   all segments and then add those partial sums together to find the
   total sum. */

#include <stdio.h>
#include <altivec.h>

/* MAX_NUM should be evenly divisible by 4 to give the correct answer
   with this SIMD implementation. */
#define MAX_NUM (1024)

int main ( int argc, char **argv )
{
    int i;
    int sum = 0;
    int *psum;

    __vector signed int va    = (__vector signed int) { 1, 2, 3, 4 };
    __vector signed int vsum  = (__vector signed int) { 0, 0, 0, 0 };
    __vector signed int vstep = (__vector signed int) { 4, 4, 4, 4 };

    /* Calculate partial sums. */
    for ( i = 1; i <= MAX_NUM; i+=4 )
    {
        /* Add vector variable va to vector variable vsum. */
        vsum = vec_add( vsum, va );

        /* Increment vector variable va by 4 using the vector variable
           vstep on each iteration. */
        va = vec_add( va, vstep );
    }

    /* Calculate total sum, making reference to the four partial sums
       in scalar form. */
    psum = (int *) &vsum;
    sum = psum[0] + psum[1] + psum[2] + psum[3];

    printf( "sum: %d\n", sum );

    return 0;
}
