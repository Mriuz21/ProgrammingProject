#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct numberNode
{
    char number[11];
    struct numberNode *next;
}*headNumber, *firstNumber;
struct nameNode
{
    char name[25];
    struct nameNode *next;
}*headName, *firstName;


void Run();
void InitTable();
void PrintTable(struct numberNode *_number, struct nameNode *_name);
void PrintNumber(char number[11]);
void InsertNumber();

char buttons[5][10] = {"Table", "Insert", "Delete", "Exit"};
int length;

int main()
{
    InitTable();
    Run();
}

void Run()
{
    printf(" Menu Buttons:\n");
    printf(" %s -> Show Content Table\n", buttons[0]);
    printf(" %s -> Insert Number\n", buttons[1]);
    printf(" %s -> Delete Number\n", buttons[2]);
    printf(" %s -> Exit Program\n\n ", buttons[3]);

    char inp[10];
    scanf("%s", &inp);

    if(strcmp(inp, buttons[0])==0)
        PrintTable(headNumber, headName);
    else if(strcmp(inp, buttons[1])==0)
    {
        InsertNumber();
        return Run();
    }
    else if(strcmp(inp, buttons[2])==0)
    {
        if(length > 1)
        {
            int _pos;
            printf(" Position: ");
            scanf("%d", &_pos);
            printf("\n");
            DeleteNumber(_pos);
        }
        else printf("\n ***Table cannot be empty***\n\n");
        return Run();
    }
    else if(strcmp(inp, buttons[3])==0)
    {
        system("cls");
        return 0;
    }
    else printf("\n ***Invalid Input***\n\n");
    return Run();
}

void InitTable()
{
    length = 2;
    headNumber = malloc(sizeof(struct numberNode));
    firstNumber = malloc(sizeof(struct numberNode));

    strcpy(headNumber->number, "0713291987");
    strcpy(firstNumber->number, "0709094516");
    headNumber->next = firstNumber;
    firstNumber->next = NULL;
    //strcpy(phoneNumbers[2], "0752070559");
    //strcpy(phoneNumbers[3], "0707251699");
    //strcpy(phoneNumbers[4], "0710474395");

    headName = malloc(sizeof(struct nameNode));
    firstName = malloc(sizeof(struct nameNode));

    strcpy(headName->name, "Brooke Chambers");
    strcpy(firstName->name, "Mae Conley");
    headName->next = firstName;
    firstName->next = NULL;
    //strcpy(names[2], "Zaara Cantrell");
    //strcpy(names[3], "Yousef Decker");
    //strcpy(names[4], "Nabil Pace");
}
void PrintTable(struct numberNode *_number, struct nameNode *_name)
{
    system("cls");
    int k = 0;
    printf(" ______________________________________\n\n");
    while(_number != NULL)
    {
        printf(" %d. |+40 ", k+1);
        PrintNumber(_number);
        _number = _number->next;

        printf("| %s\n", _name);
        _name = _name->next;
        k++;
    }
    printf(" ______________________________________\n\n");
}
void PrintNumber(char number[11])
{
    for(int j = 0; j < 3; j++)
    {
        for(int k = 0; k < 3; k++)
        {
            printf("%c%", number[k+j*3+1]);
        }
        printf(" ");
    }
}
void InsertNumber()
{
    int canAdd = 1;
    struct numberNode *nextNumber = malloc(sizeof(struct numberNode));
    struct nameNode *nextName= malloc(sizeof(struct nameNode));
    printf(" Number: ");
    scanf(" %[^\n]", &nextNumber->number);
    printf(" Name: ");
    scanf(" %[^\n]", &nextName->name);

    for(int i = 2; i < 10; i++)
    {
        if(nextNumber->number[i]<48 || nextNumber->number[i]>57)
        {
            canAdd = 0;
            break;
        }
    }

    if(strlen(nextNumber->number) != 10 || nextNumber->number[0] != '0' || nextNumber->number[1] != '7')
    {
        printf("\n ***Invalid number***\n");
    }
    else if(strlen(nextName->name) > 25)
        printf("\n ***Name is too long***\n");
    else
    {
        if(canAdd == 1)
        {
            if(length > 1)
            {
                firstNumber->next = nextNumber;
                nextNumber->next = NULL;

                firstName->next = nextName;
                nextName->next = NULL;

                firstNumber = nextNumber;
                firstName = nextName;
            }
            else if(length == 0)
            {
                headNumber = nextNumber;
                headName = nextName;
            }
            else
            {
                firstNumber = nextNumber;
                firstName = nextName;
            }
            length++;
            printf("\n ***Successful***\n");
        }
        else printf("\n ***Invalid number***\n");
    }
    printf("\n");
}
void DeleteNumber(int position)
{

    if(position == 1)
    {
        headNumber = headNumber->next;
        headName = headName->next;
        length--;
    }
    else if(position < length && position > 1)
    {
        for (int i=2; i<position; i++)
        {
            if(headNumber->next != NULL)
            {
                headNumber = headNumber->next;
            }
            if(headName->next != NULL)
            {
                headName = headName->next;
            }
        }
        headNumber->next = headNumber->next->next;
        headName->next = headName->next->next;
        length--;
    }
    else if(position == length)
    {
        struct numberNode *tempNumber = headNumber, *prevNumber;
        struct nameNode *tempName = headName, *prevName;

        while(tempNumber->next != NULL)
        {
            prevNumber = tempNumber;
            tempNumber = tempNumber->next;
        }
        prevNumber->next = NULL;

        while(tempName->next != NULL)
        {
            prevName = tempName;
            tempName = tempName->next;
        }
        prevName->next = NULL;
        length--;
    }
    else printf(" ***Invalid position***\n\n");
}
