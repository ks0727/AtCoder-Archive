#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    map<int,int> mp;
    mp[n] = 0;
    vector<int> ans;
    rep(i,n){
        auto f = [&](auto f,int k, int now)->int{
            if(mp.count(k)) return mp[k];
            for(int i=k+1;i<n;i++) if(h[i]>now) return mp[k]=f(f,i,h[i])+1;
            return 0;
        };
        ans.push_back(f(f,i,0));
    }
    for(int x : ans) cout << x<< ' '; cout << endl;
    return 0;
}