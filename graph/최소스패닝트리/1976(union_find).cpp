#include <iostream>
#define VMAX 201
#define MMAX 1001

using namespace std;

int parent[VMAX];
int result[MMAX];
int n,m;

int getparent(int x){
  if(parent[x] == x) return x;
  return parent[x] = getparent(parent[x]);
}

void merge(int sa, int sb){
  int a = getparent(sa);
  int b = getparent(sb);

  if(a > b) parent[a] = b;
  else if(a < b) parent[b] = a;
}

int main(){
  cin >> n;
  cin >> m;

  for(int i=1; i<=n; i++) parent[i]=i;

  for(int i=1; i<=n; i++){
    for(int x,j=1; j<=n; j++){
      scanf("%d", &x);
      if(x==1) merge(i,j);
    }
  }
  
  for(int x,i=0; i<m; i++){
    scanf("%d", &result[i]);
  }

  int ans = getparent(result[0]);
  
  for(int i=0; i<m; i++){
    int a = getparent(result[i]);
    if(a!=ans){
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}

/*

3
3
0 1 0
1 0 1
0 1 0
1 2 3
만약 b[i][j]==1이면
i,j merge go


*/
