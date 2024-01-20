#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll n;
    cin >> n;
    int digit = 0;
    ll now = 5;
    while(n < now){
        now *= 5;
        digit++;
    }
    cout << digit << endl;
    return 0;
}