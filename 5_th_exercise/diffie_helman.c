#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct keyPair
{
  int x, gx;
};
typedef struct keyPair Struct;

Struct
keygen (int p, int g)
{

  Struct keypair;
  int x = rand () % 5;
  keypair.x = x;
  int gx = pow (g, x);
  keypair.gx = gx;
  return keypair;
}

int
keyAgree (int p, int g, int x, int gy)
{
  int xpow = pow (g, x);
  return gy * xpow;
}

int
main ()
{
  int p = 5;
  int g = 8;			//set base of secret key keygen
  Struct pairA;
  Struct pairB;
  pairA = keygen (p, g);
  pairB = keygen (p, g);
  printf ("\nKeypair of Alice is: x= %d " "\nthe key is %d""\nand keyAgree output is %d", pairA.x, pairA.gx,keyAgree(p,g,pairA.x,pairB.gx));
  printf ("\nKeypair of Bob is: x= %d " "\nthe key is %d""\nand keyAgree output is %d", pairB.x, pairB.gx,keyAgree(p,g,pairB.x,pairA.gx));
  return 0;
}
