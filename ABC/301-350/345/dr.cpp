#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,h,w;
    cin >> n >> h >> w;
    vector<P> tiles;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        tiles.emplace_back(a,b);
    }
    vector<int> idx;
    rep(i,n) idx.push_back(i);
    do{
        for(int bit=0;bit<(1<<n);bit++){
            queue<int> use;
            vector<vector<bool> > exist(h,vector<bool>(w));
            rep(i,n) if(bit & (1<<i)) use.push(idx[i]); //使うタイルをuseにしまっておく
            while(!use.empty()){
                int si = -1, sj = -1;
                bool found = false;
                rep(i,h){
                    if(found) break;
                    rep(j,w){
                        if(!exist[i][j]){
                            si = i; sj = j;
                            found = true;
                            break;
                        }
                    }
                }
                auto [ch,cw] = tiles[use.front()]; use.pop();
                rep(k,2){
                    swap(ch,cw);
                    if(si+ch > h || sj+cw > w) continue;
                    bool ok = true;
                    rep(i,ch){
                        if(!ok) continue;
                        rep(j,cw){
                            if(exist[si+i][sj+j]){
                                ok = false;
                                break;
                            }
                        }
                    }
                    if(!ok) continue;;
                    rep(i,ch)rep(j,cw) exist[si+i][sj+j] = true;
                    bool isdone = false;
                    rep(i,h){
                        if(isdone) break;
                        rep(j,w){
                            if(!exist[i][j]){
                                isdone = true;
                                break;
                            }
                            if(i == h-1 && j == w-1){
                                cout << "Yes" << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }while(next_permutation(idx.begin(),idx.end()));
    cout << "No" << endl;
    return 0;
}