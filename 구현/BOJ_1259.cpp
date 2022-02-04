#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    while(1){
        string a;
        bool pass= true;
        cin >> a;
        if(a == "0") return 0;
        for(int i=0; i<a.length()/2; i++){
            if(a[i] != a[a.length()-1-i]){
                pass = false;
            }
        }
        if(pass) printf("yes\n");
        else printf("no\n");
    }
    
    
    return 0;
}
