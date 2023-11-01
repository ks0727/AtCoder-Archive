#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,q;
    cin >> n >> q;
    vector<vector<int> > cards(n+1);
    vector<set<int> > boxes(200001);
    rep(qi,q){
        int type;
        cin >> type;
        if(type == 1){
            int i,j;
            cards[j].push_back(i);
            boxes[i].insert(j);
        }
        if(type == 2){
            int i;
            cin >> i;
            sort(cards[i].begin(),cards[i].end());
            for(int x : cards[i]) cout << x << ' ';
            cout << endl;
        }
        if(type == 3){
            int i;
            cin >> i;
            for(int x: boxes[i]) cout << x << ' ';
            cout << endl;
        }
    }
    return 0;
}