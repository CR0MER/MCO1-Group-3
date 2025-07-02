#ifndef GRAHAM_SCAN1_H
#define GRAHAM_SCAN1_H

#include "coord.h"

int getAnchor(Coord *coords, int n);
void graham1(Coord *coords, int n, Coord *hull, int *hullSize);

#endif