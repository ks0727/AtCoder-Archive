#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    int bar1 = -1,bar2 = -1,key = -1;
    string s;
    cin >> s;
    rep(i,n){
        if(s[i] == '*') key = i;
        if(bar1 == -1 && s[i] == '|') bar1 = i;
        if(bar1 != -1 && s[i] == '|') bar2 = i;
    }
    if(bar1 < key && key < bar2) cout << "in" << endl;
    else cout << "out" << endl;
    return 0;
}