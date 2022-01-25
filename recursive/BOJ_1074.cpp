#include <iostream>
#include <cmath>
using namespace std;

int n,r,c,count=0;

int solve(int x, int y, int len){
  if(x==r && y==c) return 0;
  if(x<=r && r<x+len/2 && y<=c && c<y+len/2) return 0+solve(x,y,len/2);
  if(x<=r && r<x+len/2 && y+len/2<=c && c<y+len) return pow((len/2),2)*1+solve(x,y+len/2,len/2);
  if(x+len/2<=r && r<x+len && y<=c && c<y+len/2) return pow((len/2),2)*2+solve(x+len/2,y,len/2);
  if(x+len/2<=r && r<x+len && y+len/2<=c && c<y+len) return pow((len/2),2)*3+solve(x+len/2,y+len/2,len/2);

  return 0;
}

int main(){
  scanf("%d %d %d", &n, &r, &c);
  int result = solve(0,0,pow(2,n));
  printf("%d\n", result);
}
