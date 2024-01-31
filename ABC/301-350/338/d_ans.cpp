#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> x(m);
    rep(i,m){
        cin >> x[i];
        x[i]--;
    }
    vector<int> d(n+1); //imos法を用いるために長さがn+1の配列を用意しておく
    auto add = [&](int l,int r, int x){
        d[l] += x;
        d[r] -= x;
    };
    rep(i,m-1){
        int s = x[i], t = x[i+1];
        if(s > t) swap(s,t);
        int a = t-s, b = n-a;
        add(0,s,a);
        add(s,t,b);
        add(t,b,a);
    }     
    rep(i,n) d[i+1] += d[i];
    int ans = *min_element(d.begin(),d.begin()+n);
    cout << ans << endl;
    return 0;
}