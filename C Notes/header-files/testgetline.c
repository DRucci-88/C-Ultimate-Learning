#include <stdio.h>

// getline: get line into s, return length
int mygetline(char s[], int lim)
{
  int c, i;

  i = 0;
  // EOF -> Ctrl z (windows), Ctrl D (Unix)
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
  {
    s[i++] = c;
  }
  if (c == '\n')
  {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}