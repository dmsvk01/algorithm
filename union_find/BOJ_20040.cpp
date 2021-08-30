#include <iostream>

using namespace std;

int n,m;
int par[500000]={0};

int getpar(int x){
  if(par[x]==x) return x;
  return par[x] = getpar(par[x]);
}

int main(){
  cin >> n >> m;
  int result=0;
  for(int i=0; i<n; i++) par[i]=i;
  for(int x,y,i=0; i<m; i++){
    scanf("%d %d", &x, &y);
    int fx = getpar(x);   
    int fy = getpar(y);
    if(fx == fy && result==0){
      result = i+1;
    }
    par[fx] = fy;
  }
  if(result) cout << result;
  else cout << 0;
}
