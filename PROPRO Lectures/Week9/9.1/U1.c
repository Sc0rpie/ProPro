#include <stdio.h>
#include <math.h>

typedef struct Point{
    double x, y;
} Point;

//PART B
void printPoint(Point p)
{
    printf("(%.2f,%.2f)\n", p.x, p.y);
}

//PART C
Point createPoint(double x, double y) // stores and returns struct type
{
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

//PART D
double getDistance(Point a, Point b)
{
    double dist = sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2));
    return dist;
}

int main()
{
    Point p1, p2;
    double dist;
    // PART A)
    // p1.x = 2.0;
    // p1.y = -3.0;

    // p2.x = -4.0;
    // p2.y = 5.0;

    //PART C
    // p1 = createPoint(2.0, -3.0);
    // p2 = createPoint(-4.0, 5.0);

    //PART B
    printPoint(p1);
    printPoint(p2);

    //PART D
    dist = getDistance(createPoint(2.0, -3.0),createPoint(-4.0, 5.0));
    printf("%.2lf", dist);
    return 0;
}