#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/// Pointers and Function Arguments
void swap(int *px, int *py)
{
  int temp = *px;
  *px = *py;
  *py = temp;
}

/// Pointers vs. Multi-dimensional Arrays
char *changeString(char *data)
{
  data = "January";
  return data;
}

/// Double pointer
typedef struct Ht_item
{
  char *key;
  char *value;
} Ht_item;

// Define the hast Table here
typedef struct HashTable
{
  // Contains an array of pointers to items
  Ht_item **items;
  int size;
  int count;
} HashTable;

HashTable *create_table(int size)
{
  // Creates a new HashTable
  HashTable *table = (HashTable *)malloc(sizeof(HashTable));
  table->size = size;
  table->count = 0;
  table->items = (Ht_item **)calloc(table->size, sizeof(Ht_item *));
  for (int i = 0; i < table->size; i++)
    table->items[i] = NULL;
  return table;
}

int main()
{
  /// Pointers and Addresses
  printf("Pointers and Addresses\n");
  int x = 1, y = 2, z[10];
  int *ip;

  ip = &x;
  printf("ip %d\n", *(ip)); // 1
  y = *ip;
  printf("ip %d\n", *(ip)); // 1
  printf("y %d\n", y);      // 1
  *ip = 0;
  printf("ip %d\n", *(ip)); // 0
  printf("x %d\n", x);      // 0
  printf("y %d\n", y);      // 1
  *ip = *ip + 10;
  printf("ip %d\n", *(ip)); // 10
  printf("x %d\n", x);      // 10
  printf("y %d\n", y);      // 1
  ip = &z[0];
  printf("%d\n", *(ip));

  /// Pointers and Function Arguments
  printf("\nPointers and Function Arguments\n");
  int a = 5;
  int b = 3;
  printf("%d - %d\n", a, b);
  swap(&a, &b);
  printf("%d - %d\n", a, b);

  /// Pointers and Arrays
  printf("\nPointers and Arrays\n");
  char amessage[] = "The Time";       // an array
  char *pmessage = "Secret Timeline"; // a pointer
  printf("%s - %s\n", amessage, pmessage);
  pmessage = amessage;
  printf("%s - %s\n", amessage, pmessage);

  /// Multi-Dimensional Arrays
  printf("\nMulti-Dimensional Arrays\n");
  char days[2][13] = {
      {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
      {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  };
  char aa = 49;
  printf("%d - %c\n", aa, aa);

  for (int i = 0; i < 13; i++)
    printf("%d ", days[0][i]);
  printf("\n");

  /// Pointers vs. Multi-dimensional Arrays
  printf("\nPointers vs. Multi-dimensional Arrays\n");
  char aname[][15] = {"Illegal month", "Jan", "Feb", "Mar"};
  printf("%s\n", aname[0]);
  /* This will give an Error which says assignment to expression
  with an array type */
  // aname[0] = "Illegal";
  strcpy(aname[0], "Illegal");
  printf("%s\n", aname[0]);

  char month[256] = "December";
  printf("Month 01, %s\n", month);

  /*
  Remember that u are actually passing the address of the array
  when you pass the string, because arrays do not require an address
  operator (&) to be used to pass their addresses.
  So the values in the array string are modified */
  // String = Array of Characters
  char *result = changeString(&month[0]);
  // char *result = changeString(month);

  printf("month: %s \n", result);
  printf("month: %s \n", month);

  /// Double pointer
  printf("\nDouble pointer\n");
  int val = 5;

  // storing address of val to pointer ptr.
  int *ptr1 = &val;
  *ptr1 = 10;

  // pointer to a pointer declared which is pointing to an integer
  int **ptr2 = &ptr1;

  **ptr2 = 20;
}