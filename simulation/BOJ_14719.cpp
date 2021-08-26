#include <iostream>
#define VMAX 500

using namespace std;

int main()
{
    int result=0;
    int input[VMAX];
    int b[VMAX][VMAX]={0};
    int h,w; cin >> h >> w;
    for(int i=0; i<w; i++) cin >> input[i];
    
    for(int i=0; i<w; i++){
        for(int j=0; j<input[i]; j++){
            b[j][i]=1;
        }
    }
    
    for(int i=0; i<h; i++){
        int find = false;
        int count=0;
        for(int j=0; j<w; j++){
            if(find==true && b[i][j]==0) count++;
            if(find==true && b[i][j]==1){
                result+=count;
                count=0;
            }
            if(find==false && b[i][j]==1) find=true;;
        }
    }
    
    cout << result;
    
    return 0;
}
