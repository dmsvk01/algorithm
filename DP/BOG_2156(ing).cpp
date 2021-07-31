#include <iostream>

using namespace std;

int input[10001];
int mem[10001][3];
int n;

void dp(int pos, int c, int value){
  if(pos==n) return ;

  if(c==2){
    mem[pos][c] = mem[pos-1][c-1];
    dp(pos+1, 0, value); // 안먹어야 하고 안먹으니까 value 값 그대로 간다.
  }
  else{
    mem[pos][c+1] = value + input[pos];
    dp(pos+1, c+1, mem[pos][c+1]); // 먹음

    mem[pos][c] = value;
    dp(pos+1, 0, value); // 안먹음
  }
  return ;
}

int main(){
  cin >> n;
  for(int i=0; i<n; i++) cin >> input[i];
  dp(0,0,0);

  for(int i=0; i<3; i++){
    for(int j=0; j<n; j++){
      printf("%d ", mem[j][i]);
    }
    printf("\n");
  }
}

//첫째 줄에 포도주 잔의 개수 n이 주어진다. (1≤n≤10,000)
