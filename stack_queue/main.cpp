#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

typedef struct Student
{
    char name[30];
    int ra;

    Student *next;
};

typedef struct Control
{
    Student *startFlag;
    Student *endFlag;
};

Student *newStudent()
{
    Student *student;
    student = (Student*)malloc(sizeof(Student));

    if (student == NULL)
    {
        printf("\nWithout memory");
    }
    else
    {
        printf("\nInsert ra: ");
        scanf("%d", &student->ra);

        printf("Insert name: ");
        fflush(stdin);
        gets(student->name);
    }
}

Control *insertionQueue(Control *control)
{
    Student *student;
    student = newStudent();

    student->next = NULL;

    if(control->startFlag == NULL)
    {
        control->startFlag = student;
        control->endFlag = student;
    }
    else
    {
        control->endFlag->next = student;
        control->endFlag = student;
    }

    return control;
}

Control *insertionStack(Control *control)
{
    Student *student;
    student = newStudent();

    student->next = NULL;

    if(control->startFlag == NULL)
    {
        control->startFlag = student;
        control->endFlag = student;
    }
    else
    {
        control->startFlag->next = student;
        control->startFlag = student;
    }

    return control;
}

Control *transferToQueue(Control *control)
{

}

Control *transferToStack(Control *control)
{
    if(control->startFlag == NULL)
        printf("\nEmpty list");
    else
    {
        char isTheFirstTime = 'Y';
        char isTimeToStop = 'N';
        Student *aux;
        control->endFlag = control->startFlag;

        do
        {
            aux = control->startFlag;

            if(control->startFlag->next != NULL)
                control->startFlag = control->startFlag->next;
            else
                isTimeToStop = 'Y';

            if(isTheFirstTime == 'Y')
                aux->next = NULL;

            control->startFlag->next = aux;
            isTheFirstTime = 'N';
        }
        while(isTimeToStop != 'Y');
    }

    return control;
}

Control *decideTransfer(Control *control, char *pointerToMethod)
{
    printf("\nQ- Queue");
    printf("\nS- Stack\n");

    char aux;

    fflush(stdin);
    aux = toupper(getche());

    if(*pointerToMethod == aux)
        printf("\n\tYou are already using this method\n");
    else
    {
        *pointerToMethod = aux;

        if(aux == 'Q')
            return transferToQueue(control);
        else
            return transferToStack(control);
    }
}

void listation(Student *aux)
{
    if(aux == NULL)
    {
        printf("\n\nEmpty list");
    }
    else
    {
        do
        {
            printf("\nRA: %d", aux->ra);
            printf("\nName: %s", aux->name);
            printf("\nNext: %s\n", aux->next);

            aux = aux->next;
        }
        while(aux != NULL);
    }
}

Control *deletion(Control *control)
{
    if(control->startFlag == NULL)
    {
        printf("\n\nEmpty list");
    }
    else
    {
        Student *aux;

        aux = control->startFlag->next;
        free(control->startFlag);
        control->startFlag = aux;
    }

    return control;
}

Control *emptyList(Control *control)
{
    while(control->startFlag != NULL)
        control = deletion(control);

    return control;
}

int main()
{
    char option;
    char insertMethod = 'Q';
    Control *control;
    char *pointerInsertMethod = &insertMethod;

    control = (Control*)malloc(sizeof(Control));

    if(control == NULL)
    {
        printf("\n\nWithout memory");
        return 1;
    }
    else
    {
        control->startFlag = NULL;

        do
        {
            printf("\n\nInsertion Method: %c", insertMethod);
            printf("\nA- insert");
            printf("\nB- list");
            printf("\nC- remove");
            printf("\nD- empty");
            printf("\nT- transfer");
            printf("\nE- exit\n");

            fflush(stdin);
            option = toupper(getche());

            switch (option)
            {
            case 'A':
                printf("\n\nInsert");
                if(insertMethod == 'Q')
                    control = insertionQueue(control);
                else
                    control = insertionStack(control);

                break;
            case 'B':
                printf("\n\nList");
                if(insertMethod == 'Q')
                    listation(control->startFlag);
                else
                    listation(control->endFlag);

                break;
            case 'C':
                printf("\n\nRemove");
                control = deletion(control);

                break;
            case 'D':
                printf("\n\nEmpty");
                control = emptyList(control);

                break;
            case 'T':
                printf("\n\nTransfer");
                control = decideTransfer(control, pointerInsertMethod);

                break;
            case 'E':
                printf("\n\nEmpty and exit");
                control = emptyList(control);

                break;
            default:
                printf("\n\nInvalid option");
                break;
            }
        }
        while(option != 'E');
    }

    return 0;
}