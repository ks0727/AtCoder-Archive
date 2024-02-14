#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    map<string,int> mp;
    mp["Monday"] = 5;
    mp["Tuesday"] = 4;
    mp["Wednesday"] = 3;
    mp["Thursday"] = 2;
    mp["Friday"] = 1;
    cout << mp[s] << endl;
    return 0;
}