#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,t;
    cin >> n >> t;
    vector<pair<int,int> > players(n);
    rep(i,n) cin >> players[i].first;
    rep(i,n) cin >> players[i].second;
    int max = -1;
    int strongest = -1;
    rep(i,n){
        if(players[i].first == t){
            if(players[i].second > max){
                max = players[i].second;
                strongest = i;
            }
        }
    }
    if(strongest == -1){
        max = players[0].second;
        strongest = 0;
        for(int i=1;i<n;i++){
            if(players[i].first == players[0].first){
                if(max < players[i].second){
                    max = players[i].second;
                    strongest = i;
                }
            }
        }
    }
    cout << strongest + 1 << endl;
    return 0;
}