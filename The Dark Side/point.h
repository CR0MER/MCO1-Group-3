// point.h
// Point structure and utility functions for convex hull
// Programmers: <Your Names>
#ifndef POINT_H
#define POINT_H

typedef struct {
    double x, y;
} Point;

// Returns >0 for CCW, <0 for CW, 0 for collinear
static inline double cross(const Point *O, const Point *A, const Point *B) {
    return (A->x - O->x) * (B->y - O->y) - (A->y - O->y) * (B->x - O->x);
}

#endif // POINT_H
