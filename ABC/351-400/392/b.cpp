#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    set<int> st;
    int n,m;
    cin >> n >> m;
    rep(i,n) st.insert(i+1);
    rep(i,m){
        int a;
        cin >> a;
        st.erase(a);
    }
    cout << st.size() << endl;
    for(int x : st) cout << x << ' '; cout << endl;
    return 0;
}