#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    int ans = 0;
    int dango = 0;
    bool isdango = false;
    int stick = 0;
    int mochi  = 0;
    rep(i,n){
        if(s[i] == '-') stick++;
        else mochi++;
    }
    if(stick > 0 && mochi > 0) isdango = true;
    if(!isdango){
        cout << -1 << endl;
        return 0;
    }
    rep(i,n){
        if(s[i] == '-') dango = 0;
        else dango++;
        ans = max(ans,dango);
    }
    cout << ans << endl;
    return 0;
}