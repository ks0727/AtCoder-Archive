#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    bool ans = false;
    string s;
    cin >> s;
    int ri = 0;
    int mi = 0;
    rep(i,3){
        if(s[i] == 'R') ri = i;
        else  if(s[i] == 'M') mi = i;
    }
    if(ri < mi) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}