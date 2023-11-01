#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i =0;i<(n);i++)
using P = pair<int,int>;

int main(){
    vector<int> c(9);
    rep(i,9) cin >> c[i];
    vector<int> order(9);
    rep(i,9) order[i] = i;
    int tot = 0;
    int event = 0;
    do{
        tot++;
        bool disappointed = false;
        auto open = [&](int i,int j,int k){
            vector<P> opened;
            opened.push_back({order[i],c[i]});
            opened.push_back({order[j],c[j]});
            opened.push_back({order[k],c[k]});
            sort(opened.begin(),opened.end());
            if(opened[0].second == opened[1].second){
                disappointed = true;
            }
        };
        open(0,1,2);
        open(3,4,5);
        open(6,7,8);
        open(0,3,6);
        open(1,4,7);
        open(2,5,8);
        open(0,4,8);
        open(2,4,6);
        if(!disappointed) event++;
    }while(next_permutation(order.begin(),order.end()));
    double ans = 1.*event/tot;
    printf("%.10f",ans);
    return 0;
}