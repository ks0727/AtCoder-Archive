#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

bool isSame(string a, string b){
    string temp = b;
    reverse(temp.begin(),temp.end());
    if(a == temp) return true;
    else return false;
}

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int ans = 0;
    vector<bool> checked(n);
    rep(i,n){
        if(checked[i]) continue;
        rep(j,n){
            if(i == j) continue;
            if(checked[j]) continue;
            if(s[i] == s[j]){
                checked[j] = true;
                ans++;
            }
            else if(isSame(s[i],s[j])){
                checked[j] = true;
                ans++;
            } 
        }
    }
    cout << ans << endl;
    return 0;
}