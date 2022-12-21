#include <stdio.h>

/// External Variables
int max = 10;
void printextern(void)
{
  extern int max;
  printf("%d\n", max);
}

/// Constant
#define VTAB1 '\013' // Octagonal for Vertical Tab
#define VTAB2 '\xB'  // Hexagonal for Vertical Tab
#define VTAB3 11     // Decimal for Vertical Tab as Number

/// Static Variables
int add()
{
  static int count = 0;
  count++;
  return count;
}

int main()
{
  /// External Variables
  printf("External Variables\n");
  extern int max;
  max = 20;
  printextern();
  printf("%d\n", max);

  /// Constant
  printf("\n\nConstant\n");
  printf("I%cam\n", VTAB1);
  printf("I%cam\n", VTAB2);
  printf("I%cam\n", VTAB3); // print number as character

  /// Declarations and Initialization
  printf("\nDeclarations and Initialization\n");
  int low = 0;
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  /*
  Setiap String harus memiliki akhiran NULL character '\0' sbg akhir dari sebuah string
  '\0'  is referred to as NULL character or NULL terminator.
  It is the character equivalent of integer 0(zero) as it refers to nothing
  */
  char pattern1[] = "ould"; // '0', 'u', 'l', 'd', '\0'
  char pattern2[] = {'o', 'u', 'l', 'd', '\0'};
  char null1 = '\0';
  int null2 = '\0';
  printf("%s - %s\n", pattern1, pattern2);
  printf("%s %d\n", null1, null2);

  /// Static Variables
  printf("\nStatic Variables\n");
  printf("%d ", add());
  printf("%d ", add());

  /// Goto and Labels
  printf("\nGoto and Labels\n");
  if (1 == 1)
    goto error;
error:
  printf("Error Happen\n");

  return 0;
}
