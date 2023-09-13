/*#include "SDL.h"
#include "SDL2/SDL.h"
#define WIDTH 400
#define HEIGHT 900
#define NEURONSIZE (HEIGHT / 40)
SDL_Window *screen = NULL;
SDL_Renderer *renderer;
SDL_Event event;
SDL_Rect source, destination, dst;

void drawRectangle(SDL_Renderer *renderer, unsigned short x, unsigned short y, unsigned short r, unsigned short g, unsigned short b)
{

    SDL_Rect rect;
    rect.h = NEURONSIZE;
    rect.w = NEURONSIZE;
    rect.x = x;
    rect.y = y;
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderFillRect(renderer, &rect);
}

typedef struct
{
    int *x, *y;
} NeurotronCoordinates;

Coordinate neuronToPosition(Neurotron *neurotron, int neuron_index)
{
    Coordinate coordinate;
    int w = WIDTH / NEURONSIZE - 2;
    int h = HEIGHT / NEURONSIZE - 2;
    coordinate.x = neuron_index % (w);
    coordinate.y = neuron_index / w;
    coordinate.x += HEIGHT / 10;
    coordinate.y += NEURONSIZE;
    return coordinate;
}

NeurotronCoordinates *setupCoordinates(Neurotron *neurotron)
{
    NeurotronCoordinates *coordinates;
    coordinates = malloc(sizeof(NeurotronCoordinates));
    coordinates->x = (int *)malloc(neurotron->neuron_count * sizeof(int));
    coordinates->y = (int *)malloc(neurotron->neuron_count * sizeof(int));
    const int eyeOffset = WIDTH / (2 * neurotron->eyes_count) - NEURONSIZE / 2;
    for (int i = 0; i < neurotron->eyes_count; i++)
    {
        coordinates->x[i] = i * WIDTH / neurotron->eyes_count + eyeOffset;
        coordinates->y[i] = HEIGHT / 20;
    }
    for (int i = 0; i < neurotron->deep_count; i++)
    {
        int w = (WIDTH - (NEURONSIZE * 2)) / NEURONSIZE;
        int h = (HEIGHT - (HEIGHT / 5)) / (neurotron->deep_count / w);
        coordinates->x[i + neurotron->eyes_count] = i % w * NEURONSIZE + NEURONSIZE;
        coordinates->y[i + neurotron->eyes_count] = i / w * h + (HEIGHT / 10);
    }
    const int handOffset = WIDTH / (2 * neurotron->hands_count) - NEURONSIZE / 2;
    for (int i = 0; i < neurotron->hands_count; i++)
    {
        coordinates->x[i + neurotron->eyes_count + neurotron->deep_count] = i * WIDTH / neurotron->hands_count + handOffset;
        coordinates->y[i + neurotron->eyes_count + neurotron->deep_count] = HEIGHT - HEIGHT / 20;
    }
    return coordinates;
}

void drawNeurotron(SDL_Renderer *renderer, Neurotron *neurotron, NeurotronCoordinates *coordinates)
{
    for (int i = 0; i < neurotron->eyes_count; i++)
    {
        drawRectangle(renderer, coordinates->x[i], coordinates->y[i], 0, 0, 95 + (neurotron->values[i] * 160));
    }
    for (int i = 0; i < neurotron->deep_count; i++)
    {
        drawRectangle(renderer, coordinates->x[i + neurotron->eyes_count], coordinates->y[i + neurotron->eyes_count], 0, 95 + (neurotron->values[neurotron->eyes_count + i] * 160), 0);
    }
    for (int i = 0; i < neurotron->hands_count; i++)
    {
        drawRectangle(renderer, coordinates->x[i + neurotron->eyes_count + neurotron->deep_count], coordinates->y[i + neurotron->eyes_count + neurotron->deep_count], 95 + (neurotron->values[neurotron->eyes_count + neurotron->deep_count + i] * 160), 0, 0);
    }
}
*/

    /*
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_WINDOW_SHOWN, &screen, &renderer);
    if (!screen)
    {
        printf("InitSetup failed to create window\n");
    }
    SDL_SetWindowTitle(screen, "fuck");
    */

       /*
    NeurotronCoordinates *coordinates = setupCoordinates(neurotron);
    drawNeurotron(renderer, neurotron, coordinates);
    free(coordinates->x);
    free(coordinates->y);
    free(coordinates);
    SDL_RenderPresent(renderer);
*/

    /*
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(screen);
    // Quit SDL
    SDL_Quit();
    exit(0);
    */