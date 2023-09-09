#include "utilities.h"

// cuz im lazy
int randRange(int min, int max)
{
    return (rand() % (max - min)) + min;
}

    //start_time = clock();
    //end_time = clock();
void printTimeDiff(clock_t start_time, clock_t end_time) {
    printf("Elapsed time: %.2f seconds\n\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
}