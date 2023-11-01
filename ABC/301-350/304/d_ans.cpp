#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int w,h,n;
    cin >> w >> h >> n;
    vector<int> p(n),q(n);
    rep(i,n) cin >> p[i] >> q[i];
    int A,B;
    cin >> A >> B;
    vector<int> a(A),b(B);
    rep(i,A) cin >> a[i];
    rep(i,B) cin >> b[i];
    map<P,int> mp;
    rep(i,n){
        int x = lower_bound(a.begin(),a.end(),p[i]) - a.begin();
        int y = lower_bound(a.begin(),a.end(),q[i]) - a.begin();
        mp[P(x,y)]++;
    }
    int m = n,M = 0;
    for(auto e : mp){
        m = min(m,e.second);
        M = max(M,e.second);
    }
    if(mp.size() < (long long)(A+1)*(B+1)) m = 0;
    printf("%d %d\n",m,M);
    return 0;
}