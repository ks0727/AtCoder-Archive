#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    string s;
    cin >> s;
    int Q;
    cin >> Q;
    while(Q--){
        long long k;
        cin >> k;
        k--;
        bool flip = false;
        int idx = k%s.size();
        long long order = k/s.size();
        for(int i=60;i>=0;i--){
            if(order >= 1LL<<i){
                order -= 1LL<<i;
                flip ^= 1;
            }
        }
        char ans = s[idx];
        if(flip) ans ^= 32;
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}