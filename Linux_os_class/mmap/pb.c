#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/time.h>
#include<fcntl.h>
#include<sys/mman.h>

#define MAX 10000

int main()
{
    int i=0;
    int fd=0;
    struct timeval tv1, tv2;
    int *array = (int *)malloc( sizeof(int)*MAX );

    gettimeofday( &tv1, NULL );
    fd = open( "/home/chenzhenxxx/git/czx_first/Linux_os_class/mmap/test.txt", O_RDWR );
    if( sizeof(int)*MAX != read( fd, (void *)array, sizeof(int)*MAX ) )
    {
        printf( "Reading data failed.../n" );
        return -1;
    }

    for( i=0; i<MAX; ++i )
    {
        ++array[ i ];
    }

    if( sizeof(int)*MAX != write( fd, (void *)array, sizeof(int)*MAX ) )
    {
        printf( "Writing data failed.../n" );
        return -1;
    }

    close( fd );
    gettimeofday( &tv2, NULL );
    printf( "Time of read/write: %dms/n", tv2.tv_usec-tv1.tv_usec );

    pause();

    return 0;
}