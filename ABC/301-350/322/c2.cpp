#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    vector<int> ans(n);
    for(int i = m-1; i >= 0;i--){
        if(i == 0){
            int diff = a[0];
            int value = a[0]-1;
            if(diff <= 1) continue;
            while(diff > 0 && value > 0){
                ans[value - 1] = diff - 1;
                value--;
                diff--;
            }
        }
        ans[a[i]-1] = 0;
        int diff = a[i] - a[i-1];
        int value = a[i];
        if(diff <= 1) continue;
        while(diff > 0){
            ans[value] = diff - 1;
            value--;
            diff--;
        }
    }
    rep(i,n) cout << ans[i] << endl;
    return 0;
}