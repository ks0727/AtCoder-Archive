#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int n2 = 1<<n;
    vector<int> c(m);
    vector<char> r(m);
    vector<vector<int> > a(m);
    rep(i,m){
        int ci; cin >> ci;
        c[i] = ci;
        rep(j,ci){
            int aj; cin >> aj;
            aj--;
            a[i].push_back(aj);
        }
        char ri; cin >> ri;
        r[i] = ri;
    }
    
    int ans = 0;
    rep(s,n2){
        rep(j,m){
            int open = 0;
            rep(k,c[j]){
                if(s & (1<<a[j][k])) open++;
            }
            if(open >= k && r[j] == 'x') break;
            else if(open < k && r[j] == 'o') break;
            if(j == m-1){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}