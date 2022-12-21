#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(int *);
void inputText(char *);
void debugText(char *);
void upperCase(char *);
void lowerCase(char *);
void switching(char *);

int main()
{
  fflush(stdin);
  int pilihan = 0;
  char text[100 + 1];
  for (;;)
  {
    menu(&pilihan);
    switch (pilihan)
    {
    case 1:
      printf("UpperCase\n");
      inputText(text);
      upperCase(text);
      printf("%s\n", text);
      // debugText(text);
      break;
    case 2:
      printf("LowerCase\n");
      inputText(text);
      lowerCase(text);
      printf("%s\n", text);
      break;
    case 3:
      printf("Switching\n");
      inputText(text);
      switching(text);
      printf("%s\n", text);
      break;
    case 4:
      printf("Selamat Tinggal");
      return 0;
    default:
      printf("Default");
      break;
    }
  }

  return 0;
}
// 97 - 122 a - z
// 65 - 90  A - Z
void upperCase(char *text)
{
  for (int i = 0; i < strlen(text); i++)

    if (text[i] >= 97 && text[i] <= 122)
      text[i] -= 32;
}
void lowerCase(char *text)
{
  for (int i = 0; i < strlen(text); i++)

    if (text[i] >= 65 && text[i] <= 90)
      text[i] += 32;
}
void switching(char *text)
{
  for (int i = 0; i < strlen(text); i++)
  {
    if (text[i] >= 65 && text[i] <= 90)
      text[i] += 32;
    else if (text[i] >= 97 && text[i] <= 122)
      text[i] -= 32;
  }
}
void menu(int *pilihan)
{
  printf("1. Uppercase \n2. Lowercase \n3. Switching \n4. Keluar\n");
  printf("Pilihan: ");
  scanf("%d", pilihan);
  getchar();
}
void inputText(char *text)
{
  printf("Masukan Kata: ");
  // fgets(text, sizeof(text), stdin);
  gets(text);
  // sscanf_s("%s", text, sizeof(text));
  // scanf("%s", text);
}
void debugText(char *text)
{
  for (int i = 0; i < strlen(text) + 1; i++)
    printf("%d ", text[i]);

  // fgets(temp, 99, stdin); // scanf("%11s", tpdu); fflush(stdin); i++;

  printf("%llu\n", strlen(text));
}