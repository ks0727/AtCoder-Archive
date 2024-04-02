#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> d(n);
    rep(i,n) cin >> d[i];
    int c = a+b;
    rep(i,n) d[i] %= c;
    sort(d.begin(),d.end());
    d.erase(unique(d.begin(),d.end()),d.end());
    if(d.size() < 2){
        cout << "Yes" << endl;
        return 0;
    }
    int mn = d[0];
    int mx = d[d.size()-1];
    int diff = mx-mn+1;
    if(diff <= a) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}