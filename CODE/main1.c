/*
 Programmer: Bien Aouien Miranda, Darryl Matthew Esguerra
 Tester: Darryl Mattthew Esguerra, Keifer Sy
*/

#include <stdio.h>
#include <time.h>
#include "stack.h"
#include "coord.h"
#include "graham_scan1.h"

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

    input = fopen(inputFile, "r");

    if (input != NULL)
    {
        if (fscanf(input, "%d", &n) == 1) // Read the number of coordinates
            for (int i = 0; i < n; i++)
                fscanf(input, "%lf %lf", &coords[i].x, &coords[i].y);
    }
    else
        fprintf(stdout, "Failed to read data from %s!", inputFile);

    printf("Enter name of output file: ");
    scanf("%s", outputFile);

    start = clock();
    graham1(coords, n, hull, &hullSize); // Call the Graham Scan function (you need to implement this function in graham_scan1.c)
    end = clock();

    printf("Time Elapsed(in milliseconds): %.3lfms\n", (double)(end - start) * 1000.0 / CLOCKS_PER_SEC);

    output = fopen(outputFile, "w");
    if (output != NULL)
    {
        fprintf(output, "%d\n", hullSize); // print out the hull size
        for (int i = 0; i < hullSize; i++)
            fprintf(output, "%.6lf %.6lf\n", hull[i].x, hull[i].y); // print x and y coordinates of the hull point coordiantes
        fclose(output);
    }
    else
    {
        fprintf(stdout, "Failed to write data to %s!\n", outputFile);
    }

    return 0;
}
