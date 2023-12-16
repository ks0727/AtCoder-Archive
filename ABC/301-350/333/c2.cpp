#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    int now = 1;
    int add = 1;
    vector<int> prevs;
    int prev = 0;
    while(now < n){
        add++;
        now += add;
        prevs.push_back(now+prev);
        prev = now;
    }
    prevs.pop_back();
    int cur = prevs.back()+1;
    string s = "";
    rep(i,add) s+='1';
    vector<int> enu;
    for(int i=1;i< add;i++){
        enu.push_back(i);
        enu.push_back(i);
    }
    ll ans = 0;
    cout << cur << endl;
    do{
        if(cur == n){
            string one = "";
            string two = "";
            rep(i,enu[0]){
                one += '1';
            }
            rep(i,enu[1]){
                two += '1';
            }
            cout << one << endl;
            ll none = stoll(one);
            ll ntwo = stoll(two);
            ll nthree = stoll(s);
            ans = none+ntwo+nthree;
        }
        cur++;
    }while(next_permutation(enu.begin(),enu.end()));
    cout << ans << endl;
    return 0;
}