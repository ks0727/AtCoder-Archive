#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,x,y,z;
    cin >> n >> x >> y >> z;
    if(x > y) swap(x,y);
    if(x < z && z < y) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}