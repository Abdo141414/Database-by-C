#include "SDB.h"







void SDB_action(uint8 choice)
{
    switch (choice)
    {
    case 1:
        if (SDB_AddEntry())
            printf("student is added successfully\n");
        else
            printf("failed to add student\n");
        break;
    case 2:
        printf("number of students = %d\n",SDB_GetUsedSize());
        break;
    case 3:
        if (SDB_ReadEntry()==0)
            printf("there is no student with this ID\n");
        break;
    case 4:
        SDB_GetList();
        break;
    case 5:
        if (SDB_IsidExist())
            printf("student is found\n");
        else
            printf("student isn't found\n");
        break;
    case 6:
        SDB_DeleteEntry();
        break;
    case 7:
        if (SDB_IsFull())
            printf("list is full\n");
        else
            printf("list isn't full\n");
        break;
    default:
        printf("option isn't found\n");

    }
}
void SDB_APP()
{
    uint8 choice;
    while (1)
    {
        printf("to add entry enter 1\nto get used size in data base enter 2\nto read student data enter 3\nto get the list of all students IDs enter 4\nto check if ID exists enter 5\nto delete student data enter 6\nto check if data base is full enter 7\nto exit enter 0\n");
        scanf("%d",&choice);
        if (choice ==0)
        {
            printf("program is closed successfully\n ");
            break;
        }
        SDB_action(choice);
    }
}
