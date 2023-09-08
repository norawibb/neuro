// Jinora

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct
{
    int neuron_count, eyes_count, deep_count, hands_count, connections_count;
    bool *values;
    size_t *connection_inputs;
    size_t *connection_starts;
    int *connection_amounts;
} Neurotron;

int randRange(int min, int max)
{
    return (rand() % (max - min)) + min;
}

/* Neurotron first-time generation function
 * This generates a very simple brain, each neuron with only one random connection.
 * The neurons are stored in the order: eyes -> deep -> hands
 */
Neurotron *createNeurotron(int eyes_count, int deep_count, int hands_count)
{
    Neurotron *neurotron = malloc(sizeof(Neurotron));
    if (neurotron == NULL)
    {
        printf(" == ERROR: FAILED TO MALLOC NEUROTRON == \n");
        return NULL;
    }
    neurotron->eyes_count = eyes_count;
    neurotron->deep_count = deep_count;
    neurotron->hands_count = hands_count;
    neurotron->connections_count = deep_count + hands_count; // MAY CHANGE
    neurotron->neuron_count = eyes_count + deep_count + hands_count;

    neurotron->values = (bool *)malloc(neurotron->neuron_count * sizeof(bool));
    neurotron->connection_inputs = (size_t *)malloc(neurotron->connections_count * sizeof(size_t));
    neurotron->connection_starts = (size_t *)malloc(neurotron->connections_count * sizeof(size_t));
    neurotron->connection_amounts = (int *)malloc(neurotron->connections_count * sizeof(int));
    if (neurotron->values == NULL || neurotron->connection_inputs == NULL || neurotron->connection_starts == NULL || neurotron->connection_amounts == NULL)
    {
        printf(" == ERROR: FAILED TO MALLOC NEUROTRON ARRAYS == \n");
        free(neurotron->values);
        free(neurotron->connection_inputs);
        free(neurotron->connection_starts);
        free(neurotron->connection_amounts);
        return NULL;
    }

    for (int i = 0; i < neurotron->neuron_count; i++)
    {
        neurotron->values[i] = false;
    }

    for (int i = 0; i < deep_count + hands_count; i++)
    {
        neurotron->connection_inputs[i] = randRange(0, eyes_count + deep_count);
        neurotron->connection_starts[i] = i;
        neurotron->connection_amounts[i] = 1;
    }
    return neurotron;
}

void updateNeurotron(Neurotron *neurotron)
{
    // TODO: eyes will update here (maybe)

    bool value = false;
    // loop through connection starts
    for (int i = 0; i < neurotron->deep_count + neurotron->hands_count; i++)
    {
        // loop through that connection
        for (int j = neurotron->connection_starts[i]; j < neurotron->connection_starts[i] + neurotron->connection_amounts[i]; j++)
        {
            if (value == true)
            {
                continue;
            }
            if (neurotron->values[neurotron->connection_inputs[j]] == false)
            {
                value = true;
            }
        }
        neurotron->values[i+neurotron->eyes_count] = value;
        value = false;
    }
}

// Prints values of neurotron data
// Connections are printed with eyes (E) first, then the input value indices grouped between commas
void printNeurotron(Neurotron *neurotron)
{
    printf("Neuron counts: %d eyes, %d deep, %d hands, %d total\n", neurotron->eyes_count, neurotron->deep_count, neurotron->hands_count, neurotron->neuron_count);
    printf("Values: ");
    for (int i = 0; i < neurotron->neuron_count; i++)
    {
        printf("%d ", neurotron->values[i]);
    }
    printf("\nConnections: ");
    for (int i = 0; i < neurotron->eyes_count; i++)
    {
        printf("e ");
    }
    for (int i = 0; i < neurotron->deep_count + neurotron->hands_count; i++)
    {
        printf(", ");
        for (int j = neurotron->connection_starts[i]; j < neurotron->connection_starts[i] + neurotron->connection_amounts[i]; j++)
        {
            printf("%d ", neurotron->connection_inputs[j]);
        }
    }
    printf("\n\n");
}

int main(int, char **)
{
    printf("\n--<< Welcome to Neuro >>--\n\n");
    srand(time(NULL));
    clock_t start_time, end_time;
    Neurotron *neurotron = createNeurotron(8, 17, 5);
    printNeurotron(neurotron);
    //start_time = clock();
    //end_time = clock();
    //printf("Elapsed time: %.2f seconds\n\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    updateNeurotron(neurotron);
    printNeurotron(neurotron);
    updateNeurotron(neurotron);
    printNeurotron(neurotron);
    updateNeurotron(neurotron);
    printNeurotron(neurotron);
    start_time = clock();
    for (int i=0; i<10000000; i++) {
        updateNeurotron(neurotron);
    }
    end_time = clock();
    printf("Elapsed time: %.2f seconds\n\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    printNeurotron(neurotron);
    free(neurotron);
    return 0;
}
