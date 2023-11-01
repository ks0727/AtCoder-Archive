#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    map<int,int> mp;
    rep(i,n){
        int color;
        cin >> color;
        mp[color]++;
    }
    int ans = 0;
    for(auto [color,count] : mp){
        while(mp[color] > 1){
            mp[color]-=2;
            ans++;
        }
    }
    cout << ans << endl;
}