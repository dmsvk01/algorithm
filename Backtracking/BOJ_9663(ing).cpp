#include <iostream>
#include <vector>

using namespace std;

int count=0;
int n;

void bt(int depth, int b[][16]){
  if(depth==n+1) count++;
  for(int i=1; i<=n; i++){
    bool pass = true;
    int x=i, y=depth;
    for(int i=1; i<=n; i++){
      if(b[x][i]==1 || b[i][y]==1) pass = false;
      if(x+i<=n && y+i<=n && b[x+i][y+i]==1) pass = false;
      if(x+i<=n && y-i>=1 && b[x+i][y-i]==1) pass = false;
      if(x-i>=1 && y+i<=n && b[x-i][y+i]==1) pass = false;
      if(x-i>=1 && y-i>=1 && b[x-i][y-i]==1) pass = false;
    }
    if(pass){
      b[i][depth]=1;
      bt(depth+1, b);
      b[i][depth]=0;
    }
  }
  return ;
}

int main(){
  int b[16][16]={0};
  cin >> n;
  bt(1, b);
  printf("%d", count);
  return 0;
}

//(1 ≤ N < 15)
