#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,h,w;
    cin >> n >> h >> w;
    vector<P> vs;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        vs.emplace_back(a,b);
    }
    for(int bit = 0;bit<(1<<n);bit++){
        vector<int> use;
        for(int i=0;i<n;i++){
            if(bit & (1<<i)){
                use.push_back(i); //使うタイルのidxを入れておく
            }
        }
        auto f = [&](auto f,vector<int> use,int now,vector<vector<bool> >& exist)->bool{
            if(now == use.size()){
                rep(i,h)rep(j,w){
                    if(!exist[i][j]) return false;
                }
                return true;
            }
            if(now > use.size()) return false;
            auto [hk,wk] = vs[now];
            rep(i,h-hk+1){
                rep(j,w-wk+1){
                    bool putable = true; //すでに置かれているかを判定
                    rep(ii,hk){
                        if(!putable) break;
                        rep(jj,wk){
                            if(exist[i+ii][j+jj]){
                                putable = false;
                                break;
                            }
                        }
                    }
                    if(!putable) continue;
                    rep(ii,hk)rep(jj,wk) exist[i+ii][j+jj] = true;
                    if(f(f,use,now+1,exist)) return true;
                }
            }
            swap(hk,wk); //回転させてもう一回トライ
            rep(i,h-hk+1){
                rep(j,w-wk+1){
                    bool putable = true;
                    rep(ii,hk){
                        if(!putable) break;
                        rep(jj,wk){
                            if(exist[i+ii][j+jj]){
                                putable = false;
                                break;
                            } 
                        }
                    }
                    if(!putable) continue;
                    rep(ii,hk)rep(jj,wk) exist[i+ii][j+jj] = true;
                    if(f(f,use,now+1,exist)) return true;
                }
            }
            return false;
        };
        vector<vector<bool> > exist(h,vector<bool>(w));
        if(f(f,use,0,exist)){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}