#include <stdio.h>
#include <string.h>

bool first, flag, leap;
char in[1000000];
     
int main()
{
    first = true;
    int i, j, n, count, len, sp;
    int rem_4, rem_100, rem_400, rem_15, rem_55;
     
    while( scanf( "%s", in ) != EOF ) {
	leap = false;
	flag = false;
	
	if(!first) printf("\n");
        len = strlen( in );
        rem_4 = rem_100 = rem_15 = rem_55 = 0;
        for( i = 0; i < len; ++i ) {
            in[i] = in[i] - '0';
            rem_4 = ( rem_4*10 + in[i] ) % 4;
            rem_100 = ( rem_100*10 + in[i] ) % 100;
            rem_400 = ( rem_400*10 + in[i] ) % 400;
            rem_15 = ( rem_15*10 + in[i] ) % 15;
            rem_55 = ( rem_55*10 + in[i] ) % 55;
        }
    
        if( ( rem_4 == 0 && rem_100 != 0 ) || ( rem_400 == 0 ) ) {
            printf( "This is leap year.\n" );
            leap = true;
	    flag = true;
        }
        if( rem_15 == 0 ) {
            printf( "This is huluculu festival year.\n" );
	    flag  = true;
	}
        if( leap && rem_55 == 0) {
            printf( "This is bulukulu festival year.\n" );
	}
        if(!flag)
            printf( "This is an ordinary year.\n" );
        first = false;
    }
}

