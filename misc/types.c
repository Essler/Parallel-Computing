#include <stdio.h>

int main ( void )
{
    printf( "char:\t\t%d bytes = %d bits\n",
            sizeof(char), sizeof(char) * 8 );
    /*printf( "bool:\t\t%d bytes = %d bits\n",
            sizeof(bool), sizeof(bool) * 8 );*/
    printf( "short:\t\t%d bytes = %d bits\n",
            sizeof(short), sizeof(short) * 8 );
    printf( "int:\t\t%d bytes = %d bits\n",
            sizeof(int), sizeof(int) * 8 );
    /*printf( "short int:\t%d bytes = %d bits\n",
            sizeof(short int), sizeof(short int) * 8 );*/
    printf( "unsigned int:\t%d bytes = %d bits\n",
            sizeof(unsigned int), sizeof(unsigned int) * 8 );
    printf( "long:\t\t%d bytes = %d bits\n",
            sizeof(long), sizeof(long) * 8 );
    printf( "long long:\t%d bytes = %d bits\n",
            sizeof(long long), sizeof(long long) * 8 );
    printf( "float:\t\t%d bytes = %d bits\n",
            sizeof(float), sizeof(float) * 8 );
    printf( "double:\t\t%d bytes = %d bits\n",
            sizeof(double), sizeof(double) * 8 );
    printf( "long double:\t%d bytes = %d bits\n",
            sizeof(long double), sizeof(long double) * 8 );

    return 0;
}
