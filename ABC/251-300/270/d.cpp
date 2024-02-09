#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(k);
    rep(i,k) cin >> a[i];
    int now = k-1;
    int ta = 0,ao = 0;
    int taka = 1;
    while(now >= 0 && n > 0){
        if(taka == 0){
            if(n >= a[now]){
                ao += a[now];
                n -= a[now];
                taka++;
            }
            else now--;
        }else{
            if(n >= a[now]){
                ta += a[now];
                n -= a[now];
                taka--;
            }
            else now--;
        }
    }
    cout << ta << endl;
    return 0;
}