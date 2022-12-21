#define MAXLINE 1000 // Symbolic name or symbolic content
#define LOWER 0      // Lower limit of table

int mygetline(char line[], int max);
int mystrindex(char source[], char searchfor[]);

struct point
{
  int x;
  int y;
} pt;

#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME
  #define STEP 20
#endif // !HEADER_FILE_NAME

#ifdef __LINUX
  #define UPPER 300
#elif defined(__WIN)
  #define UPPER 200
#else
  #define UPPER 100
#endif // DEBUG
