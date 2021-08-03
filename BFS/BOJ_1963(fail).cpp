#include <iostream>
#include <queue>
#include <cstring>
#define VMAX 10001

using namespace std;

int main()
{   
    bool era[VMAX];
    for(int i=0; i<VMAX; i++) era[i] = true;
    for(int i=2; i<VMAX; i++){
        for(int j=2; i*j< VMAX; j++){
            era[i*j] = false;
        }
    }
    int t; cin >> t;
    int start, end; cin >> start >> end;
    queue<pair<int, int>>q;
    q.push({start, 0});
    
    while(!q.empty()){
        int n = q.front().first;
        int c = q.front().second;
        q.pop();
        
        if(n == end){
            printf("%d", c);
            break;
        }
        
        string s = to_string(n);
        printf("s : ");
        for(int i=0; i<4; i++){
            printf("%c",s[i]);
        }
        printf("\n");
        for(int i=0; i<4; i++){
            char init = s[i];
            int nextn;
            for(int j=0; j<10; i++){
                if(i==0 && j==0) continue;
                if(init == j+'0') continue;
                s[i] = '0'+j;
                nextn = stoi(s);
                printf("i:%d, j:%d nextn : %d\n", i,j,nextn);
                if(era[nextn]==true){ // true면 소수인것
                    q.push({nextn, c+1});
                }
                s[i] = init;
            }
        }
    }
    printf("Impossible");

    return 0;
}

/*
3
1033 8179
1373 8017
1033 1033
*/
