#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin  >> a[i];
    int n;
    cin >> n;
    auto toid = [&](int i,int j){
        int id = i*h+j;
        return id;
    };
    auto tops = [&](int id){
        int i = id/h; int j = id%h;
        return P(i,j);
    };
    vector<int> energy(h*w,-1);
    rep(i,n){
        int r,c,e;
        cin >> r >> c >> e;
        r--; c--;
        int eid = toid(r,c);
        energy[eid] = e;
    }
    int si=-1,sj=-1,gi=-1,gj=-1;
    rep(i,h)rep(j,w){
        if(a[i][j] == 'S'){
            a[i][j] = '.';
            si = i; sj = j;
        }
        if(a[i][j] == 'T'){
            a[i][j] = '.';
            gi = i; gj = j;
        }
    }
    priority_queue<P,vector<P>,less<P> > q;
    int sid = toid(si,sj);
    int gid = toid(gi,gj);
    q.emplace(0,sid);
    vector<int> grid(h*w,-1);
    grid[sid] = 0;
    while(!q.empty()){
        auto [egy,id] = q.top(); q.pop();
        if(grid[id] != egy) continue;
        auto [i,j] = tops(id);
        if(egy == 0 && energy[id] == -1) continue; //エネルギー0かつpotionなしでおしまい
        if(energy[id] != 0){ //potionが存在するとき
            if(grid[id] < energy[id]){ //posionを使うとエネルギーが回復する場合potion使用
                grid[id] = energy[id];
                energy[id] = -1;
            }
        }
        rep(d,4){
            int ni = i+di[d]; int nj = j+dj[d];
            if(ni < 0 || nj < 0 || ni >= h || nj >=w) continue;
            if(a[ni][nj] == '#') continue;
            int nid = toid(ni,nj);
            if(grid[id] - 1 > grid[nid]){
                grid[nid] = grid[id]-1;
                q.emplace(grid[id]-1,nid);
            }
        }
    }
    if(grid[gid] == -1) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}