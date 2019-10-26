#include <stdlib.h>
#include <stdio.h> 
#include <math.h>
#include <string.h>

const char* roast_msgs[] = {
    "Go back to driving school",
    "This sim is an actual representation on how you drive in the real world",
    "My grandma drives better than you"
};

// TODO: display roast msg on the screen
static void random_roast_msg() {
    int max_range = sizeof(roast_msgs)/sizeof(roast_msgs[0]);
    int random_roast = rand() % max_range;
    // printf("%s\n",roast_msgs[random_roast]);
}
