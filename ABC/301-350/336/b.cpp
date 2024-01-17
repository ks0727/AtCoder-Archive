#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    string s = "";
    while(n > 0){
        int bit = n & 1;
        s += (bit == 0 ? '0':'1');
        n >>= 1;
    }
    int size = s.size();
    int ans = 0;
    reverse(s.begin(),s.end());
    for(int i=size-1;i>=0;i--){
        if(s[i] != '0') break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}