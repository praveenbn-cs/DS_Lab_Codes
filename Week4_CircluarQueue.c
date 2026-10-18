// Circular Queue Using Array

#include <stdio.h>
#define MAX 5  // Maximum number of elements in the queue

int queue[MAX];
int front = -1, rear = -1;  // Initially, the queue is empty

// Function to insert an element into the queue
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

        // Set front and rear for the first element
        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            // Move rear to the next available position
            rear = (rear + 1) % MAX;
        }

        queue[rear] = item;
        printf("Element inserted successfully\n");
    }
}

// Function to delete an element from the queue
void delete()
{
    // Check whether the queue is empty
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);

        // Reset front and rear if the last element is deleted
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            // Move front to the next position
            front = (front + 1) % MAX;
        }
    }
}

// Function to display all elements in the queue
void display()
{
    int i;

    // Display a message if there are no elements
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Circular queue elements: ");

        i = front;

        // Print elements from front up to rear
        while (1)
        {
            printf("%d ", queue[i]);

            // Stop after displaying the last element
            if (i == rear)
                break;

            // Move to the next position in the circular queue
            i = (i + 1) % MAX;
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    // Keep showing the menu until the user exits
    while (1)
    {
        printf("\n--- CIRCULAR QUEUE ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the operation selected by the user
        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
