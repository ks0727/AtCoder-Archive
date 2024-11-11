#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int n;
    string s;
    cin >> n >> s;
    reverse(s.begin(),s.end());
    int mx = n+50;
    vector<ll> d(mx);
    ll sum = 0;
    for(int i=n-1;i>=0;i--){
        sum += (s[i]-'0')*(n-i);
        d[i] = sum;
    }
    //繰り上がりの処理を先に書いておく
    rep(i,mx-1){
        d[i+1] += d[i]/10;
        d[i]%=10; 
    }
    //末尾の0を消しておく
    while(d.back() == 0) d.pop_back();
    reverse(d.begin(),d.end());
    for(int digit : d) cout << digit;
    cout << endl;
    return 0;
}