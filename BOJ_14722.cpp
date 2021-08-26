#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define VMAX 1000
#define INF 987654321

using namespace std;

int findnext(int next){
  next++;
  if(next==3) next=0;
  return next;
}

int main(){
  int n;
  int b[VMAX][VMAX];
  int mem[VMAX][VMAX];
  int v[VMAX][VMAX]={0};
  cin >> n;
  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      scanf("%d", &b[i][j]);
    }
  }

  if(b[0][0]==0){
    mem[0][0]=1;
    v[0][0]=1;
  }else{
    mem[0][0]=0;
    v[0][0]=0;
  }

  for(int i=1; i<n; i++){
    int next = v[0][i-1]; // 이번차례에 마실 수 있는 우유 종류 구하기
    if(next==b[0][i]){
      mem[0][i] = mem[0][i-1]+1;
      v[0][i]=findnext(next);
    }else{
      mem[0][i] = mem[0][i-1];
      v[0][i] = next;
    }
  }

  for(int i=1; i<n; i++){
    int next = v[i-1][0];// 이번차례에 마실 수 있는 우유 종류 구하기
    if(next==b[i][0]){
      mem[i][0] = mem[i-1][0]+1;
      v[i][0]=findnext(next);
    }else{
      mem[i][0] = mem[i-1][0];
      v[i][0]=next;
    }
  }

  for(int i=1; i<n; i++){
    for(int j=1; j<n; j++){
      // 이번차례에 마실 수 있는 우유 종류 구하기 - 각 위,왼쪽에 대해서
      int next_top = v[i-1][j];
      int next_left = v[i][j-1];

      int top, left;
      if(b[i][j] == next_top){
        top = mem[i-1][j] + 1;
      }else{
        top = mem[i-1][j];
      }
      if(b[i][j] == next_left){
        left = mem[i][j-1] + 1;
      }else{
        left = mem[i][j-1];
      }

      if(top > left){ // top 기준으로 구하기
        mem[i][j] = top;
        if(next_top==b[i][j]){
          v[i][j]=findnext(next_top);
        }else{
          v[i][j]=next_top;
        }
      }else{ // left 기준으로 구하기 어차피 우유 number를 고려한 상태이기 때문에 상관없다.
        mem[i][j] = left;
        if(next_left==b[i][j]){
          v[i][j]=findnext(next_left);
        }else{
          v[i][j]=next_left;
        }
      }

    }
  }
  cout << mem[n-1][n-1];
  return 0;
}

/*
4
0 1 2 2
1 1 1 1
2 2 2 2
0 0 1 0

*/
