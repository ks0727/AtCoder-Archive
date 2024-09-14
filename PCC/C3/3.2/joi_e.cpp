#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<int,int>;

const int di[] = {1,0,-1,0};
const int dj[] = {0,-1,0,1};

struct UnionFind{
    int n,size;
    vector<int> par,rank;
    UnionFind(int n):n(n),par(n),rank(n){
        size = n;
        rep(i,n) par[i] = i;
    }
    int root(int x){
        if(x == par[x]) return x;
        return par[x] = root(x);
    }
    void merge(int a,int b){
        a = root(a);  b = root(b);
        if(a == b) return;
        if(rank[a] > rank[b]) swap(a,b);
        par[a] = par[b];
        rank[b] += rank[a];
        size--;
    }
    bool same(int a,int b){
        return root(a) == root(b);
    }
};

vector<int> compress(vector<int> &arr1, vector<int> &arr2,int left,int right){
    vector<int> res;
    rep(i,arr1.size()){
        res.push_back(arr1[i]);
        res.push_back(arr2[i]);
        //if(arr1[i]+1 <= right)res.push_back(arr1[i]+1);
        if(arr2[i]+1 <= right) res.push_back(arr2[i]+1);
    }
    res.push_back(left);
    res.push_back(right);
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    rep(i,arr1.size()){
        arr1[i] = lower_bound(res.begin(),res.end(),arr1[i]) - res.begin();
        arr2[i] = lower_bound(res.begin(),res.end(),arr2[i]) - res.begin();
    }
    return res;
}

int main(){
    int H,W;
    cin >> H >> W;
    int n;
    cin >> n;
    vector<int> x1(n),y1(n),x2(n),y2(n);
    rep(i,n) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    vector<int> x = compress(x1,x2,0,H);
    vector<int> y = compress(y1,y2,0,W);

    int h = x.size(), w = y.size();
    vector g(h,vector<int>(w));
    
    rep(i,n){
        g[x1[i]][y1[i]]++;
        g[x1[i]][y2[i]]--;
        g[x2[i]][y1[i]]--;
        g[x2[i]][y2[i]]++;
    }
    rep(i,h-1)rep(j,w) g[i+1][j] += g[i][j];
    rep(i,h)rep(j,w-1) g[i][j+1] += g[i][j];

    h--; w--;
    // rep(i,h){
    //     rep(j,w) cout << g[i][j] << ' ';
    //     cout << endl;
    // }
    int ans = 0;
    vector seen(h,vector<bool>(w));
    rep(i,h){
        rep(j,w){
            if(g[i][j] != 0) continue;
            if(seen[i][j]) continue;
            ans++;
            queue<P> q;
            q.emplace(i,j);
            seen[i][j] = true;
            while(!q.empty()){
                auto [ii,jj] = q.front(); q.pop();
                rep(d,4){
                    int ni = ii+di[d]; int nj = jj+dj[d];
                    if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                    if(g[ni][nj] != 0) continue;
                    if(seen[ni][nj]) continue;
                    seen[ni][nj] = true;
                    q.emplace(ni,nj);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}