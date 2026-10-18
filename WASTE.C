#include <stdio.h>
#define MAX 5  // Maximum number of elements in the queue

int queue[MAX];
int front = -1, rear = -1;  // Initially, the queue is empty


void insert()
{
    int item;

    // Check whether the circular queue is full
    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enter the element: ");
        scanf("%d", &item);
