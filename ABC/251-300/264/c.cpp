#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int h1,w1;
    cin >> h1 >> w1;
    vector a(h1,vector<int>(w1));
    rep(i,h1)rep(j,w1) cin >> a[i][j];
    int h2,w2;
    cin >> h2 >> w2;
    vector b(h2,vector<int>(w2));
    rep(i,h2)rep(j,w2) cin >> b[i][j];
    int dh = h1 - h2; //削除する行数
    int dw = w1 - w2; //削除する列数
    auto combination = [&](vector<int> indexes, int r)->vector<vector<int> >{
        vector<vector<int> > res;
        int n = indexes.size();
        auto dfs = [&](auto dfs,int v, vector<int> cur)->void{
            if(cur.size() == r){
                res.push_back(cur);
                return;
            }
            //if(v == n) return;
            //選ばない
            dfs(dfs,v+1,cur);
            //選ぶ
            cur.push_back(v);
            dfs(dfs,v+1,cur);
            cur.pop_back();
            return;
        };
        dfs(dfs,indexes[0],vector<int>{});
        return res;
    };
    auto f = [&](auto f, int ch,int cw,unordered_set<int> delh,unordered_set<int> delw)->bool{
        if(delh.size() == dh && delw.size() == dw){
            vector<vector<int> > c;
            rep(i,h1){
                if(delh.count(i)) continue;
                c.push_back({});
                rep(j,w1){
                    if(delw.count(j)) continue;
                    c.back().push_back(a[i][j]);
                }
            }
            rep(i,h2){
                rep(j,w2){
                    if(c[i][j] != b[i][j]) return false;
                }
            }
            return true;
        }
        if(ch == h1) return false;
        if(cw == w1) return false;
        {//その列を選ばない場合
            if(f(f,ch+1,cw,delh,delw)) return true;
        }
        {//その列を選ぶ場合
            delh.insert(ch);
            if(f(f,ch+1,cw,delh,delw)) return true;
            delh.erase(ch);
        }
        {//その行を選ばない場合
            if(f(f,ch,cw+1,delh,delw)) return true;
        }
        {//その行を選ぶ場合
            delw.insert(cw);
            if(f(f,ch,cw+1,delh,delw)) return true;
            delw.erase(cw);
        }
        return false;
    };
    if(f(f,0,0,unordered_set<int>{},unordered_set<int>{})) cout << "Yes" << endl;
    else cout << "No" << endl;
    vector<int> test;
    rep(i,5) test.push_back(i);
    vector<vector<int> > comb = combination(test,3);
    for(auto arr : comb){
        for(int x : arr) cout << x << ' ';
        cout << endl;
    }
    return 0;
}