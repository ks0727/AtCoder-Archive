#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;

int main(){
    ll l,r; cin >> l >> r;
    vector<ll> x_2;
    ll now = 1;
    rep(i,61){
        x_2.push_back(now);
        now *= 2;
    }
    int start_idx = lower_bound(x_2.begin(),x_2.end(),l)-x_2.begin();
    ll start = *lower_bound(x_2.begin(),x_2.end(),l);
    int end_idx = upper_bound(x_2.begin(),x_2.end(),r) - x_2.begin()-1;
    ll end = x_2[end_idx];
    ll first = (start-l);
    while (first>0)
    {
        cout << l << ' ' << l+first << endl;
        l = l+first;
        first/=2;
    }
    while(start_idx<end_idx){
        cout << x_2[start_idx] << ' ' << x_2[start_idx+1] << endl;
        start_idx = start_idx+1;
    }
    ll last = (r - end)/2*2;
    while (last>0)
    {
        cout << end << ' ' << end+last << endl;
        end = end+last;
        last/=2;
    }
    return 0;
}