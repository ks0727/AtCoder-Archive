#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    const ll INF = 1e18;
    ll ans = INF;
    for(int i=0;i<=(n);i++){
        string att = s;
        rep(ii,n){
            att[ii] = s[(ii+i)%n];
        }
        ll price = (ll)i*a;
        for(int j=0;j*2<(n);j++){
            if(att[j] != att[n-j-1]) price+=(ll)b;
        }
        ans = min(ans,price);
    }
    cout << ans << endl;
    return 0;
}