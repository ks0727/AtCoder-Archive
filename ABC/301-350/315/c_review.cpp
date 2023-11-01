#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<vector<int> > x(n);
    rep(i,n){
        int index;
        int flavor;
        cin >> index;
        cin >> flavor;
        x[index-1].push_back(flavor);
    }
    
    rep(i,x.size()){
        sort(x[i].rbegin(),x[i].rend());
    }
    
    int ans,current;
    //味が異なるとき
    vector<int> values;
    int maximum=-1,maxIndex=-1;
    rep(i,x.size()){
        if(x[i].size() == 0) continue;
        else{
            if(maximum < x[i][0]){
            maximum = x[i][0];
            maxIndex = i;
            }
        }
        values.push_back(x[i][0]);
    }
    sort(values.rbegin(),values.rend());
    current = values[0] + values[1];
    //味が同じとき
    ans = x[maxIndex][0] + x[maxIndex][1] / 2;
    ans = max(ans,current);
    cout << ans << endl;
    return 0;
}