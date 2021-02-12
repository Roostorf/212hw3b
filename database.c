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
//  DATE:        Februry 9th, 2021
//
//  FILE:        Database.c
//
//  DESCRIPTION: Just contains empty stub files for now.
//
****************************************************************/

#include <stdio.h>
#include "record.h"

extern int debugmode;

/*****************************************************************
//
//  Function name: addRecord()
//
//  DESCRIPTION:   The function used to add an entry
//
//  Parameters:    record (struct) The record
//                 accountno (int) acctount number
//                 name (char[]) account holder name
//                 address (char[]) account holder address
//
//  Return values:  0 : for now just returning 0 as a stub
//
****************************************************************/

int addRecord(struct record **recordEntry, int accountno, char name[], char address[])
{
    if (debugmode == 1)
    {
        printf("\n****Running addRecord() in debug mode****\n");
        printf("\n****addRecord was called****\n");
        printf("\n****Account number to add is %d****\n", accountno);
        printf("\n****Account holder name to add is %s****\n", name);
        printf("\n****Account holder address is****\n\n%s\n", address);
        printf("\n**************************\n");
    }
    return 0;
}

/*****************************************************************
//
//  Function name: printAllRecords()
//
//  DESCRIPTION:   Prints all the record to the screen
//
//  Parameters:    record (struct *) The records
//
//  Return Values: none
//
****************************************************************/

void printAllRecords(struct record *recordEntry)
{
    if (debugmode == 1)
    {
        printf("\n****Running printAllRecords() in debug mode****\n");
        printf("\n****printAllRecords was called****\n");
    }
}

/*****************************************************************
//
//  Function name: findRecord()
//
//  DESCRIPTION:   The function used to find an entry
//
//  Parameters:    record (struct) The record
//                 accountno (int) acctount number
//
//  Return values:  0 : for now just returning 0 as a stub 
//
****************************************************************/

int findRecord(struct record *recordEntry, int accountno)
{
    if (debugmode == 1)
    {
        printf("\n****Running findRecord() in debug mode****\n");
        printf("\n****findRecord() was called****\n");
        printf("\n****Account number to find is %d****\n", accountno);
    }
    return 0;
}

/*****************************************************************
//
//  Function name: deleteRecord()
//
//  DESCRIPTION:   The function used to deletes an entry
//
//  Parameters:    record (struct) The record
//                 accountno (int) acctount number
//
//  Return values:  0 : for now just returning 0 as a stub
//
****************************************************************/

int deleteRecord(struct record **recordEntry, int accountno)
{
    if (debugmode == 1)
    {
        printf("\n****Running deleteRecord() in debug mode****\n");
        printf("\n****deleteRecord was called****\n");
        printf("\n****Account number to delete is %d****\n", accountno);
    }
    return 0;
}
