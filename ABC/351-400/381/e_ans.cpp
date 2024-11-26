#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<int> > is(3);
    rep(i,n){
        int c = s[i]-'0';
        if(s[i]== '/') c = 0;
        is[c].push_back(i);
    }
    const int INF = 1001001001;
    auto getNext = [&](int c, int i, int x){
        if(x == 0) return i;
        auto &nis = is[c];
        int j = lower_bound(nis.begin(),nis.end(),i) - nis.begin();
        j += x-1;
        if(j < nis.size()) return nis[j]+1;
        return INF;
    };
    rep(qi,q){
        int l,r;
        cin >> l  >> r;
        l--;
        auto f = [&](int k){
            int i = l;
            i = getNext(1,i,k);
            i = getNext(0,i,1);
            i = getNext(2,i,k);
            return i <= r;
        };
        int lb=-1,rb= n;
        while(rb - lb > 1){
            int mid = (lb+rb)/2;
            if(f(mid)) rb = mid;
            else lb = mid;
        }
        int ans = 0;
        if(lb == -1) ans = 0;
        else ans = lb*2+1;
        cout << ans << '\n';
    }
    return 0;
}