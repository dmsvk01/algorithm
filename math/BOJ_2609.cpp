#include <iostream>

using namespace std;

int get_gcd(int a, int b){
    int mod;
    while(b){
        mod = a % b;
        a = b;
        b = mod;
    }
    return a;
}

int get_lcm(int a, int b, int gcd){
    return a * b / gcd;
}

int main()
{
    int a,b,gcd,lcm;
    cin >> a >> b;
    gcd = get_gcd(a,b);
    lcm = get_lcm(a,b,gcd);
    printf("%d\n%d",gcd, lcm);
    return 0;
}
