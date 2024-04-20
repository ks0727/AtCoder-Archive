#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<bool> ok(n);
    vector<P> ans;
    int key = 0;
    while(key < n){
        if(!ok[key] && a[key] != key+1){
            ans.emplace_back(key+1,a[key]);
            swap(a[key],a[a[key]-1]);
            ok[a[key]-1] = true;
        }else key++;
    }
    cout << ans.size() << endl;
    rep(i,ans.size()){
        if(ans[i].first >= ans[i].second) swap(ans[i].first,ans[i].second);
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
    return 0;
}