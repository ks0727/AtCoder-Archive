#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,q;
    cin >> n >> q;
    vector<ll> a(n);
    unordered_set<int> st;
    ll s = 0;
    rep(qi,q){
        int x;
        cin >> x;
        --x;
        if(st.count(x)){
            a[x] += s;
            st.erase(x);
        }else{
            a[x] -= s;
            st.insert(x);
        }
        s += st.size();
    }
    for(int x : st) a[x] += s;
    rep(i,n) cout << a[i] << ' ';
    cout << endl;
    return 0;
}