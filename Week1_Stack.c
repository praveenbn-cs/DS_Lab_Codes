// Week - 1 Stack Program (PUSH, POP, DISPLAY)

#include <stdio.h>
#define MAX 5  // Maximum number of elements in the stack

int stack[MAX];
int top = -1;  // Initially, the stack is empty

// Function to add an element to the stack
void push()
{
    int item;

    // Check if the stack is full
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        printf("Enter element to push: ");
        scanf("%d", &item);

        top++;  // Move top to the next position
        stack[top] = item;

        printf("Element pushed successfully.\n");
    }
}

// Function to remove the top element from the stack
void pop()
{
    // Check if the stack is empty
    if (top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("Popped element: %d\n", stack[top]);
        top--;  // Move top down by one position
    }
}

// Function to display the stack elements
void display()
{
    int i;

    // Check whether the stack contains any elements
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements are:\n");

        // Display elements from top to bottom
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

// Main function to run the stack operations
int main()
{
    int choice;

    // Keep displaying the menu until the user exits
    while (1)
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the operation selected by the user
        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
