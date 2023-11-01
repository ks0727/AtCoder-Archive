#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,q;
    cin >> n >> q;
    vector<map<int,int> > data(n);
    rep(qi,q){
        int num;
        cin >> num;
        if(num == 1){
            int i,j;
            cin >> i >> j;
            data[j][i]++;
        }
        if(num == 2){
            int i;
            cin >> i;
            sort(data[i].begin(),data[i].end());
            for(auto [key,value] : data[i]){
                while(value > 0){
                    cout << key << ' ';
                    value--;
                }
            }
            cout << endl;
        }
        if(num == 3){
            int i;
            cin >> i;
            rep(ii,n){
                if(data[ii].count(i)) cout << ii + 1;
            }
            cout << endl;
        }
    }
    return 0;
}