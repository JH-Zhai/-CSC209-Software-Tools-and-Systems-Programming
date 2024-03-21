/*  [7 marks]
 *  Question 3: Binary Files
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct game {
    char team[60];
    int score;
};
/* PART 1: [1 mark]
 * Define a new type called Game for the above struct
 */



/* PART 2: [6 marks]
 * Complete the program below that will update the the game_num'th game record stored
 * in the file score_file with a new score. 
 *  - Do not read the whole file. 
 *  - Assume there are enough game records in the file.
 *  - Ensure that the file is closed before the process terminates.
 *  - No error checking is needed.
 * 
 * Command line arguments:
 * score_file - name of a binary file that contains a sequence of 
 *              struct game records
 * game_num - identifies the game struct in the file to update. 
 *            Start numbering at 0.
 * team - the team must match the name stored in the game_num'th record or 
 *        the record won't be updated.
 * new_score - the new value for the score field
 *
 * Example:
 *    ./q3_update_score q3_games 3 Koe 2
 * will change the score in the 3rd game record to 2 because team name in that 
 * record matches "Koe"
 */

#define MESSAGE "Team does not match.  Cannot update score.\n"

int main(int argc, char **argv) {
    char *score_file = argv[1];  
    int game_num = atoi(argv[2]);
    char *team = argv[3];
    int new_score = atoi(argv[4]);

    struct game old_game;
    struct game new_game;

    // Create a new game struct with the command-line arguments
    new_game.score = new_score;
    strncpy(new_game.team, team, 60);
    new_game.team[59] = '\0';

    FILE *fp = fopen(score_file, "r+");

    /* Complete the program below
     * Read the record stored as the game_num'th record in the file score_file
     * If the team name of that record matches the team field in new_game struct
     * above then update the record in the file.
     * If it does not match, then print MESSAGE
     */




    return 0;

}
