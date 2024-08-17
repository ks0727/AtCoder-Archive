#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    string ans = to_string(n%100);
    if(ans.size() == 1) ans.insert(ans.begin(),'0');
    cout << ans << endl;
    return 0;
}