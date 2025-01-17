#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace atcoder;
int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    rep(i,n) cin >> a[i];
    fenwick_tree<int> cnt(n);
    rep(i,n){
        int need = (n-i-1);
        int get = i;
        int cannot = cnt.sum(0,i+1);
        int change = -need + get - cannot;
        if(change >= 0){
            a[i] += change;
        }else{
            if(a[i]+change >= 0){
                a[i] += change;
            }else{
                int shortage = a[i] + change;
                int j = n + shortage;
                j = max(j,i+1);
                cnt.add(j,1);
                a[i] = 0;
            }
        }
    }
    rep(i,n) cout << a[i] << ' '; cout << endl;
    return 0;
}