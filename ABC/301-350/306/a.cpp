#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    rep(i,n){
        ans.push_back(s[i]);
        ans.push_back(s[i]);
    }
    cout << ans << endl;
}