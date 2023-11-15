#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
using ll = long long;

int main(){
    int w,h;
    cin >> w >> h;
    int n;
    cin >> n;
    vector<P> str(n);
    rep(i,n) cin >> str[i].first >> str[i].second;
    int A;
    cin >> A;
    vector<int> a(A+1);
    for(int i = 1;i<=(A);i++) cin >> a[i];
    int B;
    cin >> B;
    vector<int> b(B+1);
    for(int i = 1;i<=(B);i++) cin >> b[i];
    map<P,int> mp;
    rep(i,n){
        int x = lower_bound(a.begin(),a.end(),str[i].first) - a.begin();
        int y = lower_bound(b.begin(),b.end(),str[i].second) - b.begin();
        x--; y--;
        mp[P(x,y)]++;
    }
    const int INF = 1e9;
    int mn = INF;
    int mx = -1;
    for(auto [key,value] : mp){
        mn = min(mn,value);
        mx = max(mx,value);
    }
    if(mp.size() < (ll)(A+1)*(B+1)) mn = 0;
    cout << mn << ' ' << mx << endl;
    return 0;
}