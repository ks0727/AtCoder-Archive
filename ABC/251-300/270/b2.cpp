#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int x,y,z;
    cin >> x >> y >> z;
    auto f = [](int x, int y ,int z){
        if(y < 0 || y > x) return x;
        else{
            if(z > 0 && z > y) return -1;
            else return abs(z)+abs(z-x);
        }
    };
    int ans = (x > 0)? f(x,y,z):f(-x,-y,-z);
    cout << ans << endl;
    return 0;
}