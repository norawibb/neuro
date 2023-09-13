// Jinora

#include <stdio.h>
#include <stdlib.h>

#include "neurotron.h"
#include "utilities.h"

int main(int argc, char **argv)
{
    printf("\n--<< Welcome to Neuro >>--\n\n");
    srand(time(NULL));

    clock_t start_time, end_time;
    Neurotron *neurotron = createNeurotron(8, 17, 5);
    printNeurotron(neurotron);
    FILE *fptr = createNeurotronFile(neurotron, "testoutput.txt");
    exportNeurotronState(neurotron, fptr);
    updateNeurotron(neurotron);
    printNeurotron(neurotron);
    exportNeurotronState(neurotron, fptr);
    updateNeurotron(neurotron);
    printNeurotron(neurotron);
    exportNeurotronState(neurotron, fptr);
    updateNeurotron(neurotron);
    printNeurotron(neurotron);
    exportNeurotronState(neurotron, fptr);
    neurotron->values[2] = true;
    neurotron->values[4] = true;
    neurotron->values[7] = true;

    start_time = clock();
    for (int i = 0; i < 10000000; i++)
    {
        updateNeurotron(neurotron);
    }
    fclose(fptr);
    end_time = clock();
    printf("Elapsed time: %.2f seconds\n\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    printNeurotron(neurotron);
    free(neurotron);


    return 0;
}