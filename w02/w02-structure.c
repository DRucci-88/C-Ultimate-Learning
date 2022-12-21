#include <stdio.h>
#include <string.h>
struct Student
{
  char name[50];
  char major[50];
  float gpa;
};

struct Student newStudent(char name[], char major[], float gpa)
{
  struct Student s;
  strncpy(s.name, name, 50);
}

int main()
{
  struct Student waldo = {"Waldo", "Informatika", 3.98};
  struct Student *waldoPtr = &waldo;

  printf("%llu \n", sizeof(waldo.name));

  printf("Without Pointer\n");
  printf("Name \t: %s\n", waldo.name);
  printf("Major \t: %s\n", waldo.major);
  printf("Gpa \t: %.2f\n", waldo.gpa);

  printf("With Pointer\n");
  printf("Name \t: %s\n", waldoPtr->name);
  printf("Major \t: %s\n", (*waldoPtr).major);
  printf("Gpa \t: %.2f\n", (*waldoPtr).gpa);
  return 0;
}
