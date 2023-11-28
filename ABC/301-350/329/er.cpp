#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    string t;
    cin >> t;
    queue<int> q;
    rep(i,n-m+1){
        string ns = s.substr(i,m);
        if(ns == t) q.push(i);
    }
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int i=v;i<=v+m-1;i++){
            if(s[i] == '#') continue;
            s[i] = '#';
        }
        for(int i=v-m+1;i<=v+m-1;i++){
            if(i < 0 || i > n-m) continue;
            string ns = s.substr(i,m);
            if(ns == string(m,'#')) continue;
            rep(j,m){
                if(ns[j] != t[j] && ns[j] != '#') break;
                if(j == m-1) q.push(i);
            }
        }
    }
    string a(n,'#');
    if(s == a) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}