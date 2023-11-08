#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> s(n/2);
    rep(i,n/2) s[i] = a[2*(i+1)] - a[2*(i+1)-1];
    int q;
    rep(qi,q){
        int l,r;
        cin >> l >> r;
        int left = upper_bound(a.begin(),a.end(),l) - a.begin() - 1;
        int right = upper_bound(a.begin(),a.end(),r) - a.begin() - 1;
        if(left < 0 || right < 0){
            cout << 0 << endl;
            continue;
        }
        if(left%2 == 0 && right %2 == 0){
            if(left == right){
                cout << 0 << endl;
                continue;
            }else{
                int ans = 0;
                for(int k = left/2+1;k<=right/2;k++){
                    ans += s[k];
                }
                cout << ans << endl;
                continue;
            }
        }
        if(left % 2 == 1 && right % 2 == 1){
            if(left == right){
                cout <<r - l << endl;
                continue;
            }else{
                int ans = 0;
                for(int k = left/2+1;k<right/2;k++){
                    ans += s[k];
                }
                ans += l - a[left];
                ans += r - a[right];
                cout << ans << endl;
                continue;
            }
        }
        if(left %2 == 1 && right %2 == 0){
            int ans = 0;
            ans += r - a[right];
            for(int k = left/2;k<right/2;k++){
                ans += s[k];
            }
            cout << ans << endl;
            continue;
        }
        if(left % 2 == 0 && right %2 == 1){
            int ans = 0;
            ans += l - a[left];
            for(int k = left/2+1;k<right/2;k++){
                ans += s[k];
            }
            cout << ans << endl;
        }
    }
    return 0;
}