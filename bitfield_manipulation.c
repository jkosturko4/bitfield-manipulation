/*
 * bitfield_manipulation.c
 *
 *  Created on: Nov 1, 2016
 *      Author: jay
 */

#include <stdio.h>
#include <string.h>

typedef unsigned char bitfield_t;

//#define DEBUG 1

void bitfield_display( bitfield_t bitfield ){

	char bitfield_as_str[ 9 ];
	bzero( bitfield_as_str, 9 );

#ifdef DEBUG
	printf( "[debug] bitfield_display( ) bitfield: 0x%02x\n", bitfield );
#endif

	int i;
	for (i = 128; i > 0; i >>= 1 ){

		strcat(bitfield_as_str, ( ( bitfield & i ) == i ) ? "1" : "0");

	}

	printf( "bitfield: %s\n", bitfield_as_str );


}

void bitfield_rotate_right( bitfield_t *bitfield ){

	// if we have a bit at the GSB 0x1_______
	unsigned int bit_to_keep = ( ( *bitfield & 1 ) ? 1 : 0 );

	*bitfield >>=1 ;	// shift

	if( bit_to_keep == 1 )
		*bitfield += 128 ;		// add the bit to the least significant position

}

void bitfield_rotate_left( bitfield_t *bitfield ){

	// if we have a bit at the GSB 0x1_______
	unsigned int bit_to_keep = ( ( *bitfield & 128 ) ? 1 : 0 );

	*bitfield <<=1 ;	// shift

	if( bit_to_keep == 1 )
		*bitfield += 1 ;		// add the bit to the least significant position

}

void bitfield_shift_right( bitfield_t *bitfield ){

	*bitfield >>= 1;

}

void bitfield_shift_left( bitfield_t *bitfield ){

	*bitfield <<= 1;

}

int main( int argc, char **argv ){

	bitfield_t bitfield;

	bitfield = 0xF0; // binary 1010 1010

	printf( "start\n");
	bitfield_display( bitfield );

	int i;
	for( i = 0; i < 16; i++ ){
		bitfield_rotate_left( &bitfield );
		bitfield_display( bitfield );

	}

	return 0;

}
