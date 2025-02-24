#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<string> ss;
    rep(i,n){
        string s;
        cin >> s;
        ss.push_back(s);
    }
    sort(ss.begin(),ss.end(),[&](const string a, const string b){
        return a.size() < b.size();
    });
    rep(i,ss.size()) cout << ss[i];
    cout << endl;
    return 0;
}