#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<char,int> > rle;
    int ans = 0;
    rep(i,n){
        if(rle.size() > 0 && rle.back().first == s[i]) rle.back().second++;
        else rle.emplace_back(s[i],1);
        if(s[i] == '/') ans = 1;
    }
    rep(i,rle.size()-2){
        if(rle[i].first== '1'){
            int j = i+1;
            int k = i+2;
            if(rle[j].first != '/' ) continue;
            if(rle[j].second != 1) continue;
            if(rle[k].first != '2') continue;
            int now = min(rle[i].second,rle[k].second);
            ans = max(now*2+1,ans);
        }
    }
    cout << ans << endl;
    return 0;
}