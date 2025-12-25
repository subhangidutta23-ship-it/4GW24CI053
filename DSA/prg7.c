#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char usn[20];
    char name[30];
    char programme[20];
    int sem;
    char phno[15];
    struct Student *next;
};

struct Student *head = NULL;

struct Student *createNode()
{
    struct Student *newNode = (struct Student *)malloc(sizeof(struct Student));

    printf("USN: ");
    scanf("%s", newNode->usn);
    printf("Name: ");
    scanf("%s", newNode->name);
    printf("Programme: ");
    scanf("%s", newNode->programme);
    printf("Semester: ");
    scanf("%d", &newNode->sem);
    printf("Phone No: ");
    scanf("%s", newNode->phno);

    newNode->next = NULL;
    return newNode;
}

void createList(int n)
{
    for (int i = 0; i < n; i++)
    {
        struct Student *newNode = createNode();
        newNode->next = head;
        head = newNode;
    }
}

void displayList()
{
    struct Student *temp = head;
    int count = 0;

    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL)
    {
        printf("USN: %s, Name: %s, Programme: %s, Sem: %d, PhNo: %s\n",
               temp->usn, temp->name, temp->programme, temp->sem, temp->phno);
        temp = temp->next;
        count++;
    }
    printf("Total students = %d\n", count);
}

void insertEnd()
{
    struct Student *newNode = createNode();

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Student *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void deleteEnd()
{
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    struct Student *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

void deleteFront()
{
    if (head == NULL)
        return;

    struct Student *temp = head;
    head = head->next;
    free(temp);
}

int main()
{
    int choice, n;

    while (1)
    {
        printf("\n1.Create  2.Display  3.Insert End  4.Delete End  5.Delete Front  6.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of students: ");
            scanf("%d", &n);
            createList(n);
            break;
        case 2:
            displayList();
            break;
        case 3:
            insertEnd();
            break;
        case 4:
            deleteEnd();
            break;
        case 5:
            deleteFront();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
