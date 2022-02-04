#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int> a,b;

int find(int key){
    int mid=0;
    int start = 0;
    int end = a.size()-1;
    
    while(end - start >= 0){
        mid = (start+end) / 2;
        if(key == a[mid]) return 1;
        if(key > a[mid]) start = mid + 1;
        if(key < a[mid]) end = mid - 1;
    }
    return 0;
}

int main()
{
    
    scanf("%d", &n);
    for(int x,i=0; i<n; i++){
        scanf("%d", &x);
        a.push_back(x);
    }
    scanf("%d", &m);
    for(int x,i=0; i<m; i++){
        scanf("%d", &x);
        b.push_back(x);
    }
    
    sort(a.begin(), a.end());
    
    for(int i=0; i<b.size(); i++){
        if(find(b[i])){
            printf("1\n");
        }else{
            printf("0\n");
        }
    }
    

    return 0;
}
