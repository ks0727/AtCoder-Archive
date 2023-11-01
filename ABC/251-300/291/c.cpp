#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n;
    string s;
    set<P> visited;
    cin >> n >> s;
    visited.insert(make_pair(0,0));
    int x = 0,y = 0;
    rep(i,n){
        if(s[i] == 'R') x+=1;
        if(s[i] == 'L') x-=1;
        if(s[i] == 'U') y+=1;
        if(s[i] == 'D') y-=1;
        P npos = make_pair(x,y);
        if(visited.count(npos)){
            cout << "Yes" << endl;
            return 0;
        }else{
            visited.insert(npos);
        }
    }
    cout << "No" << endl;
    return 0;
}