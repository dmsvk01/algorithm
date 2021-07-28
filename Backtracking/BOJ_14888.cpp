#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxv=-2100000000;
int minv=2100000000;
int n;
void bt(int depth, int result, int input[], int cal[]){
    if(depth==n-1){
        //printf("fin\b");
        maxv = max(maxv, result);
        minv = min(minv, result);
    }
    //printf("depth:%d\n",depth);
    //for(int i=0; i<4; i++) printf("%d ", cal[i]);
    //printf("\n");
    if(cal[0]!=0){
        cal[0]--;
        bt(depth+1, result+input[depth+1], input, cal);
        cal[0]++;
    }
    if(cal[1]!=0){
        cal[1]--;
        bt(depth+1, result-input[depth+1], input, cal);
        cal[1]++;
    }
    if(cal[2]!=0){
        cal[2]--;
        bt(depth+1, result*input[depth+1], input, cal);
        cal[2]++;
    }
    if(cal[3]!=0){
        cal[3]--;
        bt(depth+1, result/input[depth+1], input, cal);
        cal[3]++;
    }
}

int main()
{   
     cin >> n;
    int input[n];
    int cal[4]={0};
    for(int i=0; i<n; i++){
        cin >> input[i];
    }
    for(int i=0; i<4; i++){
        cin >> cal[i];
    }
    bt(0,input[0],input, cal);
    printf("%d\n%d\n", maxv, minv);
}
