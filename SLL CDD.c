#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create()
{
    struct node *newnode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }
}

void deleteFirst()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("First node deleted\n");
}

void deleteSpecified()
{
    struct node *temp, *prev;
    int key;

    printf("Enter element to delete: ");
    scanf("%d", &key);

    temp = head;
    prev = NULL;

    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Element not found\n");
        return;
    }

    if(prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    printf("Specified element deleted\n");
}

void deleteLast()
{
    struct node *temp, *prev;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Last node deleted\n");
}

void display()
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n1.Create\n2.Delete First");
        printf("\n3.Delete Specified");
        printf("\n4.Delete Last");
        printf("\n5.Display\n6.Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: create(); break;
            case 2: deleteFirst(); break;
            case 3: deleteSpecified(); break;
            case 4: deleteLast(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
