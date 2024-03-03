#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,t;
    cin >> n >> t;
    vector<ll> point(n);
    map<ll,int> mp;
    mp[0] = n;
    set<ll> st;
    st.insert(0);
    int now = 1;
    rep(i,t){
        int a,b;
        cin >> a >> b;
        a--;
        mp[point[a]]--;
        if(mp[point[a]] == 0){
            st.erase(point[a]);
        }
        point[a] += b;
        mp[point[a]]++;
        st.insert(point[a]);
        cout << st.size() << endl;
    }
    return 0;
}