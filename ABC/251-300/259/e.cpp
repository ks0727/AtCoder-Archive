#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    map<int,int> mp;
    map<int,vector<int> > mp2;
    rep(ni,n){
        int m;
        cin >>m;
        rep(mi,m){
            int p,e;
            cin >> p >> e;
            if(mp[p] < e){ //eが今の最大値よりも大きかったら
                mp[p] = e;
                mp2[p].clear();
                mp2[p].push_back(ni); //最大値の配列をからにして, その値を入れる
            }else if(mp[p] == e){
                mp2[p].push_back(ni); //最大値とその値が等しかったら, その値を入れる
            }
        }
    }
    set<int> st;
    for(auto [val,arr] : mp2){
        if(arr.size() == 1) st.insert(arr[0]); //今単独maxならそのidxをsetに入れる
    }
    int ans = st.size();
    if(ans < n) ans++;
    cout << ans << endl;
    return 0;
}