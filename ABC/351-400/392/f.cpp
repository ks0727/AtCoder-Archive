#include <bits/stdc++.h>
using namespace std;
#include<atcoder/fenwicktree>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i],p[i]--;
    fenwick_tree<int> bit(n);
    rep(i,n) bit.add(i,1);
    vector<int> ans(n,-1);
    for(int i=n-1;i>=0;i--){
        int l = 0,r = n;
        while(r-l>1){
            int mid = (r+l)/2;
            if(bit.sum(0,mid) <= p[i]) l = mid;
            else r = mid;
        }
        ans[l] = i;
        bit.add(l,-1);
    }
    rep(i,n) cout << ans[i]+1 << ' '; cout << endl;
    return 0;
}