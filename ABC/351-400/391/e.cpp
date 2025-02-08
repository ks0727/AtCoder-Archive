#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P= pair<int,int>;

int pow3(int a){
    int res = 1;
    rep(i,a) res *= 3;
    return res;
}

int main(){
    int n;
    cin >> n;
    string a;
    cin >> a;
    vector<string> original(n+1);
    original[0] = a;
    rep(i,n){
        string now = "";
        for(int j=0;j<pow3(n-i);j+=3){
            int cnt = 0;
            rep(k,3) if(original[i][j+k] == '1') cnt++;
            if(cnt >= 2) now += "1";
            else now += "0";
        }
        original[i+1] = now;
    }

    map<P,int> mp;
    auto f = [&](auto f, int d, int k)->int{
        if(d == 0) return 1;
        if(mp.count(P(d,k))) return mp[P(d,k)]; 
        char now = original[d][k];
        int cnt = 0;
        rep(i,3){
            if(original[d-1][k*3+i] == now) cnt++;
        }
        // if(cnt != 3 && cnt != 2){
        //     cout << original[d-1] << endl;
        //     rep(i,3) cout << original[d-1][k*3+i]; cout << endl;
        //     cout << d << ' ' << k << endl;
        // }
        assert(cnt == 3 || cnt == 2);
        if(cnt == 3){
            vector<int> cost;
            rep(i,3) cost.push_back(f(f,d-1,k*3+i));
            sort(cost.begin(),cost.end());
            return mp[P(d,k)] = cost[0]+cost[1];
        }else{
            int mn = 1001001001;
            rep(i,3){
                if(original[d-1][k*3+i] == now) mn = min(mn,f(f,d-1,k*3+i));
            }
            return mp[P(d,k)] = mn;
        }
    };
    int ans = f(f,n,0);
    cout << ans << endl;
    return 0;
}