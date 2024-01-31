#include <stdio.h>
#define SIZE 10
typedef struct students
{
    int rollno;
    char name[20];
    float marks;
} stud;

void add_students(stud s[SIZE]);
void sort(stud s[SIZE]);
int main(void)
{
    
     stud s[SIZE] = {{1,"John",89},
        {2,"Jane",76},
        {3,"Tom",94},
        {4,"Mary",88},
        {5,"Lisa",90},
        {6,"Alice",85},
        {7,"Bob",92},
        {8,"Sarah",87},
        {9,"Roger",86},
        {10,"Samantha",91}};
   // stud s[SIZE];
    //add_students(s);
    sort(s);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d %4s %4.2f\n", s[i].rollno, s[i].name, s[i].marks);
    }

    return 0;
}

void add_students(stud s[SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter students details(rollno, name, marks) :");
        scanf("%d", &s[i].rollno);
        scanf("%s", s[i].name);
        scanf("%f", &s[i].marks);
    }
}

void sort(stud s[SIZE])
{
    int pos, flag;
    int iterations = 0, comparisons = 0;
    for (int i = 0; i < SIZE - 1; i++)
    {
        iterations++;
        flag = 0;
        for (int pos = 0; pos < SIZE - 1 - i; pos++)
        {
            comparisons++;
            stud t;
            if (s[pos].marks > s[pos + 1].marks)
            {
                t = s[pos];
                s[pos] = s[pos + 1];
                s[pos + 1] = t;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    printf("\n Iterations = %d  comparisons = %d\n", iterations, comparisons);
}