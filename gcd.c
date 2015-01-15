#include <stdio.h>

int rgcd(int x, int y) {
  if (x==0) return y;
  if (y==0) return x;
  if (x > y) {
    return rgcd(y, x-y);
  } else { 
    return rgcd(x, y-x);
  }
}

int gcd(int x, int y) {
  while (x > 0 && y > 0) {
    if (x >= y) {
      x = x-y;
    } else {
      y = y-x;
    }
  }
  return (y == 0) ? x : y;
}

int main(int argc, char* argv[]) {
  int x, y;
  scanf("%d %d", &x, &y);
  printf("x:%d y:%d gcd:%d rgcd:%d", x, y, gcd(x,y), rgcd(x,y));
  return 0;
}
