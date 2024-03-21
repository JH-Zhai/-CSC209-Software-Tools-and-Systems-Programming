/* This file contains the answers to the questions about types
 * The question stated:

 * Given the following struct and variable definitions, give the type of 
 * each variable to make the following statements compile correctly.
 *
 * If the right-hand side is not a valid C expression, or the appropriate 
 * type is not available in the dropdown, select "Error".
 */
#include <stdio.h>


struct card {
    char suit;
    char value[13];
};



int main() {
	
	struct card *deck;
	struct card hand[8];

	struct card **x21 = &deck;
	//char x22 = deck.suit; // error
	char x23 = hand[2].suit;
	char *x24 = &hand[2].suit;
	char x25 = hand[1].value[2];
	struct card x26 = deck[0];
	char x27 = *deck->value;
	char *x28 = &deck[0].value[1];



	return 0;
}

















