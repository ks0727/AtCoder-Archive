#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    const int M = 1e6+1;
    vector<int> freq(M+1, 0);
    rep(i,n){
        cin >> a[i];
        freq[a[i]]++;
    }
    vector<int> cnt(M);
    for (int d = 1; d <= M; d++){
        for (int m = d; m <= M; m += d){
            cnt[d] += freq[m];
        }
    }
    
    vector<int> now(M+1);
    for (int d = M; d >= 1; d--){
        if(cnt[d] >= k){
            for (int m = d; m <= M; m += d){
                if(now[m] == 0) now[m] = d;
            }
        }
    }
    rep(i,n) cout << now[a[i]] << endl;
    return 0;
}
