#include "coord.h"

int getDirection(Coord c1, Coord c2, Coord c3);
int compareCoords(Coord anchor, Coord c1, Coord c2);
void bubbleSort(Coord *coords, int n, Coord anchor);
void quickSort(Coord *coords, int low, int high, Coord anchor);