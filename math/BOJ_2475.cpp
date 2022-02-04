#include <iostream>

using namespace std;

int main()
{
    int a[5], res=0;
    for(int i=0; i<5; i++){
        scanf("%d", &a[i]);
    }
    for(int i=0; i<5; i++){
        res += a[i]*a[i];
    }
    cout << res%10;
    return 0;
}
