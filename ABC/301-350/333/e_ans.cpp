#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> event;
    rep(i,n){
        int t,x;
        cin >> t >> x;
        if(t == 1) event.push_back(x);
        else event.push_back(-x);
    }
    reverse(event.begin(),event.end());
    vector<int> cnt(n+1);
    vector<int> ans;
    int now = 0, mx = 0;
    for(int x : event){
        if(x > 0){
            if(cnt[x] != 0){
                cnt[x]--;
                now--;
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }
        }else{
            cnt[-x]++;
            now++;
        }
        mx = max(mx,now);
    }
    if(now > 0){
        cout << -1 << endl;
    }else{
        cout << mx << endl;
        reverse(ans.begin(),ans.end());
        for(int x : ans) cout << x << ' ';
        cout << endl;
    }
    return 0;
}