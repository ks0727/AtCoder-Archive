#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,ll>;

ll square(int a){
    return (ll)a*a;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll sum = 0;
    sort(a.begin(),a.end());
    for(int i=0;i <= (n/2);i++){
        sum += square(a[i]+a[n-1-i]);
    }
    cout << sum << endl;
}