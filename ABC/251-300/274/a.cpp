#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    double a,b;
    cin >> a >> b;
    double ans = b / a;
    ans *= pow(10,3);
    ans = round(ans);
    ans /= pow(10,3);
    printf("%.3lf\n",ans);
    return 0;
}