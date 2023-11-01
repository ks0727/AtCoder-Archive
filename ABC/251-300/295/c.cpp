#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    set<int> st;
    rep(i,n){
        st.insert(a[i]);
    }
    int st_size = st.size();
    rep(i,st_size){
        rep(j,n){
            int cnt = 0;
            if(st.count(a[j]) >= 2){
                
            }
        }
    }
}