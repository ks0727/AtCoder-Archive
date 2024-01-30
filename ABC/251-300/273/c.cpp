#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> na = a;
    map<int,int> mp;
    rep(i,n){
        mp[na[i]]++;
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    reverse(a.begin(),a.end());
    rep(i,n){
        if(i >= a.size()) cout << 0 << endl;
        else{
            cout << mp[a[i]] << endl;
        }
    }
    return 0;
}