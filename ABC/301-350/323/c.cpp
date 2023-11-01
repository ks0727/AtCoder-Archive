#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    vector<int> points(n);
    vector<vector<bool> > solved(n,vector<bool>(m));
    rep(i,n){
        rep(j,m){
            char pass;
            cin >> pass;
            if(pass == 'o'){
                points[i] += a[j];
                solved[i][j] = true;
            }
        }
        points[i] += i + 1;
    }
    int max_point = *max_element(points.begin(),points.end());
    vector<int> ans(n);
    vector<vector<int> > unsolved(n);
    rep(i,n){
        rep(j,m){
            if(!solved[i][j]) unsolved[i].push_back(a[j]);
        }
        sort(unsolved[i].rbegin(),unsolved[i].rend());
    }
    rep(i,n){
        if(max_point == points[i]) continue;
        int diff = max_point - points[i];
        rep(j,m){
            if(diff < 0){
                break;
            }
            ans[i]++;
            diff -= unsolved[i][j];
        }
    }
    rep(i,n) cout << ans[i] << endl;
    return 0;
}