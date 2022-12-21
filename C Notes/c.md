# C Ultimate Summary

## External Variables

external variables are globally accessible.
Jangan terlalu sering menggunakan global variable, karena akan menimbulkan bug.

```c
#include <stdio.h>

int max;                 /* maximum length seen so far */

void printextern(void);

/* print longest input line; specialized version */
main() {
  extern int max;

  max = 20;
  printf("%d\n", max);
  printextern();

  return 0;
}

void printextern(void) {
 extern int max;
 printf("%d\n", max);
}
```

## Constants

```c
# define VTAB '\013'
# define VTAB '\xb'

printf("I%cam\n", VTAB);
```

## Declarations

All variables must be declared before use

```c

int  lower, upper, step;
char c, line[1000];
```

## Initialization

Setiap String harus memiliki akhiran NULL character '\0' sbg akhir dari sebuah string.
'\0'  is referred to as NULL character or NULL terminator.
It is the character equivalent of integer 0(zero) as it refers to nothing

```c
int low = 0;
int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
char pattern[] = "ould";
char pattern[] = { ′o′, ′u′, ′l′, ′d′, ′\0′ };
```

## Static Variables

Static variables have a property of preserving their value even after they are out of their scope.
Setiap function ketika kita define suatu variable.
Variable lokal akan tersimpan nilai value nya. Soalnya by default dijadikan local variable.
(Didalam Bracket)
Mirip kayak Static pada JAVA

```c
#include <stdio.h>
int fun() {
  static int count = 0;
  count++;
  return count;
}
  
int main() {
  printf("%d ", fun());
  printf("%d ", fun());
  return 0;
}
```

## Block Structure

```c
int i = 10;
if (n > 0) {
    int i;  /*declare a new i*/

    for (i = 0; i < n; i++)
        ...
}
```

## Goto and Labels

Tidak rekomended untuk digunakan
Hati-hati jika digunakan pada melakukan looping dan label ditaruh ditas looping tersebut. Malah for4 loop.

```c
for ( ... )
    for ( ... ) {
        ...
        if (disaster)
            goto error;
    }
...

error:
          clean up the mess
```

> Good Code

```c
  printf("\nGoto and Labels\n");
  if (1 == 1)
    goto error;
error:
  printf("Error Happen\n");
```

> Bad Code - Loop

```c
error:
  printf("Error Happen\n");

  printf("\nGoto and Labels\n");
  if (1 == 1)
    goto error;
```

## The C Preprocessor

conceptually a separate first step in compilation

- File Inclusion

```c
#include "filename"
or
#include <filename>
/usr/lib/gcc/x86_64-linux-gnu/9/include/
/usr/local/include/
/usr/include/
```

- Macro Substitution

```c
#define forever for (;;)
#define square(x) (x * x)
int result = square(3);
printf("%d\n", result);
```

- Conditional Inclusion

```c
#ifndef HDR
#define HDR
/*contents of hdr.h go here*/
#endif
```

## Header Files

Let us now consider dividing the program into several source files, as it might be if each of the components were substantially bigger.

A header file contains:

- function declarations
- macro definitions
- data type definitions

### testheader.h

```c
#define MAXLINE 1000    /*symbolic name or symbolic constant*/
#define LOWER  0        /*lower limit of table*/

int mygetline(char line[], int max);
int mystrindex(char source[], char searchfor[]);

struct point {
    int x;
    int y;
} pt;

#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME
    #define STEP   20       /*step size*/
#endif

#ifdef __LINUX
    #define UPPER 300
#elif defined(__WIN)
    #define UPPER 200
#else
    #define UPPER 100
#endif
```

### testgetline.c

```c
#include <stdio.h>

/*getline:  get line into s, return length*/
int mygetline(char s[], int lim) {
    int c, i;

    i = 0;
    //EOF -> Ctrl Z (Windows), Ctrl D (Unix)
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
```

