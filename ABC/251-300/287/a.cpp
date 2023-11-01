#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    int agree = 0;
    rep(i,n){
        string s;
        cin >> s;
        if(s == "For") agree++;
    }
    if(agree * 2 >= n) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}