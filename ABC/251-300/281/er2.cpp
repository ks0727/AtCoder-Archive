#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b(m);
    rep(i,m) b[i] = a[i];
    sort(b.begin(),b.end());
    if(k == m){
        int now = 0;
        rep(i,m) now += b[i];
        rep(i,n-m+1){
            cout << now << ' ';
            now -= a[i];
            now += a[i+m];
        }
        cout << endl;
        return 0;
    }else{
        int now = 0;
        rep(i,k) now += b[i];
        int kp1 = b[k];
        rep(i,n-m+1){
            cout << now << ' ';
            if(a[i] < kp1){
                if(a[i+m] < kp1){
                    now += a[i+m]-a[i];
                }else if(a[i+m] == kp1){
                    now -= a[i];
                }else{
                    
                }
            }
        }
    }
}