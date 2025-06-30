// main1.c
// Driver for Graham scan with slow sort
// Programmers: <Your Names>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "point.h"
#include "graham_scan1.h"

int main() {
    char in_file[256], out_file[256];
    printf("Enter input filename: ");
    scanf("%255s", in_file);
    printf("Enter output filename: ");
    scanf("%255s", out_file);
    FILE *fin = fopen(in_file, "r");
    if (!fin) { printf("Error opening input file\n"); return 1; }
    int n;
    fscanf(fin, "%d", &n);
    Point *pts = malloc(n * sizeof(Point));
    for (int i = 0; i < n; ++i) fscanf(fin, "%lf %lf", &pts[i].x, &pts[i].y);
    fclose(fin);
    int *hull = malloc(n * sizeof(int));
    int hull_size = 0;
    clock_t start = clock();
    graham_scan1(pts, n, hull, &hull_size);
    clock_t end = clock();
    double elapsed = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Elapsed time: %.3f ms\n", elapsed);
    FILE *fout = fopen(out_file, "w");
    fprintf(fout, "%d\n", hull_size);
    for (int i = 0; i < hull_size; ++i) fprintf(fout, "% .6f % .6f\n", pts[hull[i]].x, pts[hull[i]].y);
    fclose(fout);
    free(pts); free(hull);
    return 0;
}
