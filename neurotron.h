#pragma once
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int neuron_count, eyes_count, deep_count, hands_count, connections_count;
    bool *values;
    size_t *connection_inputs;
    size_t *connection_starts;
    int *connection_amounts;
} Neurotron;

Neurotron *createNeurotron(int eyes_count, int deep_count, int hands_count);

void updateNeurotron(Neurotron *neurotron);

void printNeurotron(Neurotron *neurotron);