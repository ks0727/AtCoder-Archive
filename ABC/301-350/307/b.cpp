#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            string moji;
            moji = s[i]+s[j];
            string re_moji = moji;
            reverse(moji.begin(),moji.end());
            if(moji == re_moji){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}