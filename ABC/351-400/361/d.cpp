#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n;
    cin >> n;
    map<string,ll> mp;
    string s;
    cin >> s;
    string g;
    cin >> g;
    s += "..";
    g += "..";
    mp[s] = 0;
    queue<string> q;
    q.push(s);
    while(!q.empty()){
        string t = q.front(); q.pop();
        int h = 0;
        for(int i=0;i<n+1;++i) if(t[i] == '.'){
            h = i;
            break;
        } 
        for(int i=0;i<n+1;++i){
            if(i != h-1 && i != h && i != h+1){
                string nt = t;
                nt[h] = t[i];
                nt[h+1] = t[i+1];
                nt[i] = '.';
                nt[i+1] = '.';
                if(mp.count(nt)) continue;
                q.push(nt);
                mp[nt] = mp[t]+1;
            }
        }
    }
    if(mp.count(g)) cout << mp[g] << endl;
    else cout << -1 << endl;
    return 0;
}