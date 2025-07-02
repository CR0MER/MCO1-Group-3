#include "stack.c"
#include "sort.c"
#include <math.h> // might need this

// The Anchor is the point with the lowest y-coordinate, and in case of a tie, the point with the lowest x-coordinate.
// returns the index of the anchor in the array pts
int getAnchor(Coord *coords, int n)
{
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (coords[i].y < coords[index].y || (coords[i].y == coords[index].y && coords[i].x < coords[index].x))
        {
            index = i;
        }
    }
    return index;
}

// TODO: Implement the graham scan algorithm using the stack and sort functions
/*
** @param *coords: Array of coordinates
** @param n: Number of coordinates
** @param *hull: Array of coordinates in the convex hull
** @param *hullSize: Size of the hull
*/
void graham1(Coord *coords, int n, Coord *hull, int *hullSize)
{

    // TODO: USE THE BUBBLESORT ALGORITHM TO SORT THE COORDINATES BASED ON THEIR ANGLE RELATIVE TO THE ANCHOR
}