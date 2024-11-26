#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> one(n),two(n);
    vector<int> mid;
    rep(i,n){
        if(s[i] == '1') one[i] = 1;
        else if(s[i] == '2') two[i] = 1;
        else mid.push_back(i);
    }
    vector<int> so(n+1),st(n+1);
    rep(i,n){
        so[i+1] = so[i]+one[i];
        st[i+1] = st[i]+two[i];
    }
    while(q--){
        int L,R;
        cin >> L >> R;
        L--; R--;
        int lb = L,rb= R;
        while(rb-lb > 1){
            int m = (rb+lb)/2;
            int cnt_one = so[m+1]-so[lb];
            int cnt_two = st[rb+1]-st[m];
            if(cnt_one >= cnt_two) rb = m;
            else lb = m;
        }
        int x = rb;
        auto it = lower_bound(mid.begin(),mid.end(),x);
        int ans = 0;
        int now = 0;
        int left = it - mid.begin();
        int right = mid.end()-it;
        left = min(left,3);
        right = min(right,3);
        //cout << L << ' ' << *it << ' ' << R << endl;
        auto f = [&](auto it, int d){
            auto it2 = prev(it,d);
            if(L <= *it2 && *it2 <= R){
                int cnt_one = so[*it2+1] - so[L];
                int cnt_two = st[R+1] - st[*it2];
                now = min(cnt_one,cnt_two);
                return now;
            }else{
                return 0;
            }
        };
        for(int i=-left;i<=right;i++){
            now = max(now,f(it,i));
        }
        if(now == 0) cout << 0 << endl;
        else cout << now*2 + 1 << endl;
    }
    return 0;
}