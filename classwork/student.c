#include <stdio.h>

typedef char GENDER;
const GENDER MALE = 'M';
const GENDER FEMALE = 'F';

typedef struct
{
    unsigned year ,month , day;
} date;

typedef struct 
{
    char name[32];
    unsigned sid;
    GENDER  gender;//'M' for male 'F' for female
    date dob;
} student;


int main()
{
    student s;

    scanf("%s%u %c", s.name ,&s.sid ,&s.gender);
    printf("%s,%u,%s\n",s.name ,s.sid ,s.gender == MALE ? "Male" : "Female");
    return 0;
}