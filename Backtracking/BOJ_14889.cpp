#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int s[21][21]={0};
int c[21]={0};
int n, result=987654321;

void bt(int depth, int pos, int c[]){
    if(depth == n/2){
        for(int i=1; i<=n; i++){
            //printf("%d ", c[i]);
        }
        //printf("\n");
        int asum=0, bsum=0;
        for(int i=1; i<=n-1; i++){
            if(c[i]==1){
                for(int j=i+1; j<=n; j++){
                    if(c[j]==1){
                        asum = asum + s[i][j] + s[j][i];
                    }
                }
            }else{
                for(int j=i+1; j<=n; j++){
                    if(c[j]==0){
                        bsum = bsum + s[i][j] + s[j][i];
                    }
                }
            }
        }
        result = min(result, abs(bsum - asum));
        return ;
    }
    if(pos > n) return ;
    c[pos]=0;
    bt(depth, pos+1, c);
    c[pos]=1;
    bt(depth+1, pos+1, c);
    c[pos]=0;
    return ;
}

int main()
{   
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &s[i][j]);
        }
    }
    bt(0,1, c);
    printf("%d", result);
    return 0;
}
/*
4
0 1 2 3
4 0 5 6
7 1 0 2
3 4 5 0
*/
