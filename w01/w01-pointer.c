#include <stdio.h>

void hitungJumlah(int *, int[]);

int main()
{
  int number = 140256;
  printf("Content of number = %d\n", number);
  printf("Content of number = %d\n\n", &number);

  int randomNumber[] = {10, 34, 26, 88, 456};
  printf("randomNumber \t= %p\n", randomNumber);
  printf("&randomNumber \t= %p\n", &randomNumber);
  printf("&randomNumber[0] = %p\n\n", &randomNumber[0]);

  // Pointer dalam array menunjuk ke array ke 0
  printf("randomNumber \t= %d\n", randomNumber[0]);
  printf("*randomNumber \t= %d\n\n", *randomNumber);

  // Pointer menunjuk ke dalam arrau index ke 2
  // dengan menjumlahkan sesuai index
  printf("randomNumber \t= %d\n", randomNumber[2]);
  printf("*(randomNumber+2) \t= %d\n\n", *(randomNumber + 2));

  // Bagaimana dengan alamat array index ke 2?
  printf("&randomNumber[2] \t= %p\n", &randomNumber[2]);

  int jumlah = 0;
  hitungJumlah(&jumlah, randomNumber);
  printf("Jumlah: %d", jumlah);
  return 0;
}

void hitungJumlah(int *jumlah, int numbers[])
{
  int i = 0;
  for (i = 0; i < 5; i++)
  {
    *jumlah += numbers[i];
  }
}