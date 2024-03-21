/* This file contains the answers to the questions about types
 * The question stated:

 * Given the following struct and variable definitions, give the type of 
 * each variable to make the following statements compile correctly.
 *
 * If the right-hand side is not a valid C expression, or the appropriate 
 * type is not available in the dropdown, select "Error".
 */
#include <stdio.h>

struct entry {
    char *name;
    int scores[16];
};

struct team {
    char *name;
    char *players[4];
};

struct card {
    char suit;
    char value[13];
};

struct ingredient {
    char label[30];
    int amount;
    char *unit;
};

int main() {
	struct entry *roster;
	struct entry players[4];

	struct entry **x1 = &roster;
	char *x2 = roster->name;
	struct entry *x3 = &players[1];
	int *x4 = players[2].scores;
	int x5 = players[1].scores[2];
	char *x6 = roster[0].name;
	//char *x7 = (*players)->name; //ERROR
	char x8 = roster[0].name[1];

	struct team *curl;
	struct team flight[8];

	struct team x11 = *curl;
	//char *x12 = curl.name; //ERROR
	char **x13 = &flight[1].name;
	struct team **x14 = &curl;
	char *x15 = flight[1].players[2];
	//char x18 = *curl[0].name[1]; // ERROR
	struct team x16 = flight[2];
	char x17 = *curl->name;


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

	struct ingredient *beans;
	struct ingredient recipe[10];

	struct ingredient x31 = *beans;
	//char * x32 = beans.unit; //error
	char * x33 = recipe[2].unit;
	//int x38 = *beans->amount; //error
	int * x34 = &recipe[2].amount;
	char x35 = recipe[1].unit[1];
	char * x36 = beans[0].label;
	char x37 = *beans->unit;

	return 0;
}

















