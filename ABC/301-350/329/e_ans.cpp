#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    string s,t;
    cin >> n >> m;
    cin >> s >> t;
    vector<bool> used(n);
    queue<int> q;
    auto push = [&](int i){
        if(i < 0 || i+m > n) return;
        if(used[i]) return;
        rep(j,m){
            if(s[i+j] != '?' && s[i+j] != t[j]) return;
        }
        used[i] = true;
        q.push(i);
    };
    rep(i,n-m+1) push(i);
    while(!q.empty()){
        int i = q.front(); q.pop();
        rep(j,m) s[i+j] = '?';
        for(int ni = i-m+1;ni<=i+m-1;ni++){
            push(ni);
        }
    }
    if(s == string(n,'?')) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}