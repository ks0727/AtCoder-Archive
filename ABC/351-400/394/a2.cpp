#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    rep(i,s.size()) if(s[i] == '2') cnt++;
    cout << string(cnt,'2') << endl;
    return 0;
}