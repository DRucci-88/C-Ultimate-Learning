#include <stdio.h>

// strindex: return index of t in s, -1 if none
int mystrindex(char s[], char t[])
{
  int i, j, k;
  // static int bufp = 0;

  for (i = 0; s[i] != '\0'; i++)
  {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
    {
      return i;
    }
  }
  return -1;
}