#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    string s;
    cin >> n >> s;
    string ans = "";
    rep(i,n){
        if(s[i] == 'n' && s[i+1] == 'a'){
            ans+= "nya";
            i++;
        }else{
            ans += s[i];
        }
    }
    cout << ans << endl;
    return 0;
}