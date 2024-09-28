#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int m;
    cin >> m;
    vector<int> a;
    int cnt = 0;
    while(m != 0){
        int x = m%3;
        a.push_back(x);
        m /= 3;
    }
    //reverse(a.begin(),a.end());
    vector<int> ans;
    rep(i,a.size()){
        if(a[i] == 0) continue;
        if(a[i] == 1){
            ans.push_back(i);
        }else{
            ans.push_back(i);
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(int x : ans) cout << x << ' '; cout << endl;
    return 0;
}