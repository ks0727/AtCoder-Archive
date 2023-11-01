#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<pair<double,int> > data(n);
    rep(i,n){
        ll a,b;
        cin >> a >> b;
        long double p;
        p = 1.*a/(a+b);
        data[i].first = -p;
        data[i].second = i;
    }
    sort(data.begin(),data.end());
    rep(i,n) cout << data[i].second + 1 << ' ';
}