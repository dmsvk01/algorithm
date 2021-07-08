#include <iostream>
#include <algorithm>

using namespace std;

int t;
int input[1000][3]={0};
int dp[1000][30][2]={0};
int maxnum=0;
void jadoo(int move, int x, int depth, int sum){
  if(depth > t) return ;
  if(input[depth][x]==1)
    sum++;

  if(dp[depth][move][x]==0){
    dp[depth][move][x] = sum;
  }else if(dp[depth][move][x] < sum){
    dp[depth][move][x] = sum;
  }else{
    return ;
  }

  if(maxnum < sum) maxnum = sum;

  if(t-depth-1 + sum < maxnum) return ;
  
  if(move!=0 && x==1){
    jadoo(move-1, x+1, depth+1, sum);
    jadoo(move, x, depth+1, sum);
  }else if(move!=0 && x==2){
    jadoo(move-1, x-1, depth+1, sum);
    jadoo(move, x, depth+1, sum);
  }else
    jadoo(move, x, depth+1, sum);
}
int main(){
  int w;
  cin >> t >> w;
  for(int i=0; i<t; i++){
    int x;
    cin >> x;
    if(x==1) input[i][1]=1;
    if(x==2) input[i][2]=1;
  }
  jadoo(w, 1, 0, 0);
  jadoo(w-1, 2, 0, 0);
  printf("%d\n", maxnum);
}
