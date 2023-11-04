#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    char a = 'A';
    int k;
    cin >> k;
    string ans = "";
    rep(i,k){
        ans += a;
        a++;
    }
    cout << ans << endl;
    return 0;
}