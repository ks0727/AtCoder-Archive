#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<bool> appeared(3);
    int ans = -1;
    rep(i,n){
        if(s[i] == 'A') appeared[0] = true;
        if(s[i] == 'B') appeared[1] = true;
        if(s[i] == 'C') appeared[2] = true;
        rep(j,3){
            if(!appeared[j]) break;
            if(j == 2){
                ans = i+1;
                cout << ans << endl;
                return 0;
            } 
        }
    }
}