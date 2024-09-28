#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    int ans = 0;
    rep(i,n-2) if(s.substr(i,3) == "ABC") ans++;
    while(q--){
        int x; char c;
        cin >> x >> c; x--;
        int start = max(0,x-2);
        int end = min(start+3,n);
        for(int i=start;i<end;i++){
            if(s.substr(i,3) == "ABC") ans--;
        }
        s[x] = c;
        for(int i=start;i<end;i++){
            if(s.substr(i,3) == "ABC") ans++;
        }
        cout << ans << endl;
    }
    return 0;
}