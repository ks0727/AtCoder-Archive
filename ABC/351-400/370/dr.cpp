#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int h,w,q;
    cin >> h >> w >> q;
    vector<vector<int> > rows(h),cols(w);
    rep(i,h)rep(j,w){
        rows[i].push_back(j);
        cols[j].push_back(i);
    }
    while(q--){
        int r,c;
        cin >> r >> c;
        r--; c--;
        auto del = [&](vector<int> &arr_r, vector<int> &arr_c, int rx, int cx){
            auto it = lower_bound(arr_r.begin(),arr_r.end(),cx);
            if(it != arr_r.begin()){
                if(*it == cx){
                    arr_r.erase(it);
                    if(find(cols[*it].begin(),cols[*it].end(),rx) != cols[*it].end()){
                        cols[*it].erase(find(cols[*it].begin(),cols[*it].end(),rx));
                    }
                    return;
                }else{
                    it--;
                    if(it != arr_r.begin()){
                        arr_r.erase(it);
                        if(find(cols[*it].begin(),cols[*it].end(),rx) != cols[*it].end()){
                        cols[*it].erase(find(cols[*it].begin(),cols[*it].end(),rx));
                        }
                    }
                }
            }
            auto it2 = upper_bound(arr_r.begin(),arr_r.end(),cx);
            if(it2 != arr_r.end()){
                arr_r.erase(it2);
                if(find(cols[*it2].begin(),cols[*it2].end(),rx) != cols[*it2].end()){
                    cols[*it2].erase(find(cols[*it2].begin(),cols[*it2].end(),rx));
                }
            }
            auto it3 = lower_bound(arr_c.begin(),arr_c.end(),rx);
            if(it3 != arr_c.begin()){
                it3--;
                if(it3 != arr_c.begin()){
                    arr_c.erase(it3);
                    if(find(rows[*it3].begin(),rows[*it3].end(),cx) != rows[*it3].end()){
                        rows[*it3].erase(find(rows[*it3].begin(),rows[*it3].end(),cx));
                    }
                }
            }
            auto it4 = upper_bound(arr_c.begin(),arr_c.end(),rx);
            if(it4 != arr_c.end()){
                arr_c.erase(it4);
                if(find(rows[*it4].begin(),rows[*it4].end(),cx) != rows[*it4].end()){
                    rows[*it4].erase(find(rows[*it4].begin(),rows[*it4].end(),cx));
                }
            }
            return;
        };
        del(rows[r],cols[c],r,c);
    }
    int ans = 0;
    rep(i,w) ans += cols[i].size();
    cout << ans << endl;
    return 0;
}