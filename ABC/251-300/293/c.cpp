#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

vector<int> dx = {1,0};
vector<int> dy = {0,1};

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<int> > a(h,vector<int>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    stack<P> q;
    
    vector<vector<bool> > seen(h,vector<bool>(w));
    vector<int> values;
    q.push(make_pair(0,0));
    int ans = 0;
    while(!q.empty()){
        auto [x,y] = q.top();
        bool isappend = true;
        if(x == w-1 && y == h-1) isappend = false;
        if(isappend) values.push_back(a[x][y]);
        int size = values.size();
        rep(i,size) cout << values[i] << ' ';
        cout << endl;
        q.pop();
        rep(v,2){
            int nx = x+dx[v]; int ny = y+dy[v];
            if(nx >= w || ny >= h) continue;
            int ok = true;
            rep(i,size){
                rep(j,size){
                    if(i == j) continue;
                    if(values[i] == values[j]){
                        ok = false;
                        break;
                    }
                }
                if(!ok) break;
            }
            if(!ok){
                values.erase(values.end()-1);
                continue;
            }
            q.push(make_pair(nx,ny));
            if(nx == w-1 && ny == h-1){
                ans++;
                auto [temp_x,temp_y] = q.top();
                values.erase(values.begin()+temp_x+temp_y+1,values.end());
            }
        }
    }
    cout << ans << endl;
}