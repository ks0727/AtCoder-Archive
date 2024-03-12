#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    vector<int> a(5);
    rep(i,5) cin >> a[i];
    vector<int> cnt(14);
    rep(i,5) cnt[a[i]]++;
    bool ans = true;
    rep(i,13){
        if(cnt[i] != 0 && cnt[i] != 2 && cnt[i] != 3) ans = false;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}