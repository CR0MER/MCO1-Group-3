#ifndef GRAHAM_SCAN2_H
#define GRAHAM_SCAN2_H

#include "coord.h"

int getAnchor(Coord *coords, int n);
void graham2(Coord *coords, int n, Coord *hull, int *hullSize);

#endif