#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point
{
    double x, y;
} Point;

typedef struct Stack
{ // A)
    Point *data;
    int size;
} Stack;

void printPoint(Point p)
{
    printf("(%.2f,%.2f)\n", p.x, p.y);
}

Point createPoint(double x, double y) // stores and returns struct type
{
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

// PART D
double getDistance(Point a, Point b)
{
    double dist = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    return dist;
}

void initStack(Stack *stack) // B) Stack INIT
{
    stack->size = 0;
    stack->data = NULL;
}

void printStack(Stack *stack) // C)
{
    if (stack->data != NULL)
    {
        for (int i = 0; i < stack->size; i++)
        {
            printf("Distance: ");
            printPoint(stack->data[i]);
            printf(" to (0,0) is: %lf\n", getDistance(createPoint(0.0, 0.0), stack->data[i]));
        }
        printf("\n");
    }
}

void printPoints(Stack *stack)
{
    for (int i = 0; i < stack->size; i++)
    {
        printPoint(stack->data[i]);
    }
    
}

int getStackSize(Stack *stack)
{
    return stack->size;
}

void push(Stack *stack, Point value)
{
    if (stack->size == 0)
    {
        stack->data = malloc(sizeof(stack->data));
        stack->data[0] = value;
        stack->size++;
    }
    else
    {
        stack->data = realloc(stack->data, (stack->size+1)*sizeof(Point));
        stack->data[stack->size] = value;
        stack->size++;
    }
}

Point top(Stack *stack)
{
    if (stack->data == NULL)
        return createPoint(0.0, 0.0);
    else
        return stack->data[stack->size-1];
}

Point pop(Stack *stack)
{
    Point tp = top(stack);
    stack->data = realloc(stack->data, stack->size - 1);
    stack->size--;
    return tp;
}

void destroyStack(Stack *stack)
{
    free(stack->data);
    stack->size = 0;
}

int main()
{
    Stack *stack = malloc(sizeof(Stack*));

    initStack(stack);
    push(stack, createPoint(1.0,1.0));
    push(stack, createPoint(2.5,2.5));
    push(stack, createPoint(1.24,4.23));
    printStack(stack);
    // printPoints(stack);

    return 0;
}