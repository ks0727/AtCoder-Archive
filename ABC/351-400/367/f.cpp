#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    map<int,vector<int> > mp1,mp2; 
    rep(i,n){
        mp1[a[i]].push_back(i);
        mp2[b[i]].push_back(i);
    } 
    while(q--){
        int l,r,L,R;
        cin >> l >> r >> L >> R;
        l--; L--; r--; R--;
        set<int> st;
        bool ok = true;
        for(int i=l;i<=r;i++){
            if(st.count(a[i])) continue;
            st.insert(a[i]);
            rep(j,mp1[a[i]].size()){
                if(mp1[a[i]][j] < l) continue;
                if(mp1[a[i]][j] > r) break;
                
            }
        }
    }
}