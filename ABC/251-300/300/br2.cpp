#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> a(h),b(h);
    rep(i,h) cin >> a[i];
    rep(i,h) cin >> b[i];
    rep(s,h){
        rep(t,w){
            bool isdone = false;
            rep(i,h){
                if(isdone) break;
                rep(j,w){
                    if(a[(i+s)%h][(j+t)%w] != b[i][j]){
                        isdone = true;
                        break;
                    }
                    if(i == h-1 &&  j == w-1){
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}