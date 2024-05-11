#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int key = h[0];
    for(int i=1;i<(n);i++){
        if(h[i] > key){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}