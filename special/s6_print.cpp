#include <iostream>
using namespace std;
#define NULL 5
struct Student
{
    int num;
    char name[16];
    int score[3];
};
int input(Student *studen)
{
    for(int i=0;i<NULL;i++)
    {
        cin>>(*(studen+i)).name;
        cin>>(*(studen+i)).num;
        cin>>(*(studen+i)).score[3];
    }
}
int main()
{
    Student student[NULL];
    Student *student=&student[NULL];
    input(student);
    return 0;
}
