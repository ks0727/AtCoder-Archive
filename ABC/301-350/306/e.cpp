#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> a(n);
    multiset<int> big,small;
    rep(i,k) big.insert(0);
    rep(i,n-k) small.insert(0);
    ll now = 0;
    rep(qi,q){
        int x,y;
        cin >> x >> y; x--;
        //cout << big.size() << ' ' << small.size() << endl;
        //for(int x : small) cout << x << ' '; cout << endl;
        if(big.find(a[x]) != big.end()){
            auto it = big.find(a[x]);
            big.erase(it);
            now -= a[x];
        }else{
            auto it = small.find(a[x]);
            assert(it != small.end());
            small.erase(it);
            small.insert(*big.begin());
            now -= *big.begin();
            big.erase(big.begin());
            
        }
        a[x] = y;
        small.insert(y);
        int mx_small = *small.rbegin();
        big.insert(mx_small);
        now += mx_small;
        //cout << mx_small << endl;
        small.erase(small.find(mx_small));
        //cout << *mn_big << endl;
        cout << now << endl;
    }
    return 0;
}