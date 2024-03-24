#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int b,w;
    cin >> w >> b;
    string s = "wbwbwwbwbwbw";
    int nw = w/7;
    int nb = b/5;
    int p = min(nw,nb);
    w -= p*7;
    b -= p*5;
    bool ans = false;
    rep(j,15){
        int now = 0;
        int cw = w, cb = b;
        while(cw > 0 || cb > 0){
            if(s[(now+j)%15] == 'b' && cb < 0) break;
            if(s[(now+j)%15] == 'w' && cw < 0) break;
            if(s[(now+j)%15] == 'b') cb--;
            else if(s[(now+j)%15] == 'w') cw--;
            now++;
        }
        if(cw == 0 && cb== 0){
            ans = true;
            break;
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}