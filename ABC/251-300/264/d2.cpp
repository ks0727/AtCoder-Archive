#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    queue<string> q;
    map<string,int> mp;
    q.push(s);
    mp[s] = 0;
    while(!q.empty()){
        string ns = q.front(); q.pop();
        if(ns == "atcoder"){
            break;
        }
        rep(i,ns.size()-1){
            string t = ns;
            swap(t[i],t[i+1]);
            if(mp.count(t)) continue;
            mp[t] = mp[ns]+1;
            q.push(t);
        }
    }
    string atcoder = "atcoder";
    cout << mp[atcoder] <<  endl;
    return 0;
}