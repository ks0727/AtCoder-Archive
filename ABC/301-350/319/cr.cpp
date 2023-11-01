#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

bool disappointed(vector<int> c){
        rep(i,3){
            if(c[i] == c[i+1] || c[i+1] == c[i+2] || c[i] == c[i+2]){
                if(c[i] == i+10 || c[i+1] == i+1+10 || c[i+2] == i+2+10) return true;
            }
        }
        rep(i,3){
            if(c[i] == c[i+3] || c[i+3] == c[i+6] || c[i] == c[i+6]){
                if(c[i] == i+10 || c[i+3] == i+3+10 || c[i+6] == i+6+10) return true;
            }
        }
        if(c[0] == c[4] || c[4] == c[8] || c[0] == c[8]){
            if(c[0] == 10 || c[4] == 14 || c[8] == 18) return true;
        }
        if(c[2] == c[4] || c[4] == c[6] || c[2] == c[6]){
            if(c[2] == 12 || c[4] == 14 || c[6] == 16) return true;
        }
        return false;
};

int main(){
    vector<int> c(9);
    rep(i,9) cin >> c[i];
    vector<int> order(9);
    rep(i,9) order[i] = i;
    double all = 0;
    double event = 0;
    do{
        vector<int> open(9);
        rep(i,9) open[i] = i+10;
        all++;
        rep(i,9){
            open[order[i]] = c[order[i]];
            if(disappointed(open)){
                event++;
                break;
            } 
        }
    }while(next_permutation(order.begin(),order.end()));
    double disappoint = 362880 - event;
    double ans = disappoint / all;
    printf("%.9f\n",ans);
}