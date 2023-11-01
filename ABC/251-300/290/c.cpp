#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,k;
    cin >> n >> k;
    set<int> a;
    rep(i,n){
        int value;
        cin >> value;
        a.insert(value);
    }
    int prev = -1;
    int m = 0;
    for(auto value : a){
        if(value == prev + 1){
            m++;
            prev = value;
            if(m >= k){
                cout << k << endl;
                return 0;
            }
        }else{
            break;
        }
    }
    cout << m << endl;
}