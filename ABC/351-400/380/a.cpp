#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    vector<int> cnt(3);
    string s;
    cin >> s;
    rep(i,s.size()){
        if(s[i] != '1' && s[i] != '2' && s[i] != '3'){
            cout << "No" << endl;
            return 0;
        }else{
            int d = s[i] - '1';
            cnt[d]++;
        }
    }
    rep(i,3){
        if(cnt[i] != i+1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}