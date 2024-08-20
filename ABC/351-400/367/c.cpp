#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> r(n);
    rep(i,n) cin >> r[i];
    auto f = [&](auto f, int d, vector<int> now)->void{
        if(now.size() == n){
            int sum = 0;
            rep(i,n) sum += now[i];
            if(sum % k != 0) return;
            rep(i,n) cout << now[i] << ' '; cout << endl;
            return;
        }
        for(int i=1; i<=r[d];i++){
            now.push_back(i);
            f(f,d+1,now);
            now.pop_back();
        }
    };
    f(f,0,vector<int>{});
    return 0;
}