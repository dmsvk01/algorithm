#include <iostream>

using namespace std;

int main()
{
    int n, count=0;
    string a;
    cin >> n;
    
    for(int i=0; i<n; i++){
        count=0;
        cin >> a;
        for(int j=0; j<a.length(); j++){
            if(a[j] == '('){
                count++;
            }
            if(a[j] == ')'){
                count--;
                if(count<0) break;
            }
        }
        if(count==0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
