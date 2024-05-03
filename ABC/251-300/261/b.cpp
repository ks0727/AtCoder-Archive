#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

string a[1000];

int main(){
    int n; cin >> n;
    rep(i,n) cin >> a[i];
    bool ans = true;
    rep(i,n)rep(j,n){
        if(a[i][j]=='W' && a[j][i] == 'W') ans = false;
        if(a[i][j] == 'L' && a[j][i] == 'L') ans = false;
        if(a[i][j] == 'D' && a[j][i] != 'D') ans = false;
    }
    cout << (ans?("correct"):("incorrect")) << endl;
    return 0;
}