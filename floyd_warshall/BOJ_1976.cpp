#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define VMAX 200
#define INF 987654321

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    int b[VMAX][VMAX]={0};
    int s[1000]={0};
    bool pass = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &b[i][j]);
            if(i==j) b[i][j]=1; // ***
        }
    }
    for(int i=0; i<m; i++)
        scanf("%d", &s[i]);
        
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(b[i][j]==0 && b[i][k]==1 && b[k][j]==1){
                    b[i][j]=1;
                }
            }
        }
    }
    for(int i=0; i<m-1; i++){
        int x = s[i]-1;
        int y = s[i+1]-1;
        if(b[x][y]==0){
            pass=false;
        }
    }
    if(pass){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}
