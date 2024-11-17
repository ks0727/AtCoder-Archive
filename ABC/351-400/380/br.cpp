#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    string s;
    cin >> s;
    vector<pair<char,int> > ps;
    for(char c : s){
        if(ps.size() > 0 && ps.back().first == c){
            ps.back().second++;
        }else{
            ps.emplace_back(c,1);
        }
    }
    for(auto [c,cnt] : ps){
        if(c == '-') cout << cnt << ' ';
    }
    cout << endl;
    return 0;
}