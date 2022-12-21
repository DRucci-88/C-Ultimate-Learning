#include <stdio.h>

int sum(int[], const int);
void printArrayOfInt(int[], const int);
void print2DArrayOfInt(int[][3], const int);

int main()
{
  /// 1 Dimensional Array Part 1

  // Menentukan nilai pada array saapembuatan
  int randonNumber1[] = {10, 24, 324, 345, 23};
  int size1 = sizeof(randonNumber1) / sizeof(randonNumber1[0]);
  // int i; // Variable untuk melakukan iterasi

  printf("Isi awal array\n");
  printArrayOfInt(randonNumber1, size1);

  randonNumber1[3] = 1000;
  printf("\nIsi array setelah berubah\n");
  printArrayOfInt(randonNumber1, size1);

  /// Passing 1 Dimensional Array to Function
  printf("\nPassing array to function\n"); // Pass by references
  int randomNumber2[] = {10, 30, 45, 67, 83, 57, 11};
  const int size2 = sizeof(randomNumber2) / sizeof(randomNumber2[0]); // 28 Bytes / 4 Bytes
  // randonNumber2[0] actually an int
  printArrayOfInt(randomNumber2, size2);
  int total = sum(randomNumber2, size2);
  printf("Total : %d\n", total);

  /// 2 Dimensional Array
  int randomNumber3[][3] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };
  printf("%llu\n", sizeof(randomNumber3));       // Size of all  = 36
  printf("%llu\n", sizeof(randomNumber3[0]));    // Size of array int  = 12
  printf("%llu\n", sizeof(randomNumber3[0][0])); // Size of int  = 4
  const int sizeRow = sizeof(randomNumber3) / sizeof(randomNumber3[0]);
  print2DArrayOfInt(randomNumber3, sizeRow);
  return 0;
}

int sum(int receiveArr[], const int size)
{
  int i, result = 0;
  for (i = 0; i < size; i++)
  {
    result += receiveArr[i];
  }
  return result;
}

void printArrayOfInt(int arr[], const int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("Index %d = %d\n", i, arr[i]);
  }
}
void print2DArrayOfInt(int arr[][3], const int sizeRow)
{
  int row, col;
  printf("\nIsi dari 2D array\n");
  for (row = 0; row < sizeRow; row++)
  {
    for (col = 0; col < 3; col++)
    {
      printf("%d ", arr[row][col]);
    }
    printf("\n");
  }
}