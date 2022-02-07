#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a,b;
int n,m,x;

int find(int key){
    int start = 0;
    int end = a.size()-1;
    int mid;
    while(end - start >= 0){
        mid = (start+end)/2;
        if(a[mid] == key){ // 찾았을 경우 숫자 카운팅 시작
            int i = +1;
            int count=0;
            while(a[mid + i] == a[mid]){
                count++;
                i++;
            }
            i=-1;
            while(a[mid + i] == a[mid]){
                count++;
                i--;
            }
            return count+1;
        }
        
        if(a[mid] > key) end = mid - 1;
        if(a[mid] < key) start = mid + 1;
    }
    // while문을 빠져나왔다 -> 못찾았다.
    return 0;
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        scanf("%d",&x);
        a.push_back(x);
    }
    cin >> m;
    for(int i=0; i<m; i++){
        scanf("%d",&x);
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    for(int i=0; i<b.size(); i++){
        printf("%d ", find(b[i]));
    }
    return 0;
}

/*
1. a 배열 정렬
2. for 문 돌면서 b의 각 배열값에 대해 이분탐색 실시.
2-1. 발견했다면 발견한 자리 양쪽으로 같은 숫자가 더 있는지 탐색하고 그 카운트 값을 출력
2-2. 발견못했다면 0출력

1<=n,m<=500000
50만 개면 배열로 선언하여서 
10
6 3 2 10 10 10 -10 -10 7 3
8
10 9 -5 2 3 4 5 -10

3 0 0 1 2 0 0 2

a  1 1 1 2 2 3 5 6 6 6 6 

  0 1 2 3 4 5 6
b 0 0 0 0 0 0 0
1을 찾는다. -> 있다.

존재하는 지만 찾는 것은 nlogm으로 쉬운데
어떻게 중복해서 개수를 찾을 것인가?

*/
