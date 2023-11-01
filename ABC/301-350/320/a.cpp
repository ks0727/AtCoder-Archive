#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)


int main(){
    int a,b;
    cin >> a >> b;
    int a_ans =1,b_ans =1;
    rep(i,b) a_ans *= a;
    rep(i,a) b_ans *= b;
    cout << a_ans + b_ans << endl;
    return 0;
}