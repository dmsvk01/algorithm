#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a,b;
int n,m,x;

int lower_bound(int key){
    int start = 0, end = n;
    int mid;
    while(end - start > 0){
        mid = (start + end) / 2;
        if(a[mid] >= key) end = mid;
        else start = mid + 1;
        
    }
    return end;
}

int upper_bound(int key){
    int start = 0, end = n;
    int mid;
    while(end - start > 0){
        mid = (start + end) / 2;
        if(a[mid] > key) end = mid;
        else start = mid + 1;
    }
    return end;
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
        printf("%d ", upper_bound(b[i]) - lower_bound(b[i]));
    }
    return 0;
}
