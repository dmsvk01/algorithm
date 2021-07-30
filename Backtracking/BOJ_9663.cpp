#include <iostream>

using namespace std;

int n, count=0;
int b[15]={0}; // max_N : 14

bool check(int pos){
    for (int i = 1; i < pos; i++) {
		if (b[pos] == b[i] || pos - i == abs(b[pos] - b[i])) {
			return false;
		}
	}
	return true;
}

void bt(int pos){
    if(pos==n+1){
        count++;
        return ;
    }
    
    for(int i=1; i<=n; i++){
        b[pos]=i;
        if(check(pos)==true){
            bt(pos+1);
        }
    }
    
    return ;
}

int main(){
    cin >> n;
    bt(1);
    printf("%d", count);
    return 0;
}
