#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> a,b;
    rep(i,n){
        ll A,B;
        cin >> A >> B;
        a.push_back(A);
        b.push_back(A+B);
    }
    auto f = [&](int i,int j)->bool{
        return (ll)a[i]*b[j] > (ll)a[j]*b[i];
    };
    vector<int> ans;
    rep(i,n) ans.push_back(i);
    stable_sort(ans.begin(),ans.end(),f);
    rep(i,n) cout << ans[i]+1 << ' ';
    return 0;
}