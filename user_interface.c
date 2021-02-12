/*****************************************************************
//
//  NAME:        Constantine Peros
//
//  HOMEWORK:    3b
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        February 9, 2021
//
//  FILE:        user_interface.c
//
//  DESCRIPTION: The part of the program that interacts with the user
//
****************************************************************/

#include <stdio.h>
#include <string.h>
#include "database.h"
#include "record.h"

void welcomeMsg();
void getInput();
void add();
void print();
void find();
void delete();

int enterAccount();
int debugmode;

void getAddress();

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   The main part of the program
//
//  Parameters:    argc (int) : number of arguments
//                 argv (char*[]): array of arguments
//
//  Return values:  0 : success
//
****************************************************************/

int main(int argc, char* argv[])
{
    struct record * start = NULL;

    debugmode = 0;

    if (argc == 1)
    {
        welcomeMsg();
        getInput(start);
    }
    else if (argc == 2)
    {
        if (strcmp (argv[1], "-debug") == 0)
        {
            debugmode = 1;
            printf("\n\n\n*************************DEBUG MODE");
            printf("*************************\n\n\n");
            welcomeMsg();
            getInput(start);
        }
        else
        {
            printf("\nThere was an error\n");
        }
    }
    return 0;
}

/*****************************************************************
//
//  Function name: welcomeMsg
//
//  DESCRIPTION:   the Welcome Message
//
//  Parameters:    none
//
//  Return values:  none
//
****************************************************************/

void  welcomeMsg()
{
    if (debugmode == 1)
    {
        printf("\n\n****Running welcomeMSG() in debug mode****\n\n");
    }
    printf("\n\nWelcome to the database user interface\n");
    printf("Please Select from the options below\n\n");
    printf("1. [A]dd Record: [add]\n");
    printf("2. [P]rint All Records: [printall] \n");
    printf("3. [F]ind Record: [find]\n");
    printf("4. [D]elete Record: [delete]\n");
    printf("5. [Q]uit: [quit]\n");
}

/*****************************************************************
//
//  Function name: getInput
//
//  DESCRIPTION:   Gets the user input
//
//  Parameters:    user_input (char[]) The user input
//                 runLoop (int) boolean used to run the loop.
//                 length (size_t) length of user input 
//
//  Return values:  none
//
****************************************************************/

void getInput(struct record * start)
{
    char user_input[10];
    int runLoop;
    size_t length;

    runLoop = 1;

    if (debugmode == 1)
    {
        printf("\n\n****Running getInput() in debug mode****\n\n");
    }

    while (runLoop == 1)
    {
        fgets(user_input, 9, stdin);
        length = strlen(user_input) - 1;

        if (strncmp(user_input, "quit", length) == 0 ||
            strncmp(user_input, "QUIT", length) == 0 ||
            strcmp(user_input, "5\n") == 0)
        {
            printf("Quiting Program, Aloha\n\n");
            runLoop = 0;
        }
        else if (strncmp(user_input, "add", length) == 0 ||
            strncmp(user_input, "ADD", length) == 0 ||
            strcmp(user_input, "1\n") == 0)
        {
            printf("Add A Record...\n");
            runLoop = 0;
            add(start);
        }
        else if (strncmp(user_input, "printall", length) == 0 ||
            strncmp(user_input, "PRINTALL", length) == 0 ||
            strcmp(user_input, "2\n") == 0)
        {
            printf("Printing All Records...\n");
            runLoop = 0;
            print(start);
        }
        else if (strncmp(user_input, "find", length) == 0 ||
            strncmp(user_input, "FIND", length) == 0 ||
            strcmp(user_input, "3\n") == 0)
        {
            printf("Find A Record...\n");
            runLoop = 0;
            find(start);
        }
        else if (strncmp(user_input, "delete", length) == 0 ||
            strncmp(user_input, "Delete", length) == 0 ||
            strcmp(user_input, "4\n") == 0)
        {
            printf("Delete A Record...\n");
            runLoop = 0;
            delete(start);
        }
        else
        {
            printf("Invalid Response\n");
        }
    }
}

/*****************************************************************
//
//  Function name: add()
//
//  DESCRIPTION:   adds entry to database
//
//  Parameters:    none
//
//  Return values:  none
//
****************************************************************/

