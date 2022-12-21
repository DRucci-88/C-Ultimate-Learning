#include <stdio.h>

/// Basic of Structures
struct point
{
  int x;
  int y;
};

/// Structures and Functions
struct point makepoint(int x, int y)
{
  struct point temp;
  temp.x = x;
  temp.y = y;
  return temp;
}

struct point addpoint(struct point p1, struct point p2)
{
  p1.x += p2.x;
  p1.y += p2.y;
  return p1;
};

struct key
{
  char *word;
  int count;
} keytab[] = {
    {"auto", 0},
    {"break", 1},
    {"case", 2},
    // dan seterusnya
};

/// Typedef
typedef char *String;

/// Unions
typedef union u_tag
{
  int ival;
  double dval;
  char *sval;
} u;

int main()
{
  /// Basic of Structures
  printf("Basic of Structures\n");
  struct point pt;
  struct point maxpt = {320, 200};
  printf("%d %d\n", pt.x, pt.y);
  printf("%d %d\n", maxpt.x, maxpt.y);

  /// Structures and Functions
  printf("\nStructures and Functions\n");
  struct point origin, *pp;
  pp = &origin;
  printf("Origin: %d - %d\n", origin.x, origin.y);
  printf("Origin: %d - %d\n", (*pp).x, pp->y);
  origin = (struct point){100, 50};
  printf("Origin: %d - %d\n", origin.x, origin.y);
  printf("Origin: %d - %d\n", (*pp).x, pp->y);
  *pp = (struct point){200, 150};
  printf("Origin: %d - %d\n", origin.x, origin.y);
  printf("Origin: %d - %d\n", (*pp).x, pp->y);

  printf("%d\n", keytab[0].count);

  /// Typedef
  printf("\nTypedef\n");
  String name = "Dewa";
  printf("%s\n", name);

  /// Unions
  u utype;
  printf("\nWrong Way\n");
  utype.ival = 10;
  utype.dval = 20.0;
  utype.sval = "Rucci";
  printf("%d, %.2f, %s\n", utype.ival, utype.dval, utype.sval);
  /*
  In above example, we can see that member of ival and dval got corrupted
  because the final value assigned to the variable has occupied
  the memory location (sval).
  */

  u data;
  printf("\nCorrect Way\n");
  data.ival = 30;
  printf("%d\n", data.ival);
  data.dval = 25.9;
  printf("%d\n", data.ival);
  data.sval = "Rucci";
  printf("%d\n", data.ival);

  return 0;
}