/*
 Programmer: Bien Aouien Miranda,  Keifer Sy
 Tester: Darryl Mattthew Esguerra, Bien Aouien Miranda
*/

#include "stack.h"
#include "sort.h"

// The Anchor is the point with the lowest y-coordinate, and in case of a tie, the point with the lowest x-coordinate.
// returns the index of the anchor in the array pts
int getAnchor(Coord *coords, int n)
{
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        // if the current point is lower than the current anchor, or they are the same y coordinate but x coordinate is lower
        if (coords[i].y < coords[index].y || (coords[i].y == coords[index].y && coords[i].x < coords[index].x))
        {
            index = i;
        }
    }
    return index;
}

/*
** @param *coords: Array of coordinates
** @param n: Number of coordinates
** @param *hull: Array of coordinates in the convex hull
** @param *hullSize: Size of the hull
*/
void graham2(Coord *coords, int n, Coord *hull, int *hullSize)
{
    // Get the lowest point
    int index = getAnchor(coords, n);

    // swap the anchor with the first coordinate
    Coord temp = coords[0];
    coords[0] = coords[index];
    coords[index] = temp;
    Coord anchor = coords[0];

    // use the bubble sort algorithm
    quickSort(coords, 0, n - 1, anchor);

    // initialize the stack then push the first 3 points o
    Stack s;
    CREATE(&s);
    PUSH(&s, coords[0]);
    PUSH(&s, coords[1]);
    PUSH(&s, coords[2]);

    // go through the rest of the coordinates
    for (int i = 3; i < n; i++)
    {
        // While the last two points in the stack does not make a left turn
        while (s.top >= 1 && getDirection(NEXT_TO_TOP(&s), TOP(&s), coords[i]) != 2)
            POP(&s);
        PUSH(&s, coords[i]); // add curent coord to the stack
    }
    // Set hull size to the number of points in the stack
    *hullSize = s.top + 1;
    // pop all the points in the stack and then put them into the hull array
    for (int i = s.top; i >= 0; i--)
        hull[i] = POP(&s);
}