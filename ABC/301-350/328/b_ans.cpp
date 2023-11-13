#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

bool check(int a,int b){
    string s = to_string(a) + to_string(b);
    sort(s.begin(),s.end());
    return s[0] == s.back();
}

int main(){
    int n;
    cin >> n;
    vector<int> d(n+1);
    for(int i=1;i<=n;i++) cin >> d[i];
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=d[i];j++){
            if(check(i,j)) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}