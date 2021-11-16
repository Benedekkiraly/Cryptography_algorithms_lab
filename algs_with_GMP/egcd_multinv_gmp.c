#include <stdio.h>
#include <gmp.h>

struct gcdExtended
{
  mpz_t gcd, x, y;
};

typedef struct gcdExtended Struct;

Struct
gcdExtended (mpz_t a, mpz_t b)
{

  Struct s;
  mpz_t x1, x2, y1, y2, a1, b1;
  mpz_init_set_ui (x1, 0);
  mpz_init_set_ui (x2, 1);
  mpz_init_set_ui (y1, 1);
  mpz_init_set_ui (y2, 0);
  mpz_init (a1);
  mpz_set (a1, a);
  mpz_init (b1);
  mpz_set (b1, b);
  mpz_t q, r, x, y, temp;

  if (mpz_get_ui (b1) == 0)
    {
      //return
      printf ("EGCD of inputs is: ");
      mpz_out_str (stdout, 10, a1);
      printf ("\n");
      mpz_set (s.gcd, a1);
      mpz_set (s.x, x2);
      mpz_set (s.y, x1);
      return s;
    }
  while (mpz_get_ui (b1) > 0)
    {
      mpz_init (q);
      mpz_init (r);
      mpz_init (x);
      mpz_init (y);
      mpz_init (temp);

      mpz_fdiv_q (q, a1, b1);
      mpz_mul (temp, q, b1);
      mpz_sub (r, a1, temp);
      mpz_mul (temp, x1, q);
      mpz_sub (x, x2, temp);
      mpz_mul (temp, q, y1);
      mpz_sub (y, y2, temp);

      mpz_set (a1, b1);
      mpz_set (b1, r);
      mpz_set (x2, x1);
      mpz_set (x1, x);
      mpz_set (y2, y1);
      mpz_set (y1, y);
    }
  //return
  printf ("EGCD of inputs is: ");
  mpz_out_str (stdout, 10, a1);
  printf ("\n");
  mpz_set (s.gcd, a1);
  mpz_set (s.x, x2);
  mpz_set (s.y, y2);
  return s;
}

//2.2 exc, multiplicative inverse function with GMP MPZ
int
multInv (mpz_t a, mpz_t n)
{

  Struct gcdRes;
  gcdRes = gcdExtended(a, n);
  //cannot figure out why it exits from function after running gcdExtended
  mpz_t d, x, y;

  mpz_init (d);
  mpz_init (x);
  mpz_init (y);

  mpz_set (d, gcdRes.gcd);
  mpz_set (x, gcdRes.x);
  mpz_set (y, gcdRes.y);

  if (mpz_get_ui (d) > 1)
    {
      printf ("Multiplicatice inverse of inputs is: 0");
      printf ("\n");
      return 0;
    }

  printf ("Multiplicatice inverse of inputs is:");
  mpz_out_str (stdout, 10, x);
  printf ("\n");
  return 0;
}

int
main ()
{
  //change values of x and y for EGCD inputs
  int a = 4;
  int n = 10;
  mpz_t A, N;
  mpz_init_set_ui (A, a);
  mpz_init_set_ui (N, n);
  multInv (A, N);
  return 0;
}
