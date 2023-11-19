#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<char,int> > d;
    d.emplace_back(s[0],0);
    //Run-Length Encoding (RLE)
    for(char c : s){
        if(d.back().first == c) d.back().second++;
        else d.emplace_back(c,1);
    }
    vector<int> mx(26);
    for(auto [c,len] : d){
        mx[c-'a'] = max(mx[c-'a'],len);
    }
    int ans = 0;
    for(int len : mx) ans += len;
    cout << ans << endl;
    return 0;
}