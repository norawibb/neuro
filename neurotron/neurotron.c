#include "neurotron.h"
#include "utilities.h"

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

/* This function runs one update for the brain (at the moment)
 * It runs through the neuron list in order, and NANDS their inputs based
 * on the connection arrays.
 */
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
        neurotron->values[i + neurotron->eyes_count] = value;
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
            printf("%ld ", neurotron->connection_inputs[j]);
        }
    }
    printf("\n\n");
}

// Creates an output file to store the states of a neurotron and returns the file pointer
// It also writes initial information to the file: eyes,deep,hands counts and all the connections.
FILE *createNeurotronFile(Neurotron *neurotron, char *filename)
{
    FILE *fptr;

    fptr = fopen(filename, "w");

    //
    fprintf(fptr, "%d,%d,%d\n", neurotron->eyes_count, neurotron->deep_count, neurotron->hands_count);
    for (int i = 0; i < neurotron->deep_count + neurotron->hands_count; i++)
    {
        for (int j = neurotron->connection_starts[i]; j < neurotron->connection_starts[i] + neurotron->connection_amounts[i]; j++)
        {
            fprintf(fptr, "%ld ", neurotron->connection_inputs[j]);
        }
        fprintf(fptr, ",");
    }
    fprintf(fptr,"\n");
    return fptr;
}

// Given an existing neurotron output file pointer,
// this writes a single line to the file, the current neurotron value array
void exportNeurotronState(Neurotron *neurotron, FILE *fptr)
{
    for (int i = 0; i < neurotron->neuron_count; i++)
    {
        fprintf(fptr,"%d", neurotron->values[i]);
    }
    fprintf(fptr,"\n");
}