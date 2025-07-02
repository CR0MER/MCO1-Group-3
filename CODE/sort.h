#ifndef SORT_H
#define SORT_H

#include "coord.h"

int getDirection(Coord c1, Coord c2, Coord c3);
double getDistance(Coord c1, Coord c2);
int compareCoords(Coord anchor, Coord c1, Coord c2);
void bubbleSort(Coord *coords, int n, Coord anchor);
void quickSort(Coord *coords, int low, int high, Coord anchor);

#endif