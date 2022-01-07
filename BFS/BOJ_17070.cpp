#include <iostream>
#include <vector>

using namespace std;

int board[16][16]={0,};
vector<pair<pair<int,int>, pair<int,int>>> a;
int n;
int count=0;

void input(){
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      scanf("%d", &board[i][j]);
    }
  }
}

void solve(){
   // (0,0) , (0,1) 로 초기 셋팅 -> w,z 가 n-1,n-1이 될때 까지
  a.push_back({{0,0},{0,1}});
  while(!a.empty()){
    int x = a.back().first.first;
    int y = a.back().first.second;
    int w = a.back().second.first;
    int z = a.back().second.second;
    a.pop_back();
    if(w==n-1 && z==n-1) count++;
    //가로인 경우
    if(x==w && y+1==z){
      if(board[x][y+2]==0 && y+2 < n){
        a.push_back({{x,y+1},{w,z+1}});
      }
      if(board[x][y+2]==0 && board[x+1][y+2]==0 && board[x+1][y+1]==0 && y+2 < n && x+1 < n){
        a.push_back({{x,y+1},{w+1,z+1}});
      }
    }

    //세로인 경우
    if(x+1==w && y==z){
      if(board[x+2][y]==0 && x+2 < n){
        a.push_back({{x+1,y},{w+1,z}});
      }
      if(board[x+1][y+1]==0 && board[x+2][y+1]==0 && board[x+2][y]==0 && y+1 < n && x+2 < n){
        a.push_back({{x+1,y},{w+1,z+1}});
      }
    }

    //대각선인 경우
    if(x+1==w && y+1==z){
      if(board[w][z+1]==0 && z+1 < n){
        a.push_back({{x+1,y+1},{w,z+1}});
      }
      if(board[w+1][z]==0 && w+1 < n){
        a.push_back({{x+1,y+1},{w+1,z}});
      }
      if(board[w][z+1]==0 && board[w+1][z]==0 && board[w+1][z+1]==0 && w+1 < n && z+1 < n){
        a.push_back({{x+1,y+1},{w+1,z+1}});
      }
    }
  }
  cout << count << endl;
}

int main(){
  input();
  solve();
  return 0;
}

/*
4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
*/
