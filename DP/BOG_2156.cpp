#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n; cin >> n;
    int a[10001]={0};
    int dp[10001]={0};
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    dp[0] = 0;
    dp[1] = a[1];
    dp[2] = a[1] + a[2];
    for(int i=3; i<=n; i++){
        dp[i] = max({dp[i-3]+a[i-1]+a[i], dp[i-2]+a[i], dp[i-1]});
    }
    printf("%d\n", dp[n]);
}

/*
dp의 위력을 깨달았다.
항상 재귀로 가지치기하는 식으로 dp문제를 해결했었는데
점화식을 찾고 O(n)만에 답을 구할 수 있다는 것에 놀랐다.
더 dp 공부를 해야 겠다.
*/
