#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v(101,vector <int>(101,0)); // 관계 저장 벡터 
vector<int> visited(101,0); // 방문여부 확인 벡터 
int answer = -1; // 출력할 정답(촌수) 저장 변수 
bool answerFound = false;
int N;

void dfs(int start, int target, int count) {
  visited[start] = 1;
  if(start == target) {
    answer = count;
    answerFound = true;
    return;
  }
  
  for(int i = 1 ; i <= N ; i++) {
    if(v[start][i] !=0 && visited[i]==0){
      dfs(i, target, count + 1);
      if(answerFound) break;
    }
  }
  return;
}

int main() {
  int x, y;
  int A, B, M;

  scanf("%d", &N);
  scanf("%d %d", &A, &B);
  scanf("%d", &M);
  
  for(int i = 0 ; i < M ; i++) { // 주어진 부모 자식간의 관계 개수만큼 입력받아라 
    scanf("%d %d", &x, &y);
    v[x][y] = 1;
    v[y][x] = 1;
  } // 관계 선 연결

  dfs(A, B, 0);

  cout << answer;

  return 0;
}

/*
9
7 9
7
1 2
1 3
2 7
2 8
2 9
4 5
4 6
*/
