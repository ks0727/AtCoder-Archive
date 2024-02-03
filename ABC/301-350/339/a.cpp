#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    string ans = "";
    bool start =false;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i] == '.') break;
        ans += s[i];
    }
    reverse(ans.begin(),ans.end());
    cout << ans <<endl;
    return 0;
}