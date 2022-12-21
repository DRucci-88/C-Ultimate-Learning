#define __LINUX
#include <stdio.h>
#include "testheader.h"

char pattern[] = "ould"; // Pattern to search for
#define square(x) (x * x)

int main()
{
  char line[MAXLINE];
  int found = 0;
  printf("upper %d\n", UPPER);

  while (mygetline(line, MAXLINE) > 0)
  {
    if (mystrindex(line, pattern) >= 0)
    {
      printf("%s", line);
      found++;
    }
  }
  return found;
}

/*
Run this in terminal
gcc testfunction.c testgetline.c teststrindex.c -o testfunction && testfunction
*/

/*
gcc -D__LINUX testfunction.c testinclude/testgetline.c testinclude/teststrindex.c -o testfunction
gcc testfunction.c testinclude/testgetline.c testinclude/teststrindex.c -o testfunction

*/
