/* Question 3:
 * Complete the functions below according to their comments.
 * You may not change anything outside of the functions
 * A sample input file has been provided, you can run it as
 * ./points < test_points.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point {
    int x;
    int y;
};

struct object {
    char *label;
    int num_points;
    struct point *points;
};

/* [2 marks]
 * Print the object obj in the following format:
 * "label [num_points] (x1 y1) (x2 y2) ...
 * where xi, yi represent the x and y values of each point in points.
 *
 * Example: If the input "ball 3 10 11 20 21 30 31" was used to create the object
 * then the print_object function would print
 * ball [3] (10 11) (20 21) (30 31)
 */
void print_object(struct object *obj) {
    // TODO
    char *tp = malloc((strlen("label [num_points]") + 1) * sizeof(char) + sizeof(char) * 11 * obj->num_points + 1);
    for (int i = 0; i < obj->num_points; i++){
        char *pp = malloc(sizeof(char) * 9);
        strncat(pp, " (", 9)
        strncat(pp, obj->pints[i].x, )
        strncat(tp, (" (%d %d)",obj->points[i]->x, obj->points[i]->y), 11);
    }
    printf("%s\n", tp);
    free(tp);
}


/* [2 marks]
 * Add x to the x value of every point in obj.
 * Add y to the y value of every point in obj.
 */
void move_object(int x, int y, struct object *obj) {
    // TODO
    for (int i = 0; i < obj->num_points; i++){
        obj->points[i].x += x;
        obj->points[i].y += y;
    }
}


/* [6 marks]
 * Create and return a new object with a copy of the given parameters.
 */
struct object *create_obj(char *label, int num, struct point *pts) {
    // TODO
    struct object *new = malloc(sizeof(struct object));
    new->label = label;
    new->num_points = num;
    new->points = pts;
    return new;
}


/* [2 marks]
 * Free all the memory allocated for object obj
 */
void free_object(struct object *obj) {
    // TODO
    free(obj->label);
    // for(int i = 0; i<obj->num_points; i++){
    //     free(obj->points[i])
    // }
    free(obj->points);
    free(obj);
}


// Do not change anything below this line.
// You can run the program as
// ./points < test_points.txt
#ifndef TESTING

int main(int argc, char **argv) {

    char line[256];
    int num;
    struct point pts[10];

    /* Read in the data for the first object */
    scanf("%s ", line);
    scanf("%d ", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d %d", &pts[i].x, &pts[i].y);
    }
    struct object *o1 = create_obj(line, num, pts);
    move_object(10, 20, o1);

    /* Read in the data for the second object */
    scanf("%s ", line);
    scanf("%d ", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d %d ", &pts[i].x, &pts[i].y);
    }
    struct object *o2 = create_obj(line, num, pts);

    print_object(o1);
    print_object(o2);
    free_object(o1);
    free_object(o2);
    return 0;
}
#endif
