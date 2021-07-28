#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n=0;
int b[10][10]={0};

void bt(int depth, int b[][10]){
  printf("n: %d depth:%d\n", n,depth);
    if(depth==n+1){
        printf("--------------------\n");
        for(int i=1; i<=9; i++){
            for(int j=1; j<=9; j++){
                printf("%d ", b[i][j]);
            }
            printf("\n");
        }
        return ;
    }
    
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            if(b[i][j]==0){
                for(int k=1; k<=9; k++){
                    b[i][j]=0;
                    //k가 적합하면 k 넣고 back tracking
                    bool pass = true;
                    printf("i:%d j:%d k:%d\n",i,j,k);
                    for(int x=1; x<=9; x++){
                        if(b[x][j]==k || b[i][x]==k) pass = false;
                    }
                    for(int x=((i-1)/3)*3+1; x<=((i-1)/3 + 1)*3; x++){
                        for(int y=(j/3)*3+1; y<=(j/3 + 1)*3; y++){
                            if(b[x][y]==k) pass = false;
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
}
/*
0 3 5 4 6 9 2 7 8
7 8 2 1 0 5 6 0 9
0 6 0 2 7 8 1 3 5
3 2 1 0 4 6 8 9 7
8 0 4 9 1 3 5 0 6
5 9 6 8 2 0 4 1 3
9 1 7 6 5 2 0 8 0
6 0 3 7 0 1 9 5 2
2 5 8 3 9 4 7 6 0
*/
