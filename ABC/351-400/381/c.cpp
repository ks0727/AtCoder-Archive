#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a;
    rep(i,n) if(s[i] == '/') a.push_back(i);
    int ans = 0;
    vector<bool> seen(n);
    for(int x : a){
        if(seen[x]) continue;
        int l = x-1;
        int r = x+1;
        seen[x] = true;
        while(l>=0 && s[l] == '1'){
            seen[l] = true;
            l--;
        } 
        while(r<n&&s[r] =='2'){
            seen[r] = true;
            r++;
        }
        l++;
        r--;
        int now = min(x-l,r-x);
        ans = max(ans,now*2+1);
    }
    cout << ans << endl;
    return 0;
}