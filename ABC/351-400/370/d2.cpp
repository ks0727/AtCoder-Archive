#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int h,w,q;
    cin >> h >> w >> q;
    vector<set<int> > rows(h),cols(w);
    const int INF = 1001001001;
    rep(i,h)rep(j,w){
        rows[i].insert(INF);
        rows[i].insert(-INF);
        rows[i].insert(j);
        cols[j].insert(INF);
        cols[j].insert(-INF);
        cols[j].insert(i);
    }

    auto del_row = [&](set<int> &st, int nr ,int c)->bool{
        if(st.count(c)){
            st.erase(c);
            cols[c].erase(nr);
            return true;
        }else{
            auto it = st.lower_bound(c);
            if(*it != -INF){
                it--;
                int val= *it;
                if(val != -INF){
                    st.erase(it);
                    if(cols[val].count(nr)) cols[val].erase(nr);
                }
            }
            auto it2 = st.upper_bound(c);
            int val = *it2;
            if(val != INF){
                st.erase(val);
                if(cols[val].count(nr)) cols[val].erase(nr);
            }
        }
        return false;
    };
    auto del_col = [&](set<int> &st, int nc ,int r){
        if(st.count(r)){
            st.erase(r);
            rows[r].erase(nc);
            return;
        }else{
            auto it = st.lower_bound(r);
            if(*it != -INF){
                it--;
                int val = *it;
                if(val != -INF){
                    st.erase(val);
                    if(rows[val].count(nc)) rows[val].erase(nc);
                }
            }
            auto it2 = st.upper_bound(r);
            if(*it2 != INF){
                int val = *it2;
                st.erase(val);
                if(rows[val].count(nc)) rows[val].erase(nc);
            }
        }
        return;
    };
    while (q--)
    {
        int i,j;
        cin >> i >> j;
        i--; j--;
        if(del_row(rows[i],i,j)) continue;
        del_col(cols[j],j,i);
    }
    int ans = 0;
    rep(i,h) ans += rows[i].size() -2;
    cout << ans << endl;
    return 0;
}