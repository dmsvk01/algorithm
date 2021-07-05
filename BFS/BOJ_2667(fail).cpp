#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int input[25][25]={0,};
vector<int> result;
queue<pair<int, int>> q;
int v[25][25]={0,};
int n;

int bfs(int a, int b){
  int c=0;
  q.push(make_pair(a,b));
  while(!q.empty()){
    c++;
    int x = q.front().first;
    int y = q.front().second;
    printf("%d, %d\n", x,y);
    q.pop();
     // 방문을 안했고 집이있다면(input==1이라면)
    if(v[x-1][y]==0 && input[x-1][y] && x!=n-1){ // 아래
      v[x-1][y]=1;
      q.push(make_pair(x-1,y));
    }
    if(v[x+1][y]==0 && input[x+1][y] && x!=0){ // 위
      v[x+1][y]=1;
      q.push(make_pair(x+1,y));
    }
    if(v[x][y-1]==0 && input[x][y-1]  && y!=0){ // 왼쪽
      v[x][y-1]=1;
      q.push(make_pair(x,y-1));
    }
    if(v[x][y+1]==0 && input[x][y+1]  && y!=n-1){ // 오른쪽
      v[x][y+1]=1;
      q.push(make_pair(x,y+1));
    }
  }
  return c;
}

int main(){
  int count=0;
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> input[i][j];
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(input[i][j]==1){
        int x = bfs(i,j);
        result.push_back(x);
        count++;
      }
    }
  }
  sort(result.begin(), result.end(), greater<int>());
  
  printf("%d\n", count);
  
  for(int i=0; i<result.size(); i++)
    printf("%d\n", result[i]);
}


/*
5≤N≤25
1은 집이 있는 곳을, 0은 집이 없는 곳
1은 집
0은 집없음
-> 1을 찾는다. 그리고 찾은 1인덱스를 중심으로 bfs를 돌린다.
탐색이 1차례 완료되면 result에 단지수를 입력한다.
1이 없을때 까지 찾고 종료하낟.

7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

3
7
8
9

*/
