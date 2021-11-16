 #include <stdio.h>
struct gcdExtended {
    int gcd, x, y;
};
  
typedef struct gcdExtended Struct;
  
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
  
// Driver code
int main()
{    
    Struct gcdResult;
    int x = 4;
    int y = 2;
    gcdResult = gcdExtended(x,y);
    printf("\nGCD is: %d ""\nx is %d""\ny is %d",
           gcdResult.gcd,gcdResult.x,gcdResult.y);
  
    return 0;
}