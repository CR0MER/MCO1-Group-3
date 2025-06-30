// graham_scan2.c
// Graham scan using fast sort (quicksort)
// Programmers: <Your Names>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"
#include "stack.h"
#include "sort.h"

void graham_scan2(Point *pts, int n, int *hull, int *hull_size);

// Helper: find anchor (lowest y, then x)
static int find_anchor(Point *pts, int n) {
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        if (pts[i].y < pts[idx].y || (fabs(pts[i].y - pts[idx].y) < 1e-9 && pts[i].x < pts[idx].x))
            idx = i;
    }
    return idx;
}

// Helper: compare indices by polar angle
static Point anchor;
static int cmp_angle_idx_qs(const void *a, const void *b) {
    extern Point *pts_g;
    int i = *(int*)a, j = *(int*)b;
    double c = cross(&anchor, &pts_g[i], &pts_g[j]);
    if (fabs(c) < 1e-9) {
        double da = (pts_g[i].x - anchor.x)*(pts_g[i].x - anchor.x) + (pts_g[i].y - anchor.y)*(pts_g[i].y - anchor.y);
        double db = (pts_g[j].x - anchor.x)*(pts_g[j].x - anchor.x) + (pts_g[j].y - anchor.y)*(pts_g[j].y - anchor.y);
        return (da < db) ? -1 : 1;
    }
    return (c > 0) ? -1 : 1;
}
Point *pts_g = NULL;

void graham_scan2(Point *pts, int n, int *hull, int *hull_size) {
    int idx[n];
    int anchor_idx = find_anchor(pts, n);
    anchor = pts[anchor_idx];
    pts_g = pts;
    // Build index array (skip anchor)
    int k = 0;
    for (int i = 0; i < n; ++i) if (i != anchor_idx) idx[k++] = i;
    // Quicksort by polar angle
    qsort(idx, n-1, sizeof(int), cmp_angle_idx_qs);
    // Stack for hull indices
    Stack *S = CREATE();
    PUSH(S, anchor_idx);
    PUSH(S, idx[0]);
    for (int i = 1; i < n-1; ++i) {
        while (S->top >= 1 && cross(&pts[NEXT_TO_TOP(S)], &pts[TOP(S)], &pts[idx[i]]) <= 0) POP(S);
        PUSH(S, idx[i]);
    }
    // Output hull indices
    *hull_size = S->top + 1;
    for (int i = 0; i <= S->top; ++i) hull[i] = S->data[i];
    FREE(S);
}
