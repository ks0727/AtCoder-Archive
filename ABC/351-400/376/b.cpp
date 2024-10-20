#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)


int main(){
    int n,q;
    cin >> n >> q;
    int l= 0,r=1;
    int ans = 0;
    while(q--){
        char h; int t;
        cin >> h >> t;
        t--;
        auto f = [&](int now,int target,int other){
            int cur = now;
            for(int i=1;i<=n;i++){
                cur++;
                cur %= n;
                if(cur == other) break;
                else if(cur == target){
                    ans += i;
                    return;
                }
            }
            cur = now;
            for(int i=1;i<=n;i++){
                cur--;
                cur += n;
                cur %= n;
                if(cur == other) break;
                else if(cur == target){
                    ans += i;
                    return;
                }
            }
        };
        if(h == 'L'){
            f(l,t,r);
            l = t;
        }else{
            f(r,t,l);
            r = t;
        }
    }
    cout << ans << endl;
    return 0;
}