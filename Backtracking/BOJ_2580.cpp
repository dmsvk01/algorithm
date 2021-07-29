#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n=0;
int b[10][10]={0};
int result[10][10];
int fin=0;
void bt(int depth, int b[][10]){
    if(depth==n+1){
      fin=1;
      for(int i=1; i<=9; i++){
            for(int j=1; j<=9; j++){
                result[i][j] = b[i][j];
            }
        }
        return ;
    }
    
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            if(b[i][j]==0){
                for(int k=1; k<=9; k++){
                    if(fin) return ;
                    b[i][j]=0;
                    //k가 적합하면 k 넣고 back tracking
                    bool pass = true;
                    for(int x=1; x<=9; x++){
                        if(b[x][j]==k || b[i][x]==k){
                          pass = false;
                        }
                    }
                    for(int x=((i-1)/3)*3+1; x<=((i-1)/3)*3+3; x++){
                        for(int y=((j-1)/3)*3+1; y<=((j-1)/3)*3+3; y++){
                            if(b[x][y]==k){
                              pass = false;
                            }
                        }
                    }
                    b[i][j]=k;
                    if(pass) bt(depth+1, b);
                    b[i][j]=0;
                }
                return ;
            }
        }
    }
    return ;
}
int main()
{   
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            scanf("%d", &b[i][j]);
            if(b[i][j]==0) n++;
        }
    }
    bt(1, b);
    for(int i=1; i<=9; i++){
            for(int j=1; j<=9; j++){
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
}
