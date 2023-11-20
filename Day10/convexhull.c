#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a structure to represent a point (x, y)
struct Point {
    int x, y;
};

// Function to find the orientation of three points (p, q, r)
int orientation(struct Point p, struct Point q, struct Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or counterclockwise
}

// Function to swap two points
void swap(struct Point *a, struct Point *b) {
    struct Point temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array of points based on polar angle
// with respect to the first point (the point with the lowest y-coordinate)
void sortPoints(struct Point points[], int n) {
    int i, j, minIndex;
    for (i = 1; i < n; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (points[j].y < points[minIndex].y ||
                (points[j].y == points[minIndex].y && points[j].x < points[minIndex].x))
                minIndex = j;
        }
        swap(&points[i], &points[minIndex]);
    }
    // Sort points based on polar angle with the first point
    // We use a bubble sort since it's simple and works well for this case
    for (i = 2; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (orientation(points[1], points[i], points[j]) == 1)
                swap(&points[i], &points[j]);
        }
    }
}

// Function to compute the convex hull using the Graham Scan algorithm
void grahamScan(struct Point points[], int n) {
    if (n < 3) {
        printf("Convex hull not possible with less than 3 points.\n");
        return;
    }

    // Find the point with the lowest y-coordinate (and leftmost in case of a tie)
    int i, minY = points[0].y, minIndex = 0;
    for (i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < minY) || (y == minY && points[i].x < points[minIndex].x)) {
            minY = y;
            minIndex = i;
        }
    }

    // Swap the lowest point with the first point
    swap(&points[0], &points[minIndex]);

    // Sort the remaining points based on polar angle with the first point
    sortPoints(points, n);

    // Initialize the convex hull with the first three points
    struct Point hull[n];
    int m = 0;
    hull[m++] = points[0];
    hull[m++] = points[1];
    hull[m++] = points[2];

    // Process the remaining points
    for (i = 3; i < n; i++) {
        while (m > 1 && orientation(hull[m - 2], hull[m - 1], points[i]) != 2)
            m--;
        hull[m++] = points[i];
    }

    // Print the convex hull points
    printf("Convex Hull Points (Graham Scan):\n");
    for (i = 0; i < m; i++) {
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
    }
}

// Function to compute the convex hull using the Jarvis March (Gift Wrapping) algorithm
void jarvisMarch(struct Point points[], int n) {
    if (n < 3) {
        printf("Convex hull not possible with less than 3 points.\n");
        return;
    }

    // Find the point with the lowest y-coordinate (and leftmost in case of a tie)
    int i, minY = points[0].y, minIndex = 0;
    for (i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < minY) || (y == minY && points[i].x < points[minIndex].x)) {
            minY = y;
            minIndex = i;
        }
    }

    // Start from the point with the lowest y-coordinate
    int p = minIndex;
    int q;
    struct Point hull[n];
    int m = 0;

    do {
        // Add the current point to the convex hull
        hull[m++] = points[p];

        // Initialize the next point to be the first point not in the convex hull
        q = (p + 1) % n;
        for (i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }

        p = q;
    } while (p != minIndex);

    // Print the convex hull points
    printf("Convex Hull Points (Jarvis March):\n");
    for (i = 0; i < m; i++) {
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
    }
}

int main() {
    int n, i;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    if (n < 3) {
        printf("Convex hull not possible with less than 3 points.\n");
        return 0;
    }

    struct Point points[n];

    for (i = 0; i < n; i++) {
        printf("Enter x and y coordinates of point %d: ", i + 1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    grahamScan(points, n);
    printf("\n");
    jarvisMarch(points, n);

    return 0;
}
