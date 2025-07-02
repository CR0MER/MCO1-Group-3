#include <stdio.h>
#include "sort.h"

// Returns the orientation or direction of the three point coordinates
// Returns 2 if Counter Clockwise, 1 if Clockwise, and 0 if Collinear
int getDirection(Coord c1, Coord c2, Coord c3)
{
    double value = (c2.x - c1.x) * (c3.y - c1.y) - (c2.y - c1.y) * (c3.x - c1.x);
    if (value == 0.0)
        return 0; // Collinear
    if (value < 0.0)
        return 1; // Clockwise
    return 2;     // Counter-clockwise
}

// Returns the distance between two coordinates (Used pythagorean theorem)
double getDistance(Coord c1, Coord c2)
{
    double dx = c1.x - c2.x, dy = c1.y - c2.y;
    return dx * dx + dy * dy; // no need to get the sqrt
}

// Compares two point coordinates based on their angle relative to the anchor
int compareCoords(Coord anchor, Coord c1, Coord c2)
{
    int dir = getDirection(anchor, c1, c2);
    if (dir == 0)                                                 // if Collinear
        return getDistance(anchor, c1) < getDistance(anchor, c2); // returns 1 if c1 is closer to anchor than c2

    // if not Collinear
    return dir == 2; // returns 1 if orientation is counter clockwise, else 0
}

void bubbleSort(Coord *coords, int n, Coord anchor)
{
    int i, j;
    Coord temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (compareCoords(anchor, coords[j], coords[j + 1]) > 0) // if the coordinates are not collinear
            {
                // Swap
                temp = coords[j];
                coords[j] = coords[j + 1];
                coords[j + 1] = temp;
            }
        }
    }
}

void quickSort(Coord *coords, int left, int right, Coord anchor)
{
    if (left >= right)
        return; // if theres one or no elements left

    Coord pivot = coords[(left + right) / 2]; // get the middle element of coords
    int i = left, j = right;
    Coord temp;
    // Partitioning the coords array to sort
    while (i <= j)
    {
        // Left Scanning
        while (compareCoords(anchor, coords[i], pivot)) // while coords[i] is less than pivot
            i++;                                        // move i to the right
        // Right Scanning
        while (compareCoords(anchor, pivot, coords[j])) // while coords[j] is greater than pivot
            j--;                                        // Move j to the left
        if (i <= j)
        {
            temp = coords[i];
            coords[i] = coords[j];
            coords[j] = temp;
            j--;
            i++;
        }
    }
    if (left < j)
        quickSort(coords, left, j, anchor);
    if (i < right)
        quickSort(coords, i, right, anchor);
}