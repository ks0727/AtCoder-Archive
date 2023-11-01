#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<pair<int,int> > vec(n);
    rep(i,n){
        vec[i].first = 0;
        vec[i].second = i;
        rep(j,n){
            if(s[i][j] == 'o'){
                vec[i].first++;
            }
        }
    }
    sort(vec.rbegin(),vec.rend());
    rep(i,vec.size()) cout << vec[i].second + 1<< ' ';
    cout << endl;
    return 0;
}