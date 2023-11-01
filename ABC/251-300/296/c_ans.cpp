#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    bool ans = false;
    rep(i,n) cin >> a[i];

    set<int> st;
    rep(i,n) st.insert(a[i]);
    rep(i,n){
        int y = a[i] - x;
        if(st.count(y)) ans = true; 
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}