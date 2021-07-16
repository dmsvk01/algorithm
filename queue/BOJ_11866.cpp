#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    int n, k; cin >> n >> k;
    for(int i=0; i<n; i++){
        v.push_back(i+1);
    }
    int index=0;
    cout << "<";
    while(!v.empty()){
        index+=k-1;
        index%=v.size();
        cout << v[index];
        v.erase(v.begin() + index);
        if(v.empty()==true){
            cout << ">";
        }else{
            cout << ", ";
        }
	}
}
