#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<bool> > with(n,vector<bool>(n)); 
    rep(i,m){
        int k;
        cin >> k;
        vector<int> p;
        rep(i,k){
            int x;
            cin >> x;
            x--;
            p.push_back(x);
        }
        for(int x : p){
            for(int y : p){
                with[x][y] = true;
                with[y][x] = true;
            }
        }
    }
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            if(!with[i][j]){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}