// graham_scan1.c
// Graham scan using slow sort (bubble sort)
// Programmers: <Your Names>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"
#include "stack.h"
#include "sort.h"
#include "graham_scan1.h"

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
static double polar_angle(const Point *a) {
    return atan2(a->y - anchor.y, a->x - anchor.x);
}
static int cmp_angle_idx(const void *a, const void *b, void *pts_v) {
    Point *pts = (Point*)pts_v;
    int i = *(int*)a, j = *(int*)b;
    double c = cross(&anchor, &pts[i], &pts[j]);
    if (fabs(c) < 1e-9) {
        double da = (pts[i].x - anchor.x)*(pts[i].x - anchor.x) + (pts[i].y - anchor.y)*(pts[i].y - anchor.y);
        double db = (pts[j].x - anchor.x)*(pts[j].x - anchor.x) + (pts[j].y - anchor.y)*(pts[j].y - anchor.y);
        return (da < db) ? -1 : 1;
    }
    return (c > 0) ? -1 : 1;
}

// Bubble sort indices by polar angle
static void bubble_sort_indices(int *idx, int n, Point *pts) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (cmp_angle_idx(&idx[j], &idx[j+1], pts) > 0) {
                int t = idx[j]; idx[j] = idx[j+1]; idx[j+1] = t;
            }
        }
    }
}

void graham_scan1(Point *pts, int n, int *hull, int *hull_size) {
    int idx[n];
    int anchor_idx = find_anchor(pts, n);
    anchor = pts[anchor_idx];
    // Build index array (skip anchor)
    int k = 0;
    for (int i = 0; i < n; ++i) if (i != anchor_idx) idx[k++] = i;
    // Bubble sort by polar angle
    bubble_sort_indices(idx, n-1, pts);
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
