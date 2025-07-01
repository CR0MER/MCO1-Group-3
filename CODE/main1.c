#include <stdio.h>
#include <time.h>
#include "stack.h"
#include "graham_scan1.c"

// Main1.c does the Graham Scan algorithm using Bubble Sort

int main()
{
    // Initialization
    char inputFile[100];
    char outputFile[100];
    Coord coords[MAX_COORDS]; // Holds the coordinates
    Coord hull[MAX_COORDS];   // Holds the coords in the convex hull
    FILE *input, *output;
    int n, hullSize; // n is the # of coordinates, hullSize is the # of coordinates in the hull
    clock_t start, end;

    printf("Enter name of input file: ");
    scanf("%s", inputFile);

    // TODO: Open the input file and read the number of coordinates

    printf("Enter name of output file: ");
    scanf("%s", outputFile);

    start = clock();
    graham1(coords, n, hull, &hullSize); // Call the Graham Scan function (you need to implement this function in graham_scan1.c)
    end = clock();

    // TODO: Write the output to the output file

    return 0;
}
