// Implementation of Linear Queue Using Array

#include <stdio.h>
#define MAX 5  // Maximum size of the queue

int queue[MAX];
int front = -1, rear = -1;  // Queue starts empty

// Function to add an element to the queue
void insert()
{
    int item;

    // Check if the queue has reached its last position
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enter the element to insert: ");
        scanf("%d", &item);

        // Set front when inserting the first element
        if (front == -1)
            front = 0;

        rear++;  // Move rear to the next position
        queue[rear] = item;

        printf("Element inserted successfully\n");
    }
}

// Function to remove an element from the queue
void delete()
{
    // Check if the queue is empty
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);

        // Reset both pointers when the last element is removed
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;  // Move front to the next element
        }
    }
}

// Function to print all elements in the queue
void display()
{
    int i;

    // Check if there are any elements to display
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are: ");

        // Print elements from front to rear
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    // Show the menu repeatedly until the user exits
    while (1)
    {
        printf("\n--- LINEAR QUEUE OPERATIONS ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Run the operation chosen by the user
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