### teststrindex.c

```c
/*strindex:  return index of t in s, −1 if none*/
int mystrindex(char s[], char t[]) {
    int i, j, k;
    static int bufp = 0;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
```

### testfunction.c

```c
//gcc -D__LINUX testfunction.c testinclude/testgetline.c testinclude/teststrindex.c -o testfunction
//gcc testfunction.c testinclude/testgetline.c testinclude/teststrindex.c -o testfunction
/*
Run this in terminal
gcc testfunction.c testgetline.c teststrindex.c -o testfunction && testfunction
*/
#define __LINUX
#include <stdio.h>
#include "./testinclude/testheader.h"

char pattern[] = "ould";    /*pattern to search for*/
#define  square(x)  (x * x)

/*find all lines matching pattern*/
int main() {
    char line[MAXLINE];
    int found = 0;

    printf("upper %d\n", UPPER);

    while (mygetline(line, MAXLINE) > 0)
        if (mystrindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    
    return found;
}
```

---

## Pointers and Addresses

```c
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

printf("%d\n", *(ip));    // 0 alias null
```

## Pointers and Function Arguments

```c
void swap(int *px, int*py);

int main() {
    int a = 5;
    int b = 3;
    printf("original a=%d, b=%d\n", a, b);
    swap(&a,&b);
    printf("swap a=%d, b=%d\n", a, b);
}

void swap(int *px, int*py)  /*interchange*px and *py*/
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}
```

## Pointers and Arrays

```c
char amessage[] = "The Time";       // an array
char *pmessage = "Secret Timeline"; // a pointer
printf("%s - %s\n", amessage, pmessage);
pmessage = amessage;
printf("%s - %s\n", amessage, pmessage);
```

amessage is an array, just big enough to hold the sequence of characters and ′\0′ that initializes it. Individual characters within the array may be changed but amessage will always refer to the same storage. On the other hand, pmessage is a pointer, initialized to point to a string constant; the pointer may subsequently be modified to point elsewhere, but the result is undefined if you try to modify the string contents.

## Multi-dimensional Arrays

```c
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
```

## Initialization of Pointer Arrays

```c
static char *name[] = {
    "Illegal month",
    "January", "February", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December"
};
printf("%s\n", name[1]);
name[0] = "Illegal";
```

## Pointers vs. Multi-dimensional Arrays

```c
#include <stdio.h>
#include <string.h>

char *changeString(char*);  /*changeString: function returning pointer to int*/

int main()
{
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
    return 0;
}

char *changeString(char* data) {
    data = "January";
    return data;
}
```

## Double pointer

```c
int val = 5;
int *ptr1 = &val; // storing address of val to pointer ptr.
*ptr1 = 10;
int **ptr2 = &ptr1; // pointer to a pointer declared
                    // which is pointing to an integer.
**ptr2 = 20;

typedef struct Ht_item Ht_item;

// Define the Hash Table Item here
struct Ht_item {
    char*key;
    char* value;
};

typedef struct HashTable HashTable;

// Define the Hash Table here
struct HashTable {
    // Contains an array of pointers
    // to items
    Ht_item** items;
    int size;
    int count;
};

HashTable*create_table(int size) {
    // Creates a new HashTable
    HashTable* table = (HashTable*) malloc (sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (Ht_item**) calloc (table->size, sizeof(Ht_item*));
    for (int i=0; i<table->size; i++)
        table->items[i] = NULL;

    return table;
}
```

## Basics of Structures

```c
struct point {
    int x;
    int y;
};

struct point pt;
struct point maxpt = {320, 200};
printf("%d,%d", pt.x, pt.y);
```

## Structures and Functions

```c
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
}

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

struct key {
    char *word;
    int count;
} keytab[NKEYS];

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    /* ... */
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

 { "auto", 0 },
 { "break", 0 },
 { "case", 0 },
...
```

## Typedef

```c
typedef int Length;
```

