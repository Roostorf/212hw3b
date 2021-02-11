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
//  DATE:        Feb 8 2021
//
//  FILE:        record.h
//
//  DESCRIPTION:
//   Contains the entry structure for the database
//
//
****************************************************************/

struct record
{
    int accountno;
    char name[25];
    char address[50];
    struct record* next;
};
