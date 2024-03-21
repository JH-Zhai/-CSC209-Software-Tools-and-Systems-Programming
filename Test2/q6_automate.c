// [7 marks] Question 6: Processes

/* Complete the program below that takes a filename as an argument.  The 
 * file contains a sequence of commands to run, one per line (see q6_commands 
 * for an example input file).
 * 
 * The program reads one line at a time from the file and executes it in one
 * of two ways:
 *   1) Run the command, print a message when it completes, and then start the
 *      next command.  This is the default behaviour.
 * 
 *      The message printed is:
 *      fprintf(stderr, "%s exited with %d\n", <name of command>, <exit value>);
 *
 *   2) If the command read from the file has "&" as the final word on the line,
 *      then the program will not wait for the command to complete before 
 *      starting the next one, and will not print any output for this process.
 *      Note that "&" is not an argument to the program, and should be removed
 *      from the list of arguments.
 * 
 *  Two helper functions are given that convert the input into a useful data structure.
 * 
 *  Remember that error checking is only necessary if it affects the correctness
 *  of the program, and you do not have to handle invalid input or corner cases.
 *   
 *  Note that when you need to call wait, you will need to wait for a specific 
 *      process id using waitpid().
 *  
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

// Maximum number of words in a line plus 1 
#define MAX_ARGS 10
// Maximum number of character in a line of input
#define MAX_LINE 128


/* Return an array of strings containing the space-separated words in line.
 * Following the valid strings in the array will be a NULL element.
 * The number of non-NULL elements of word will not exceed MAX_ARGS - 1.
 */
char **split_string(char *line);

/* Return the number of strings in strs. Stops counting upon encountering 
 * the first NULL element.
 */
int num_elements(char **strs);


int main(int argc, char **argv) {
    FILE *fp;
    char line[MAX_LINE];
    char **args;
    fp = fopen(argv[1], "r");
    int fd[2];
    int chil[128];


// TODO Complete the remainder of the program. (You may need more variables.)

    while (fgets(line, MAX_LINE, fp) != NULL) {
	    // Split the line into an array of strings
        args = split_string(line);
		// num is set to the number of non-NULL elements in args
        int num = num_elements(args);

        // TODO
        r = fork();
        if(r == 0){
            execvp(args[0], args);
            exit(1)
        }else{
            if(not end with "&"){
                waitpid(r);
            }
        }




    }

    fclose(fp);
    return 0;
}

/* Do not modify the helper functions below. Assume they work as 
 * described above.
 */

char **split_string(char *line) {
    char *ptr = strchr(line, '\n');
    if (ptr != NULL) {
        *ptr = '\0';
    }

    char **words  = malloc(sizeof(char *) * MAX_ARGS);
    words[0] = strtok(line, " ");
    int i = 1;
    while ((words[i] = strtok(NULL, " ")) != NULL) {
        i++;
    }
    return words;
}


int num_elements(char **strs) {
    int count = 0;

    while (strs[count] != NULL) {
        count++;
    }
    return count;
}
