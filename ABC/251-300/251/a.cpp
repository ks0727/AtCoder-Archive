#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    string s;
    cin >> s;
    string ans = "";
    while(ans.size() < 6){
        ans += s;
    }
    cout << ans << endl;
    return 0;
}