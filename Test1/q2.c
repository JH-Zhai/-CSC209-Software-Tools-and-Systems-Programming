#include <stdio.h>
#include <stdlib.h>

/* Question 2 [9 marks]  
 * This file goes with the q2.pdf file that contains the memory model diagram
 * for this problem. Submit this file.  You do not need to submit the pdf file.
 *
 * Complete the program below to match the memory model diagram in the pdf file.
 * Remember to free any memory you allocate.
 * You may not "hard-code" the solution.  The function should work as expected
 * if we passed in different arguments. You do not need to handle any corner 
 * cases that do not appear in the memory diagram and can assume enough 
 * memory has been allocated.
 */

/* Set the array ptrs to point to each of the space characters in str.
 * Assume enough memory has been allocated.
 */
void spaces(char *s, char **ptrs) {
	int j = 0;
	for (int i = 0; i < strlen(s); i++){
		if(s[i] == ' '){
			j++;
			ptrs[j] = &(s[i]);
		}
	}

}


/* When you follow the memory model diagram, you will see that main doesn't
 * do anything interesting other than declare and intialize some variable and
 * call a function.  You are welcome to print out values of variables
 * for testing.
 */
int main() {
	int n = 1;
	char **arr[2];
	char *sentence = "Cat vs Dog"
	spaces(sentence, arr);


    return 0;
}
