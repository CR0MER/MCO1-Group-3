#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

typedef struct {
    double x, y;
} Point;

// Cross product of OA and OB vectors
// Returns >0 for counter-clockwise turn, <0 for clockwise, 0 for collinear
static double cross(const Point O, const Point A, const Point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Sort by y, then x (for Graham scan anchor)
int cmp_anchor(const void *a, const void *b) {
    Point *p = (Point*)a, *q = (Point*)b;
    if (p->y != q->y) return (p->y < q->y) ? -1 : 1;
    if (p->x != q->x) return (p->x < q->x) ? -1 : 1;
    return 0;
}

Point anchor;

// Sort by polar angle with anchor
int cmp_angle(const void *a, const void *b) {
    Point *p = (Point*)a, *q = (Point*)b;
    double c = cross(anchor, *p, *q);
    if (fabs(c) < 1e-9) {
        // If collinear, closer comes first
        double dp = (p->x - anchor.x)*(p->x - anchor.x) + (p->y - anchor.y)*(p->y - anchor.y);
        double dq = (q->x - anchor.x)*(q->x - anchor.x) + (q->y - anchor.y)*(q->y - anchor.y);
        return (dp < dq) ? -1 : 1;
    }
    return (c > 0) ? -1 : 1;
}

int main() {
    int n;
    Point pts[MAX_POINTS];
    if (scanf("%d", &n) != 1 || n < 3) return 1;
    for (int i = 0; i < n; ++i) {
        if (scanf("%lf %lf", &pts[i].x, &pts[i].y) != 2) return 1;
    }
    // Step 1: Find anchor (lowest y, then x)
    int anchor_idx = 0;
    for (int i = 1; i < n; ++i) {
        if (cmp_anchor(&pts[i], &pts[anchor_idx]) < 0) anchor_idx = i;
    }
    // Swap anchor to front
    Point tmp = pts[0]; pts[0] = pts[anchor_idx]; pts[anchor_idx] = tmp;
    anchor = pts[0];
    // Step 2: Sort by angle with anchor
    qsort(pts+1, n-1, sizeof(Point), cmp_angle);
    // Step 3: Graham scan
    Point hull[MAX_POINTS];
    int m = 0;
    for (int i = 0; i < n; ++i) {
        while (m >= 2 && cross(hull[m-2], hull[m-1], pts[i]) <= 0) m--;
        hull[m++] = pts[i];
    }
    // Output
    printf("%d\n", m);
    for (int i = 0; i < m; ++i) {
        printf("% .6f % .6f\n", hull[i].x, hull[i].y);
    }
    return 0;
}