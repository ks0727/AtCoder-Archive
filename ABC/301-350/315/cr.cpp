#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    map<int,vector<int>> mp;
    rep(i,n){
        int f,s;
        cin >> f >> s;
        mp[f].push_back(s);
    }
    int mx = -1;
    int mindex = -1;
    for(auto [fla,arr] : mp){
        sort(arr.rbegin(),arr.rend());
        int most_fla = arr[0];
        if(mx < most_fla){
            mx = most_fla;
            mindex = fla;
        }
    }   
    int ans = -1;
    for(auto [fla,arr] : mp){
        if(fla == mindex) continue;
        sort(arr.rbegin(),arr.rend());
        ans = max(ans,mx+arr[0]);
    }
    if(mp[mindex].size() != 0){
        sort(mp[mindex].rbegin(),mp[mindex].rend());
        ans = max(ans,mp[mindex][0]+mp[mindex][1]/2);
    }
    cout << ans << endl;
}