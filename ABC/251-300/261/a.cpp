#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int l = max(l1,l2);
    int r = min(r1,r2);
    int ans = max(0,r-l);
    cout << ans << endl;
    return 0;
}