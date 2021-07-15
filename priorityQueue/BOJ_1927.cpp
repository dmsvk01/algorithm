#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
  priority_queue<int, vector<int>, greater<int>> q;
  int n; cin >> n;
  for(int x,i=0; i<n; i++){
    scanf("%d", &x);
    if(x!=0){
      q.push(x);
    }else{
      if(q.empty()==true){
        printf("0\n");
      }else{
        printf("%d\n", q.top());
        q.pop();
      }
    }
  }

}
