#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    vector<bool> exist(3);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans;
    rep(i,n){
        if(s[i] == 'A') exist[0] = true;
        if(s[i] == 'B') exist[1] = true;
        if(s[i] == 'C') exist[2] = true;
        if(exist[0] && exist[1] && exist[2]){
            ans = i+1;
            break;
        }
    }
    cout << ans << endl;
}