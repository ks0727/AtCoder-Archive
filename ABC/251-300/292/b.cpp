#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> players(n);
    rep(i,q){
        int event;
        cin >> event;
        if(event == 1){
            int x;
            cin >> x;
            x--;
            players[x]++;
        }
        if(event == 2){
            int x;
            cin >> x;
            x--;
            players[x]+=2;
        }
        if(event == 3){
            int x;
            cin >> x;
            x--;
            if(players[x] >= 2){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}