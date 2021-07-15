#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;


int n;
int heap[100002];
int size=0;

int h_empty();
int h_top();
int h_pop();
int h_push();


int main(){
  cin >> n;
  for(int x,i=0; i<n; i++){
    scanf("%d",&x);
    if(x==0){
      if(h_empty()==true){
        printf("0\n");
      }else{
        printf("%d\n", h_top());
        h_pop();
      }
    }else{
      h_push(x);
    }
  }
  return 0;
}
/*
9
0
12345678
1
2
0
0
0
0
32

0
1
2
12345678
0
*/
