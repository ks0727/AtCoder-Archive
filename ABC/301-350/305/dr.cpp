#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> s(n);
    s[0] = a[0];
    for(int i=1;i<(n);i++){
        if(i%2 == 1) s[i] += s[i-1];
        else s[i] += a[i] - a[i-1] + s[i-1];
    }
    int q;
    cin >> q;
    rep(qi,q){
        int l,r;
        cin >> l >> r;
        int li,ri;
        li= lower_bound(s.begin(),s.end(),l) - s.begin();
        ri = lower_bound(s.begin(),s.end(),r) - s.begin();
        ri--;
        int ans = s[ri] - s[li];
    }
}