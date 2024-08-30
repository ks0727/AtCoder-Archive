#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    const int M = 100005;
    vector<int> g(M);
    vector<vector<int> > divs(M);

    for(int i=1;i<M;i++){
        for(int j=i*2;j<M;j+=i){
            divs[j].push_back(i);
        }
    }
    for(int i=1;i<M;i++){
        set<int> st;
        for(int d : divs[i]){
            st.insert(g[d]);
        }
        while(st.count(g[i])) g[i]++;
    }
    int n;
    cin >> n;
    vector<int> a(n);
    int x = 0;
    rep(i,n) cin >> a[i],x^=g[a[i]];
    if(x == 0) cout << "Bruno" << endl;
    else cout << "Anna" << endl;
    return 0;
}