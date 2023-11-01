#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,q;
    cin >> n >> q;
    vector<vector<int> > boxes(n);
    map<int,set<int>> mp;
    rep(cnt,q){
        int type;
        cin >> type;
        if(type == 1){
            int i,j;
            cin >> i >> j;
            j--;
            boxes[j].push_back(i);
            mp[i].insert(j);
        }
        if(type == 2){
            int i;
            cin >> i;
            i--;
            sort(boxes[i].begin(),boxes[i].end());
            rep(j,boxes[i].size()) cout << boxes[i][j] << ' ';
            cout << endl;
        }
        if(type == 3){
            int i;
            cin >> i;
            for(auto box : mp[i]){
                cout << box + 1 << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}