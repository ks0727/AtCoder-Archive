#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    set<int> winners;
    vector<int> losers;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        winners.insert(a);
        losers.push_back(b);
    }
    int size = losers.size();
    rep(i,size){
        if(winners.count(losers[i])) winners.erase(losers[i]);
    }
    if(winners.size() == 1){
        cout << *winners.begin() << endl;
        return 0;
    }
    
    else{
        cout << -1 << endl;
        return 0;
    }
    return 0;
}