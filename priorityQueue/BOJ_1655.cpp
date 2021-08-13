#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define VMAX 1001
#define INF 987654321

using namespace std;

int main(){
  int n; cin >> n;
  int a[100000];
  priority_queue<int> minq, maxq; // 
  for(int i=0; i<n; i++) scanf("%d", &a[i]);

  for(int i=0; i<n; i++){
    int x = a[i];
    if(maxq.empty()){
      maxq.push(x);
    }else{
      if(x > maxq.top()){
        minq.push(-x);
      }else{
        maxq.push(x);
      }
    }

    if(maxq.size() == minq.size() + 2){ // maxq 원소가 2개 더 많으면 한개 옮기기
      minq.push(-maxq.top());
      maxq.pop();
    }
    if(maxq.size() + 1 == minq.size()){ // minq 원소가 1개 더 많으면 한개 옮기기 max=min로 맞추기위해
      maxq.push(-minq.top());
      minq.pop();
    }
//maxq를 출력하도록 q를 조작하기 무조건 size가 max = min+1 이나 max=min 이 되어야 함
    printf("%d\n", maxq.top()); //
  }
}
