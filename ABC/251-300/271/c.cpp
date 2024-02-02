#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        a[i]--;
    }
    sort(a.begin(),a.end());
    vector<bool> have(n);
    rep(i,n) if(a[i] < n) have[a[i]] = true;
    int num = n;
    int i = 0;
    int ans = 0;
    while(num > 0 && i < n){
        if(have[i]){
            ans++;
            num--;
        }
        else{
            num -= 2;
            if(num >= 0) ans++;
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}