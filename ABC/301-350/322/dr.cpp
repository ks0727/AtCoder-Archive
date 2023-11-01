#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

struct Board{
    vector<string> p;
    void input(){
        rep(i,4){
            string s;
            cin >> s;
            p.push_back(s);
        }
    }
    void clear(){
        rep(i,4)rep(j,4) p[i][j] = '.';
    }
    void print(){
        rep(i,4) cout << p[i] << endl; 
    }
    void rotate(){
        vector<string> np = p;
        rep(i,4){
            rep(j,4){
                np[i][j] = p[3-j][i];
            }
        }
        p = np;
    }
    void shift(Board &x,int si,int sj, bool &flag){
        rep(i,4){
            rep(j,4){
                if(p[i][j] == '.') continue;
                int ni = i+si; int nj = j+sj;
                if(ni < 0 || nj < 0 || ni >= 4|| nj >= 4){
                    flag = false;
                    return;
                }
                if(x.p[ni][nj] == '#'){
                    flag = false;
                    return;
                }
                x.p[ni][nj] = '#';
            }
        }
    }
};

int main(){
    Board b0,b1,b2;
    b0.input();
    b1.input();
    b2.input();
    Board attempt;
    attempt = b0;
    attempt.clear();
    vector<string> ans;
    rep(i,4){
        ans.push_back("####");
    }
    bool flag = true;
    for(int b0si = -4;b0si < 4;b0si++){
        for(int b0sj = -4;b0sj < 4;b0sj++){
            rep(r1,4){
                rep(r2,4){
                    for(int b1si = -4;b1si < 4;b1si++){
                        for(int b1sj = -4;b1sj<4;b1sj++){
                            for(int b2si=-4;b2si<4;b2si++){
                                for(int b2sj = -4;b2sj<4;b2sj++){
                                    b0.shift(attempt,b0si,b0sj,flag);
                                    b1.shift(attempt,b1si,b1sj,flag);
                                    b2.shift(attempt,b2si,b2sj,flag);
                                    if(!flag){
                                        attempt.clear();
                                        flag = true;
                                        continue;
                                    }
                                    if(attempt.p == ans){
                                        cout << "Yes" << endl;
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                    b2.rotate();
                }
                b1.rotate();
            }
        }
    }
    cout << "No" << endl;
    return 0;
}