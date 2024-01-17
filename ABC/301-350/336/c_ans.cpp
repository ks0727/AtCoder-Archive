#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll n;
    cin >> n;
    n--;
    string s;
    if(n == 0){ //n=0の時の例外処理
        cout << 0 << endl;
        return 0;
    }
    while(n){
        s += '0'+(n%5*2);
        n /= 5;
    }
    reverse(s.begin(),s.end());
    cout << s << endl;
    return 0;
}