void add(struct record * start)
{
    int accountno;
    int runLoop;
    char name[25];

    if (debugmode == 1)
    {
        printf("\n\n****Running add() in debug mode****\n\n");
    }

    printf("\nEnter The Account Number you wish to add : ");

    accountno = enterAccount();

    printf("\nEnter The Account holder's name you wish to add : ");
    runLoop = 1;

    while (runLoop == 1)
    {
        fgets(name, 24, stdin);
        printf("Input Accepted\n");
        runLoop = 0;
    }

    if (debugmode == 1)
    {
        printf("\n****Account holder name is %s****\n", name);
    }

    getAddress(name, accountno, start);
}

/*****************************************************************
//
//  Function name: print()
//
//  DESCRIPTION:   Prints all records.
//
//  Parameters:    none
//
//  Return values:  none
//
****************************************************************/

void print(struct record * start)
{
    if (debugmode == 1)
    {
        printf("\n\n****Running print() in debug mode****\n\n");
    }
    printAllRecords(start);
}

/*****************************************************************
//
//  Function name: find()
//
//  DESCRIPTION:   finds entry in database
//
//  Parameters:    accountno (int) the account number.
//
//  Return values:  none
//
****************************************************************/

void find(struct record * start)
{
    int accountno;

    if (debugmode == 1)
    {
        printf("\n\n****Running find() in debug mode****\n\n");
    }

    printf("\nEnter The Account Number you wish to find : ");

    accountno = enterAccount();

    if (debugmode == 1)
    {
        printf("\n\n****Running find() in debug mode****\n\n");
        printf("\n****Account number is %d****\n", accountno);
    }

    findRecord(&start, accountno);
}

/*****************************************************************
//
//  Function name: delete()
//
//  DESCRIPTION:   deletes entry from database.
//
//  Parameters:    none
//
//  Return values:  none
//
****************************************************************/

void delete(struct record * start)
{
    int accountno;

    if (debugmode == 1)
    {
        printf("\n\n****Running delete() in debug mode****\n\n");
    }

    printf("\nEnter The Account Number you wish to delete : ");

    accountno = enterAccount();

    if (debugmode == 1)
    {
        printf("\n\n****Running delete() in debug mode****\n\n");
        printf("\n****Account number is %d****\n", accountno);
    }
    deleteRecord(&start, accountno);
}

/*****************************************************************
//
//  Function name: enterAccount()
//
//  DESCRIPTION:   user enters an account number
//
//  Parameters:    user_input (char[]) The user input.
//                 runLoop (int) boolean used to run the loop.
//
//  Return values:  accountno (int) the inputted account number.
//
****************************************************************/

int enterAccount()
{
    int accountno;
    char user_input[100];
    int runLoop;

    if (debugmode == 1)
    {
        printf("\n\n****Running enterAccount() in debug mode****\n\n");
    }
    runLoop = 1;

    while (runLoop == 1)
    {
        fgets(user_input, 99, stdin);

        if ( sscanf(user_input, "%d", &accountno) != 1)
        {
            runLoop = 1;
            printf("Invalid entry, not a number\n");
        }
        else if ( accountno < 0)
        {
            runLoop = 1;
            printf("Invalid entry, less than zero\n");
        }
        else
        {
            printf("Input Accepted\n");
            runLoop = 0;
        }
    }
    return accountno;
}

/*****************************************************************
//
//  Function name: getAddress
//
//  DESCRIPTION:   Gets the user address
//
//  Parameters:    index (int) the space in array to work with
//                 run (int) boolean used to run the loop.
//                 c (char) the user input
//                 address[50] the address
//                 recordEntry (record) struct of the record
//
//  Return values:  none
//
****************************************************************/

void getAddress(char name[], int accountno, struct record * start)
{
    int index;
    int run;
    char c;
    char address[50];

    run = 1;
    index = 0;

    if (debugmode == 1)
    {
        printf("\n\n****Running getAddress() in debug mode****\n");
        printf("****name is: %s", name);
        printf("****accountno is: %d****\n", accountno);
    }

    printf("\nEnter address:\n");
    printf("Press [ENTER] twice to compelete entry.\n");

    while (run == 1)
    {
        c = getchar();
        address[index] = c;
        index++;

        if (c == 10)
        {
            if (address[index - 2] == 10)
            {
                address[index - 2] = '\0';
                printf("Input Accepted\n");

                if (debugmode == 1)
                {
                    printf("\n********DEBUG MODE********\n");
                    printf("****Address Entered Is****\n\n%s", address);
                    printf("\n**************************\n");
                }
                run = 0;
            }
        }
    }

    addRecord(&start, accountno, name, address);
}
