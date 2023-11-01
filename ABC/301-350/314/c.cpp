#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<char,int> > > x(3,vector<pair<char,int> >());
    vector<pair<char,int> > p; 
    rep(i,n){
        char s;
        cin >> s;
        p.push_back(make_pair(s,i));
    }
    rep(i,n){
        int color;
        cin >> color;
        x[color-1].push_back(p[i]);
    }
    rep(i,m){
        if(x[i].size() > 0){
            int prev = x[i][0].first;
            int last = x[i][x[i].size()-1].first;
            rep(j,x[i].size()){
                if(j == 0) continue;
                int temp = prev;
                prev = x[i][j].first;
                x[i][j].first = temp;
                if(j == x[i].size()-1) x[i][0].first = last;
            }
        }
    }
    vector<char> ans(n);
    rep(i,m){
        int index;
        char alpha;
        if(x[i].size() != 0){
            rep(j,x[i].size()){
                alpha = x[i][j].first;
                index = x[i][j].second;
                ans[index] = alpha;
            }
        }
        else{
            index = x[i][0].first;
            alpha = x[i][0].second;
            ans[index] = alpha;
        }
    }
    rep(i,n) cout << ans[i];
    cout << endl;
}