#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> d;
    while(n >= 16){
        d.push_back(n%16);
        n /= 16;
    }
    d.push_back(n);
    reverse(d.begin(),d.end());
    cout << endl;
    string ans = "";
    for(int x : d){
        if(x < 10){
            char c = x + '0';
            ans += c;
        }else{
            x -= 10;
            char c = 'A' + x;
            ans += c;
        }
    }
    while(ans.size() < 2){
        ans.insert(ans.begin(),'0');
    }
    cout << ans << endl;
    return 0;
}