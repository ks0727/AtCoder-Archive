#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

//文字列を出力してプログラム終了
void print(const string &s){
    cout << s << '\n';
    exit(0);
}
//右に90度回転
void rotate(vector<string> &v){
    vector<string> w = v;
    rep(i,4){
        rep(j,4){
            w[3-j][i] = v[i][j];
        }
    }
    v = w;
}
//(i,j)がグリッド内かどうか判定
bool in(int i, int j){
    return 0 <= i && i < 4 &&  0 <= j && j < 4;
}
// p を(di,dj)を左の上の位置としたときに、それはグリッド内に収まり、おくことができるか？
bool can_put(vector<vector<int> > &exist, const vector<string> &p, int di,int dj){
    rep(i,4){
        rep(j,4){
            if(p[i][j] == '#'){
                int ni = i + di;
                int nj = j + dj;
                if(!in(ni,nj)) return false;
                if(exist[ni][nj] == 1) return false;
                exist[ni][nj] = 1;
            }
        }
    }
    return true;
}
//ポリオミノを再帰で置いていく
void dfs(int i,const vector<vector<int> > &exist,const vector<vector<string> > &ps){
    if(i == 3){
        int ok = 1;
        rep(u,4){
            rep(v,4){
                ok &= exist[u][v];
            }
        }
        if(ok) print("Yes");
        return;
    }
    for(int di = -3;di<= 3;di++){
        for(int dj = -3;dj<=3;dj++){
            auto ex2 = exist;
            bool flag = can_put(ex2,ps[i],di,dj);
            if(flag) dfs(i+1,ex2,ps);
        }
    }
}

int main(){
    vector<vector<string> > ps(3);
    rep(i,3){
        ps[i].resize(4);
        for(auto &s : ps[i]) cin >> s;
    }
    rep(t,4){
        rep(u,4){
            dfs(0,vector(4,vector(4,0)),ps);
            rotate(ps[2]);       
        }
        rotate(ps[1]);
    }
    print("No");
}