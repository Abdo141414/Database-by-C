#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED

#include "STD.h"


typedef struct SimpleDb
{
uint32 student_ID;
uint32 student_year;
uint32 course1_ID;
uint32 course1_grade;
uint32 course2_ID;
uint32 course2_grade;
uint32 course3_ID;
uint32 course3_grade;
}student;
#include"SDB.c"
/*
Function name : SDB_IsFull
Function return type : bool
Function Arguments : NONE
Function Description : check if the database is full or not.
*/

bool SDB_IsFull();

/*
Function name : SDB_GetUsedSize
Function return type : uint8
Function Arguments : NONE
Function Description : get how many students in your database have added.
*/

uint8 SDB_GetUsedSize();

/*
Function name : SDB_AddEntry
Function return type : bool
Function Arguments : NONE
Function Description : When the user chooses to add entry this function asks him for the
required data in the database to add one
student which is his (id, year, Course1_ID,
Course1_grade, Course2_ID,
Course2_grade, Course3_ID, and Course3_grade) and then add to your
database.
*/

bool SDB_AddEntry();

/*
Function name : SDB_DeleteEntry
Function return type : void
Function Arguments : uint32 id .
Function Description : delete the student data with
the given id..
*/

void SDB_DeleteEntry();

/*
Function name : SDB_ReadEntry
Function return type : bool
Function Arguments : uint32 id .
Function Description : print the data of the user by
searching on his data by the given id.
*/

bool SDB_ReadEntry();

/*
Function name : SDB_GetList
Function return type : void
Function Arguments : .
Function Description : it gets the number of ids in the
count and the list of all ids in list array that’s
you get his base address.
.
*/

void SDB_GetList();

/*
Function name : SDB_DeleteEntry
Function return type : bool
Function Arguments : uint32 id .
Function Description : check if the given id is exist.
*/

bool SDB_IsIdExist();

#include"SDBAPP.c"

void SDB_APP();
void SDB_action(uint8 choice);



#endif //SDB_H_INCLUDED
