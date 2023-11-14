#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int> > data(10,vector<int>(n+1));
    map<string,int> mp;
    string zero = "0000000000";
    mp[zero]++;
    for(int i=1;i<=(n);i++){
        int tg = s[i-1] - '0';
        rep(j,10){
            data[j][i] = data[j][i-1];
        }
        if(data[tg][i] == 0) data[tg][i] = 1;
        else data[tg][i] = 0;
        string t = "";
        rep(j,10){
            t += data[j][i] + '0';
        }
        mp[t]++;
    }
    ll ans = 0;
    for(auto [s,cnt] : mp){
        ans += (ll)cnt*(cnt-1)/2;
    }
    cout << ans << endl;
}