#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
bool ispa(string t){
    string nt = t;
    reverse(nt.begin(),nt.end());
    return nt == t;
}

int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    ll ans = 0;
    do{
        rep(i,n-k+1){
            string t = s.substr(i,k);
            if(ispa(t)) break;
            if(i == n-k) ans++;
        }
    }while(next_permutation(s.begin(),s.end()));
    cout << ans << endl;
    return 0;
}