#include "SDB.h"

struct node
{
    student info;
    struct node *next;
};

struct node *start=NULL;


uint8 SDB_GetUsedSize()
{
    struct node *ptr;
    int i=0;

    ptr=start;
    while (ptr!=NULL)
    {
        ptr=ptr->next;
        i++;
    }
    return i;

}

bool SDB_AddEntry()
{
    struct node *temp,*ptr;
    int i=0;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nOut of Memory Space:\n");
        return;
    }
    ptr=start;
    while (ptr!=NULL)
    {
        ptr=ptr->next;
        i++;
    }

    if(i>=10)
    {
        printf ("sorry it's full\n");


    }


    else
    {
        printf("\nEnter the ID of student:\n" );
        scanf("%d",&temp->info.student_ID );
        printf("Enter student year:\n");
        scanf("%d",&temp->info.student_year );
        printf("Enter course1 ID\n");
        scanf("%d",&temp->info.course1_ID );
        printf("Enter course1 grade\n");
        scanf("%d",&temp->info.course1_grade );
        printf("Enter course2 ID\n");
        scanf("%d",&temp->info.course2_ID );
        printf("Enter course2 grade\n");
        scanf("%d",&temp->info.course2_grade );
        printf("Enter course3 ID\n");
        scanf("%d",&temp->info.course3_ID );
        printf("Enter course3 grade\n");
        scanf("%d",&temp->info.course3_grade );


        temp->next =NULL;

        if(start==NULL)
        {
            start=temp;
        }
        else
        {
            ptr=start;
            while(ptr->next !=NULL)
            {
                ptr=ptr->next ;
            }
            ptr->next =temp;
        }
        return 1;
    }


}

bool SDB_ReadEntry ( )
{
    int flag=0,id;
    struct node *ptr;

    printf("Enter ID: \n");
    scanf("%d",&id);
    ptr=start;
    while(ptr!=NULL)
    {
        if (ptr->info.student_ID==id)
        {
            printf("student ID= %d\nstudent year=%d\ncourse 1 ID=%d\ncourse 1 grade=%d\ncourse 2 ID=%d\ncourse 2 grade=%d\ncourse 3 ID=%d\ncourse 3 grade=%d\n",ptr->info.student_ID,ptr->info.student_year,ptr->info.course1_ID,ptr->info.course1_grade,ptr->info.course2_ID,ptr->info.course2_grade,ptr->info.course3_ID,ptr->info.course3_grade);
            flag=1;
            break;
        }
        ptr=ptr->next;
    }
    if (flag==0)
        return false;
    else
        return true;

}

bool SDB_IsidExist()
{
    struct node *ptr;


    int x, flag=0;
    printf("what's the ID of student you want to check\n");
    scanf("%d",&x);
    ptr=start;
    while (ptr!=NULL)
    {
        if (ptr->info.student_ID==x)
        {
            flag=1;
            break;
        }
        ptr=ptr->next;
    }
    if (flag==1)
        return true;
    else
        return false ;

}

void SDB_DeleteEntry()
{
    int i,id;
    struct node *temp,*ptr;
    if(start==NULL)
    {
        printf("\nThe List is Empty:\n");

    }
    else
    {
        printf("\nEnter the id to be deleted:\t");
        scanf("%d",&id);
        if(start->info.student_ID==id)
        {
            ptr=start;
            start=start->next ;
            printf("\nThe deleted id is:%d\n",ptr->info.student_ID );
            free(ptr);
        }
        else
        {
            ptr=start;
            while(ptr->info.student_ID!=id)
            {
                temp=ptr;
                ptr=ptr->next ;
                if(ptr==NULL)
                {
                    printf("\nid not Found:\n");
                    return;
                }
            }
            temp->next =ptr->next ;
            printf("\nThe deleted id is:%d\n",ptr->info.student_ID );
            free(ptr);
        }
    }
}
void SDB_GetList()
{
    struct node *ptr ;
    int i=1, x=0,arr[10];
    ptr = start ;

    while(ptr!=NULL)
    { for( x; x<i; x++)
        {

            arr[x]=ptr->info.student_ID;
            ptr=ptr->next;
        }

        for(int x; x<i; x++)
        {
            printf("ID[%d]:%d\n",x,arr[x]);

        }
        i++;
    }

printf("the number of IDs in count is %d\n",i-1);

}

bool SDB_IsFull()
{
    struct node *temp,*ptr;
    int flag,i=0;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nOut of Memory Space:\n");
        exit(0);
    }
    ptr=start;
    while (ptr!=NULL)
    {
        ptr=ptr->next;
        i++;
    }
    if (i>=10)
    {
        flag= 1;
    }
    else
    {
        flag=0 ;
    }
    return flag;

}
