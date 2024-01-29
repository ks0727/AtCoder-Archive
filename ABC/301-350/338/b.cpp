#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    vector<int> a(26);
    rep(i,s.size()){
        a[s[i]-'a']++;
    }
    int num  = -1;
    rep(i,26){
        num = max(num,a[i]);
    }
    rep(i,26){
        if(a[i] == num){
            char ans = 'a'+i;
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}