#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> sum(n);
    int now = 0;
    for(int i = 1;i<=(n);i++){
        if(s[i] == s[i-1]){
            now++;
        }
        sum[i] = now;
    }
    rep(qi,q){
        int l,r;
        cin >> l >> r;
        l--; r--;
        cout << sum[r] - sum[l] << endl; 
    }
    return 0;
}