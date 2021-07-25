#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
#define VMAX 401

using namespace std;

int n,m;
vector<pair<pair<int,int>,int>> a[VMAX];



int main(){
  int result=INF;
  cin >> n >> m;
  for(int x,y,w,i=0; i<m; i++){
    scanf("%d %d %d", &x, &y, &w);
    a[x].push_back({{x,y},w});
  }
}
/*

3
*/
