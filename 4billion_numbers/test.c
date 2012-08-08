/*
 * vim:expandtab:shiftwidth=8:tabstop=8:
 *
 * Copyright 2011
 * contributeur : Raghvendra Kumar Yadav (raghavmnnit@gmail.com) 
 *
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 * 
 * ---------------------------------------
 */

#include<stdio.h>
#include<stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

//array size to store all the integers
#define BIT_ARRAY_SIZE 536870912
#define CHAR_BIT 8
unsigned char number[BIT_ARRAY_SIZE] = {0};//GLOBAL ARRAY which contains the bitmap for integers
typedef enum bool{FALSE ,TRUE}Error;

int setBit( unsigned int  num)
{
	unsigned int array_index;
	uint8_t bit_offset;
	array_index = num / CHAR_BIT; // base is the char whose certain bit needs to be set
	bit_offset  = 1 << (num % CHAR_BIT ); // offset is the bit to be set
	number[array_index] |= bit_offset; // I set the particular bit1    
	return 0; 
}

void printNumbers()
{
	unsigned int array_index;
	uint8_t bit_offset;
	int loop , bit_loop;
	unsigned int temp_num = 0; 
	for (loop = 0 ; loop < BIT_ARRAY_SIZE ;loop++ ) {
		for(bit_loop = 0 ;bit_loop < CHAR_BIT ;bit_loop++){
			bit_offset  = 1 << bit_loop; // offset is the bit to be set
			if( number[loop] & bit_offset){
				temp_num = (loop * CHAR_BIT) + bit_loop ; 
				printf("%d\n",temp_num); 
			}
		}
	}
}

int main(int argc , char *argv[])
{
	int no_of_elements = 0;
	int loop;
	unsigned int temp_num;
	Error error = FALSE ;
	if(argc!=2){
		fprintf(stderr,"usage:program no_of_elements \n");
		return 1; 
	}
	no_of_elements = atoi(argv[1]);
	//print the number in sorted order
	for(loop = 0; loop < no_of_elements ; loop++){
		printf("enter the number \n");
		scanf("%d",&temp_num);
		if(setBit(temp_num)){
			printf("error in setting the bit for integer\n");
			error = TRUE;
			break;
		}
	}

	if(error){
		printf("program does not completed successfully\n");        
		return 1;
	}else{
		//print the number in sorted order
		printf("printing the numbers in sorted manner \n");
		printNumbers();
		printf("program completed successfully \n") ;
 	        return 0;
	}
}
