#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    map<string,int> mp;
    mp["AB"] = 1;
    mp["AE"] = 1;
    mp["AC"] = 2;
    mp["AD"] = 2;
    mp["BC"] = 1;
    mp["BD"] = 2;
    mp["BE"] = 2;
    mp["CD"] = 1;
    mp["CE"] = 2;
    mp["DE"] = 1;
    string s,t;
    cin >> s >> t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if(mp[s] == mp[t]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}