makes the name Length a synonym for int. The type Length can be used in declarations, casts, etc., in exactly the same ways that the type int can be:

```c
typedef int Length;
Length len, maxlen;
Length *lengths[];
```

Similarly, the declaration

```c
typedef char *String;
String name = "Dewa";
printf("%s\n", name);
```

makes String a synonym for char * or character pointer, which may then be used in declarations and casts

## Unions

You can define a union with many members, but only one member can contain a value at any given time.
<https://www.tutorialspoint.com/cprogramming/c_unions.htm>

```c
typedef union u_tag {
    int ival;
    float fval;
    char *sval;
} u;

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
```

## Bit-fields and Enumeration

```c
#define KEYWORD  01
#define EXTERNAL 02
#define STATIC   04

or

enum enum_dummy
{
  ENUM_KEYWORD = 01,
  ENUM_EXTERNAL = 02,
  ENUM_STATIC = 03
};

int main()
{
  enum enum_dummy dummy = ENUM_KEYWORD;
  printf("%d\n", ENUM_KEYWORD);
  printf("%d\n", dummy);
  return 0;
}
```

## String Operations

```c
/// Common Operations
strcat(s,t) concatenate t to end of s
strncat(s,t,n) concatenate n characters of t to end of s
strcmp(s,t) return negative, zero, or positive for s < t, s == t, or s > t
strncmp(s,t,n) same as strcmp but only in first n characters
strcpy(s,t) copy t to s
strncpy(s,t,n) copy at most n characters of t to s
strlen(s) return length of s
strchr(s,c) return pointer to first c in s, or NULL if not present
strrchr(s,c) return pointer to last c in s, or NULL if not present

/// Character Class Testing and Conversion
isalpha(c) non-zero if c is alphabetic, 0 if not
isupper(c) non-zero if c is upper case, 0 if not
islower(c) non-zero if c is lower case, 0 if not
isdigit(c) non-zero if c is digit, 0 if not
isalnum(c) non-zero if isalpha(c) or isdigit(c), 0 if not
isspace(c) non-zero if c is blank, tab, newline, return, formfeed, vertical tab
toupper(c) return c converted to upper case
tolower(c) return c converted to lower case

/// Formatted Output
int printf(const char *format, ...)
int fprintf(FILE*stream, const char *format, ...)
int sprintf(char*s, const char *format, ...)
/*
sprintf is the same as printf except that the output is written into the string s, 
terminated with ′\0′.  s must be big enough to hold the result. 
The return count does not include the ′\0′.
*/
```

## A Storage Allocator

### malloc

doesn’t initialize the allocated memory

```c
int*ptr = (int*) malloc(5 * sizeof(int));
if (ptr == NULL) {
    printf("Memory not allocated.\n");
    exit(0);
}
else {
    // Memory has been successfully allocated
    printf("Memory successfully allocated.\n");
}
```

Since the size of int is 4 bytes, this statement will allocate 20 bytes of memory. And, the pointer ptr holds the address of the first byte in the allocated memory.

### calloc

calloc() allocates the memory and also initializes every byte in the allocated memory to 0

```c
int*ptr = (int*) calloc(5, sizeof(int));
if (ptr == NULL) {
    printf("Memory not allocated.\n");
    exit(0);
}
else {
    // Memory has been successfully allocated
    printf("Memory successfully allocated.\n");
}
```

### free

```c
free(ptr);
```

### realloc

Realloc function is used to resize a block of memory that was previously allocated. The realloc function allocates a block of memory (which be can make it larger or smaller in size than the original) and copies the contents of the old block to the new block of memory, if necessary.

```c
ptr = realloc(ptr, 10 * sizeof(int));
```

### Test

```c
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
```

---

## typedef union header Header

```c
typedef long Align;  /*for alignment to long boundary*/

union header {       /*block header:*/
    struct {
        union header *ptr; /* next block if on free list */
        unsigned size;     /* size of this block */
    } s;
    Align x;         /* force alignment of blocks */
};
```

