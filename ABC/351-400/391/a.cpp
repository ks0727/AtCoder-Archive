#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    map<string,string> mp;
    mp["N"] = "S";
    mp["E"] = "W";
    mp["W"] = "E";
    mp["S"] = "N";
    mp["NE"] = "SW";
    mp["NW"] = "SE";
    mp["SE"] = "NW";
    mp["SW"] = "NE";
    string s;
    cin >> s;
    cout << mp[s] << endl;
    return 0;
}