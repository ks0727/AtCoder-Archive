#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<int,int>;

int main(){
    int n,h,w;
    cin >> n >> h >> w;
    set<P> st;
    rep(i,n){
        int r,c;
        cin >> r >> c;
        r--; c--;
        st.insert(P(r,c));
    }
    vector<vector<>>
    return 0;
}