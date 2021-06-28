#include <iostream>
#include <algorithm>

using namespace std;

int n,k;
int v[102], w[102];
int bt(int depth, int weight, int value){
  if(weight > k)
    return 0;
  if(depth == n)
    return value;
  
  return max(bt(depth+1, weight+w[depth], value+v[depth]), bt(depth+1, weight,value));
}

int main(){
  cin >> n >> k;
  for(int i=0; i<n; i++){
    cin >> w[i] >> v[i];
  }
  
  cout << bt(0,0,0);
}
/*
4 16
2 40
5 30
10 50
5 10

*/
