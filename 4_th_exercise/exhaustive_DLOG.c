#include <stdio.h>
#include <math.h>

int
RSM (int a, int k[], int len, int n)
{

  int b;
  if (len == 0)
    {
      return 1;
    }
  int A = a;
  if (k[0] == 1)
    {
      b = a;
    }
  for (int i = 1; i < len; i++)
    {
      A = A ^ 2 % n;
      if (k[i] == 1)
	{
	  A = A * b % n;
	}
    }
  return A;
}

int
exhaustiveDLOG1 (int p, int g, int y)
{
  int arr[] = { 0, 1, 3, 4, 5, 8, 7 };	//length of the power in bits
  int len = (sizeof (arr) / sizeof (arr[0]));
  for (int k = 0; k < p; k++)
    {

      if (y == RSM (g, arr, len, p))
	{
	  return k;
	}
    }
}

int
exhaustiveDLOG2 (int p, int g, int y)
{
  int arr[] = { 0, 1, 3, 4, 5, 8, 7 };	//length of the power in bits
  int len = (sizeof (arr) / sizeof (arr[0]));

  for (int k = 0; k < sqrt (p); k++)
    {

      if (y == RSM (g, arr, len, p))
	{
	  return k;
	}
    }
}

// Driver code
int
main ()
{
  int a = 9;
  int arr[] = { 0, 1, 3, 4, 5, 8, 7 };	//length of the power in bits
  int n = 14;
  int len = (sizeof (arr) / sizeof (arr[0]));
  printf ("\nRSM is %d", RSM (a, arr, len, n));
  int p = 2;
  int g = 3;
  int y = 10;
  printf ("\nExhaustiveDLOG1 search output is %d", exhaustiveDLOG1 (p, g, y));
  printf ("\nExhaustiveDLOG2 search output is %d", exhaustiveDLOG2 (p, g, y));
  return 0;
}
