#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<string> w(n);
    rep(i,n) cin >> w[i];
    bool ans = false;
    rep(i,n){
        if(w[i] == "and" || w[i] == "not" || w[i] == "that" || w[i] == "the" || w[i] == "you"){
            ans = true;
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
