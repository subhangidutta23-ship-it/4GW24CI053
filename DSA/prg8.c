#include <stdio.h>
#include <stdlib.h>

typedef struct Employee
{
    char SSN[20], Name[50], Dept[30], Designation[30], PhNo[15];
    float Sal;
    struct Employee *prev, *next;
} Employee;

Employee *head = NULL;

Employee *createNode()
{
    Employee *newNode = (Employee *)malloc(sizeof(Employee));

    printf("SSN Name Dept Designation Salary Phone:\n");
    scanf("%s %s %s %s %f %s",
          newNode->SSN, newNode->Name, newNode->Dept,
          newNode->Designation, &newNode->Sal, newNode->PhNo);

    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertEnd(Employee *newNode)
{
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Employee *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertFront(Employee *newNode)
{
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void deleteEnd()
{
    if (head == NULL)
        return;

    Employee *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

void deleteFront()
{
    if (head == NULL)
        return;

    Employee *temp = head;
    head = head->next;

    if (head)
        head->prev = NULL;

    free(temp);
}

void display()
{
    Employee *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        printf("SSN:%s Name:%s Dept:%s Desig:%s Salary:%.2f Phone:%s\n",
               temp->SSN, temp->Name, temp->Dept,
               temp->Designation, temp->Sal, temp->PhNo);
        temp = temp->next;
        count++;
    }
    printf("Total Employees = %d\n", count);
}

int main()
{
    int choice, n;

    while (1)
    {
        printf("\n1.Create 2.Display 3.Insert End 4.Delete End 5.Insert Front 6.Delete Front 7.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of employees: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
                insertEnd(createNode());
            break;
        case 2:
            display();
            break;
        case 3:
            insertEnd(createNode());
            break;
        case 4:
            deleteEnd();
            break;
        case 5:
            insertFront(createNode());
            break;
        case 6:
            deleteFront();
            break;
        case 7:
            exit(0);
        }
    }
}
