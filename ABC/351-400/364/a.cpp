#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n;
    cin >> n;
    bool ate = false;
    bool ans = true;
    rep(i,n){
        string s;
        cin >> s;
        if(ate && s[1] == 'w' && i != n-1) ans = false;
        if(!ate && s[1] == 'w') ate = true;
        if(s[1] == 'a') ate = false;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}