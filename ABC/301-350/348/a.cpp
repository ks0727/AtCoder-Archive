#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    string ans = "";
    for(int i=1;i<(n+1);i++){
        if(i%3 == 0) ans += 'x';
        else ans += 'o';
    }
    cout << ans << endl;
    return 0;
}