#include <stdio.h>

int insertItemsInMatrix(int lenght, int matrix[lenght][lenght])
{
  for (int line = 0; line < lenght; line++)
    for (int column = 0; column < lenght; column++)
    {
      printf("\nPlease, insert here the value of the position [%d][%d]: ", line, column);
      scanf("%d", &matrix[line][column]);
    }
}

void showMatrix(int lenght, int matrix[lenght][lenght])
{
  printf("\n-- Starting shoMatrix --\n");

  for (int line = 0; line < lenght; line++)
    for (int column = 0; column < lenght; column++)
      printf("In position [%d][%d]: %d \n", line, column, matrix[line][column]);

  printf("-- Finishing shoMatrix --\n");
}

int sumMainDiagonal(int lenght, int matrix[lenght][lenght])
{
  int sum = 0;

  for (int position = 0; position < lenght; position++)
    sum = sum + matrix[position][position];

  return sum;
}

int sumSecDiagonal(int lenght, int matrix[lenght][lenght])
{
  int sum = 0;

  for (int position = 0; position < lenght; position++)
    sum = sum + matrix[position][lenght - position - 1];

  return sum;
}

void cleanMatrix(int lenght, int matrix[lenght][lenght])
{
  for (int line = 0; line < lenght; line++)
    for (int column = 0; column < lenght; column++)
      matrix[line][column] = 0;
}

void cleanList(int lenght, int array[lenght])
{
  for (int position = 0; position < lenght; position++)
    array[position] = 0;
}

void sumLines(int lenght, int matrix[lenght][lenght], int array[lenght])
{
  for (int line = 0; line < lenght; line++)
  {
    array[line] = 0;

    for (int column = 0; column < lenght; column++)
      array[line] += matrix[line][column];
  }
}

void sumColumns(int lenght, int matrix[lenght][lenght], int array[lenght])
{
  for (int column = 0; column < lenght; column++)
  {
    array[column] = 0;

    for (int line = 0; line < lenght; line++)
      array[column] += matrix[line][column];
  }
}

void showArray(int lenght, int array[lenght])
{
  printf("\n-- Starting showArray --\n");

  for (int position = 0; position < lenght; position++)
    printf("In position[%d] %d \n", position, array[position]);

  printf("-- Finishing showArray --\n");
}

int checkIfValuesAreEqual(int lenght, int array[lenght])
{
  int position = 0;
  int positionValue = array[position];

  for (position; position < lenght; position++)
  {
    if (array[position] == positionValue)
      return 1;
    else
      return 0;
  }
}

int main(void)
{
  int lenghtMatrix = 0;

  printf("Please, insert here the matrix length: ");
  scanf("%d", &lenghtMatrix);
  printf("\n");

  int matrix[lenghtMatrix][lenghtMatrix];
  cleanMatrix(lenghtMatrix, matrix);
  showMatrix(lenghtMatrix, matrix);

  insertItemsInMatrix(lenghtMatrix, matrix);
  showMatrix(lenghtMatrix, matrix);

  int resultSumMainDiagonal = sumMainDiagonal(lenghtMatrix, matrix);
  int resultSumSecDiagonal = sumSecDiagonal(lenghtMatrix, matrix);

  int resultSumLines[lenghtMatrix];
  int resultSumColumns[lenghtMatrix];

  sumLines(lenghtMatrix, matrix, resultSumLines);
  showArray(lenghtMatrix, resultSumLines);

  sumColumns(lenghtMatrix, matrix, resultSumColumns);
  showArray(lenghtMatrix, resultSumColumns);

  int isSumLinesEqual = checkIfValuesAreEqual(lenghtMatrix, resultSumLines);
  int isSumColumnsEqual = checkIfValuesAreEqual(lenghtMatrix, resultSumColumns);

  if (isSumLinesEqual && isSumColumnsEqual && resultSumMainDiagonal == resultSumSecDiagonal && resultSumLines[0] == resultSumMainDiagonal)
    printf("\n -- It is a magic square! :) -- \n");
  else
    printf("\n -- It is NOT a magic square! :( -- \n");

  printf("\n-- Finishing the main function -- \n");

  return 0;
}