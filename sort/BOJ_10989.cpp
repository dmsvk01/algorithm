#include <iostream>

using namespace std;

int main(){
  int n; cin >> n;
  int input[10001]={0};
  for(int x,i=0; i<n; i++){
    scanf("%d", &x);
    input[x]++;
  }
  for(int i=1; i<10001; i++){
    int size = input[i];
    for(int j=0; j<size; j++){
      printf("%d\n", i);
    }
  }
}
/*
n 은 최대 천만
각 숫자는 최대 10000


10
5
2
3
1
4
2
3
5
1
7

*/
