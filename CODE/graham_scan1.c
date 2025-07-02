#include "stack.h"
#include "sort.h"

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

/* Trying out javadocs in C
** @param *coords: Array of coordinates
** @param n: Number of coordinates
** @param *hull: Array of coordinates in the convex hull
** @param *hullSize: Size of the hull
*/
void graham1(Coord *coords, int n, Coord *hull, int *hullSize)
{
    // Get the lowest point
    int index = getAnchor(coords, n);

    // swap the anchor with the first coordinate
    Coord temp = coords[0];
    coords[0] = coords[index];
    coords[index] = temp;
    Coord anchor = coords[0];

    // use the bubble sort algorithm
    bubbleSort(coords, n, anchor);

    // initialize the stack then push the first 3 non collinear points
    Stack s;
    CREATE(&s);
    PUSH(&s, coords[0]);
    PUSH(&s, coords[1]);
    PUSH(&s, coords[2]);

    // go through the rest of the coordinates
    for (int i = 3; i < n; i++)
    {
        while (s.top >= 1 && getDirection(NEXT_TO_TOP(&s), TOP(&s), coords[i]) != 2)
            POP(&s);
        PUSH(&s, coords[i]);
    }

    *hullSize = s.top + 1;
    for (int i = s.top; i >= 0; i--)
        hull[i] = POP(&s);
}