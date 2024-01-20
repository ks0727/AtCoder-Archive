#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    int ans = -1;
    int size = s.size();
    for(int i = size-1;i>=0;i--){
        if(s[i] == 'a'){
            ans = i;
            break;
        }
    }
    if(ans != -1) cout << ans + 1 << endl;
    else cout << ans << endl;
    return 0;
}