#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    const int INF = 1001001001;
    int left=INF,right=-1,top=INF,down=-1;
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#'){
                left = min(left,j);
                right = max(right,j);
                top = min(top,i);
                down = max(down,i);
            }
        }
    }
    for(int i=top;i<=down;i++){
        for(int j=left;j<=right;j++){
            if(s[i][j] == '.'){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}