#include <stdio.h>
#include <stdlib.h>

typedef struct Stack // A)
{
    int *ptr;
    int size;
} Stack;

void initStack(Stack *stack) // B) Stack INIT
{
    stack->size = 0;
    stack->ptr = NULL;
}

void printStack(Stack *stack) // C)
{
    if (stack->ptr != NULL)
    {
        for (int i = 0; i < stack->size; ++i)
        {
            printf("Stack index: %d || Value: %d\n", i, stack->ptr[i]);
        }
        printf("\n");
    }
}

int getStackSize(Stack *stack) // D)
{
    return stack->size;
}

void push(Stack *stack, int value) // E)
{
    if (stack->size == 0)
    {
        stack->ptr = malloc(sizeof(stack->ptr));
        stack->ptr[0] = value;
        stack->size++;
    }
    else
    {
        stack->ptr = realloc(stack->ptr, stack->size+1);
        stack->ptr[stack->size] = value;
        stack->size++;
    }
}

int top(Stack *stack) // F)
{
    if (stack->ptr == NULL)
        return 0;
    else
        return stack->ptr[stack->size-1];
}

int pop(Stack *stack) // G)
{
    int tp = top(stack);
    stack->ptr = realloc(stack->ptr, stack->size-1);
    stack->size--;
    return tp;
}

void destroyStack(Stack *stack) // J
{
    free(stack->ptr);
    stack->size = 0;
}

int main()
{
    Stack *stack = malloc(sizeof(Stack*));

    initStack(stack);
    push(stack, 10);
    printStack(stack);
    push(stack, 234);
    printf("Size %d\n", getStackSize(stack));
    printf("Top %d\n", top(stack));
    push(stack, 10000);
    printf("Pop %d\n", pop(stack));
    printStack(stack);
    destroyStack(stack);
    printf("%d", top(stack));
    return 0;
}