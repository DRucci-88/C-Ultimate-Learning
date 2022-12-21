#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Bit-fields and Enumeration
#define KEYWORD 01
#define EXTERNAL 02
#define STATIC 03

enum enum_dummy
{
  ENUM_KEYWORD = 01,
  ENUM_EXTERNAL = 02,
  ENUM_STATIC = 03
};

int main()
{
  /// Bit-fields and Enumeration
  printf("Bit-fields and Enumeration\n");
  enum enum_dummy dummy = ENUM_KEYWORD;
  printf("%d\n", ENUM_KEYWORD);
  printf("%d\n", dummy);

  /// Storage Allocator
  printf("\nStorage Allocator\n");
  int summalloc = 0;
  int sumcalloc = 0;
  /// 1. Malloc
  // Since the size of int is 4 bytes, this statement will allocate 20 bytes of memory.
  // pointer ptr holds the address of the first bytes in the allocated memory
  int *ptrm = (int *)malloc(5 * sizeof(int));
  memset(ptrm, 0, sizeof(int));
  if (ptrm == NULL)
  {
    printf("Memory not allocated\n");
    exit(0);
  }

  /// 2. Calloc
  int *ptrc = (int *)calloc(5, sizeof(int));
  if (ptrc == NULL)
  {
    printf("Memory not allocated.\n");
    exit(0);
  }

  /// Test
  for (int i = 0; i < 5; i++)
  {
    *(ptrm + i) = i;
    summalloc += *(ptrm + 1);
    printf("%d ", *(ptrm + i));
  }
  printf("\n");
  for (int i = 0; i < 5; i++)
  {
    *(ptrc + i) = i * 2;
    sumcalloc += *(ptrc + 1);
    printf("%d ", *(ptrc + i));
  }
  printf("\nsum malloc: %d \nsum calloc: %d\n", summalloc, sumcalloc);
  printf("%llu\n", sizeof(int) * 5);
  printf("%llu\n", sizeof(*ptrm));
  printf("%llu\n", sizeof(ptrc));

  /// 3. Realloc
  ptrm = realloc(ptrm, 10 * sizeof(int));
  free(ptrm);
  free(ptrc);
  return 0;
}
