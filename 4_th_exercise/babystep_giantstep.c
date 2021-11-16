#include <stdio.h>
#include <math.h>

int bsgs (int p, int g, int y)
{
  int m = sqrt (y);
  int arr1[100000];
  int arr2[100000];
  for (int j = 0; j < m; j++)
    {
      arr1[j] = j;
      arr2[j] = g ^ j;
    };
  int a = pow (g, (-1) * m);
  for (int i = 0; i < m; i++)
    {
      int z = y * pow (a, i);
      int indexZ =-1;
      for (i = 0; i < 1000; i++)
	{

	  if (arr2[i] == z)
	    indexZ=i;
	};
      if (indexZ!=-1)
	{
	  int j = arr1[indexZ];
	  return i * m + j;
	};
    };
}

int
main ()
{
 //set input variables here: 
  int p = 1;
  int g = 5;
  int y = 1002030203;
  printf ("\nResult of baby step giant step is %d", bsgs (p, g, y));

}
