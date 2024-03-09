#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    vector<int> a;
    while(1){
        int x;
        cin >> x;
        a.push_back(x);
        if(x == 0) break;
    }
    reverse(a.begin(),a.end());
    for(int x : a) cout << x << endl;
    return 0;
}