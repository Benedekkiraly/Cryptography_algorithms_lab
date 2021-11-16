#include <stdio.h>
struct gcdExtended {
    int gcd, x, y;
};
  
typedef struct gcdExtended Struct;
//2.1 exc.,Extended Euclidean algorithm function 
Struct gcdExtended(int a, int b)
{
    Struct s;
    if (b == 0) {
        s.gcd = a;
        s.x = 1;
        s.y = 0;
        return s;
    }
    
    int x1 = 0;
    int x2 = 1;
    int y1 = 1;
    int y2 = 0;
    
    while (b > 0) {
        int q = a/b;
        int r = a-q*b;
        int x = x2-x1*q;
        int y= y2-q*y1;
        a = b;
        b = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    s.gcd = a;
    s.x = x2;
    s.y = y2;
  
    return s;
}
//2.2 exc, multiplicative inverse function
int multInv(int a,int n) {
    Struct gcdRes;
    gcdRes = gcdExtended(a,n);
    int d = gcdRes.gcd;
    int x = gcdRes.x;
    int y = gcdRes.y;
    
    if (d > 1) {
       return 0;
    }
    return x;
}
  
// Driver code
int main()
{    
    int a = 3;
    int n = 10;
    printf("\n multiplicative inverse is %d",multInv(a,n));
    
    return 0;
}