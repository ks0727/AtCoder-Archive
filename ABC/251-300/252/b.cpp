#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<int,int>;

int main(){
    int n,k; cin >> n >> k;
    vector<P> a(n);
    rep(i,n) cin >> a[i].first, a[i].second = i;
    sort(a.begin(),a.end());
    set<int> st;
    rep(i,k){
        int b;
        cin >> b; b--;
        st.insert(b);
    }
    int mx = a[n-1].first;

    while(a.back().first == mx){
        int id = a.back().second;
        a.pop_back();
        if(st.count(id)){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}