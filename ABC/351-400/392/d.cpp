#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<int> k(n);
    vector<vector<int> > a(n);
    vector<map<int,double> > cnt(n);
    rep(i,n){
        cin >> k[i];
        a[i] = vector<int>(k[i]);
        rep(j,k[i]) cin >> a[i][j];
        rep(j,k[i]){
            cnt[i][a[i][j]]++;
        }
    }
    double ans = 0;
    rep(i,n){
        for(int j=i+1;j<n;j++){
            double now = 0;
            for(auto [val,c] : cnt[i]){
                if(!cnt[j].count(val)) continue;
                now += (double)cnt[i][val]/k[i]*cnt[j][val]/k[j];
            }
            ans = max(ans,now);
        }
    }
    printf("%.10f\n",ans);
    return 0;
}