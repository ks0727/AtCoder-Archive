#include <bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    const int M = 5e5 + 5;
    vector<int> a(M+1);
    rep(i,M+1) a[i] = i;
    fenwick_tree<long long> bit(M);
    rep(i,n){
        int l,r; cin >> l >> r;
        auto f = [&](int x){
            int lb = 0, rb = M;
            while(rb-lb>1){
                int mid = (rb+lb)/2;
                if(a[mid]+bit.sum(0,mid+1) < x) lb = mid;
                else rb = mid;
            }
            return rb;
        };
        int left = f(l);
        int right = f(r+1)-1;
        //cout << left << ' ' << right << endl;
        //rep(i,10) cout << a[i]+bit.sum(0,i+1) << ' '; cout << endl;
        bit.add(left,1);
        bit.add(right+1,-1);
    }
    //rep(i,10) cout << a[i]+bit.sum(0,i+1) << ' '; cout << endl;
    int Q; cin >> Q;
    while (Q--)
    {
        int x;
        cin >> x;
        cout << a[x] + bit.sum(0,x+1) << endl;
    }
    return 0;
}