## Bitwise Operators

- `&   bitwise AND`
- `¦   bitwise inclusive OR`
- `^   bitwise exclusive OR / bitwise XOR`
- `<<  left shift`
- `>>  right shift`
- `~   one’s complement (unary) / bitwise NOT`

```c
#include <stdio.h>

int main() {

  int t = 0;
  int a = 5; //0000 0101

  t = a << 1; //0000 1010
  printf("%d\n", t);

  t = a << 2; //0001 0100
  printf("%d\n", t);

  t = a >> 1; //0000 0010
  printf("%d\n", t);

  t = a >> 2; //0000 0001
  printf("%d\n", t);

  int b = 3;
  t = a & b;
  /*
    0000 0101
    0000 0011
    _________&
    0000 0001
  */
  printf("%d\n", t);

  t = a | b;
  /*
    0000 0101
    0000 0011
    _________|
    0000 0111
  */
  printf("%d\n", t);

  t = a ^ b;
  /*
    0000 0101
    0000 0011
    _________^
    0000 0110
  */
  printf("%d\n", t);

  t = 5;
  t = ~t;
  printf("%d\n", t);

  char p = 0x50; //0101 0000
  p = ~p;
  /*
    0101 0000
    _________~
    1010 1111  -> 0xaf = 175
    8+0+2+0=10=a 8+4+2+1=15=f
  */
  printf("%c\n", p);

  return 0;
}
```

## Function Pointer

```c
#include <stdio.h>

void fun(int);

int main() {
    // fun_ptr is a pointer to function fun()
    void (*fun_ptr)(int) = &fun;
    //void (*fun_ptr)(int) = fun;

    /* The above line is equivalent of following two
       void (*fun_ptr)(int);
       fun_ptr = &fun;
    */

    // Invoking fun() using fun_ptr
    (*fun_ptr)(10);
    //fun_ptr(10);

    return 0;
}

void fun(int a) {
    printf("Value of a is %d\n", a);
}
```

```c
#include <stdio.h>

void fun1();
void fun2();
void wrapper(void (*fun)());
  
int main()
{
    wrapper(fun1);
    wrapper(fun2);
    return 0;
}

void fun1() {
    printf("Fun1\n");
}

void fun2() {
    printf("Fun2\n");
}

void wrapper(void (*fun)()) {
    printf("Wrapper\n");
    fun();
}
```

## Stringification

When a macro parameter is used with a leading `#', the preprocessor replaces it with the literal text of the actual argument, converted to a string constant. Stringification in C involves more than putting double-quote characters around the fragment.

```c
#define xstr(s) str(s)
#define str(s) #s
#define foo 4
char*x = str (foo);
printf("%s\n", x);
char* y = xstr (foo);
printf("%s\n", y);
/*
str (foo)
  ==> "foo"
xstr (foo)
  ==> xstr (4)
  ==> str (4)
  ==> "4"
*/
```

## Concatenation

```c
/*
In C language, ## operator is used for token pasting or token concatenation. 
Using this operator, we can combine two valid tokens into one valid token.
*/
#include <stdio.h>
#define COMMAND(NAME)  { #NAME, NAME ## _command }
struct command commands[] =
{
  COMMAND (quit),
  COMMAND (help)
};

void quit_command();
void help_command();

int main() {
    commands[0].function();
    commands[1].function();
    return 0;
}

void quit_command() {
    printf("quit\n");
}

void help_command() {
    printf("help\n");
}
```

---

```c
#define SINGLETON(t, inst, init) t* Singleton_##t() { \
                 static t inst = init;               \
                 return &inst;                       \
                }

#include <stdio.h>

/*actual definition*/
SINGLETON(float, finst, 4.2);

int main() {
    printf("%f\n", *(Singleton_float()));
    return 0;
}
```
