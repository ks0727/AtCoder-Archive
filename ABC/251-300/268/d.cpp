#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<string,bool>;

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    unordered_set<string> st;
    rep(i,m){
        string t;
        cin >> t;
        st.insert(t);
    }
    int sum = 0; //sの長さの合計
    rep(i,n) sum += s[i].size();
    int extra = 16-sum-n+1; //余計に追加できるハイフンの数
    vector<int> is; //permutation用
    rep(i,n) is.push_back(i);
    string ans = "???";
    auto f = [&](auto f,vector<int> indexes, string now, int cur, int ex)->bool{
        if(cur == n-1){ // 
            if(!st.count(now) && now.size() >= 3 && now.size() <=16){
                ans = now;
                return true;
            }
            return false;
        }
        string next = now;
        next += "_";
        if(f(f,indexes,next+s[indexes[cur+1]],cur+1,ex)) return true;
        while(ex > 0){
            ex--;
            next+= "_";
            if(f(f,indexes,next+s[indexes[cur+1]],cur+1,ex)) return true;
        }
        return false;
    };
    do{
        if(f(f,is,s[is[0]],0,extra)) break;
    }while(next_permutation(is.begin(),is.end()));
    if(ans != "???") cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}