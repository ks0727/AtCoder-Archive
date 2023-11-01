#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> x(5*n);
    rep(i,5*n) cin >> x[i];
    sort(x.begin(),x.end());
    x.erase(x.begin(),x.begin()+n);
    x.erase(x.begin()+4*n,x.end());
    int all = 0;
    rep(i,3*n){
        all += x[i];
    }
    double point = 1.*all/(3*n);
    printf("%.10lf\n",point);
    return 0;
}