#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> nums;
    for(int i = 1;i <= 1e7;i++){
        nums.push_back(i*i);
    }
    sort(s.begin(),s.end());
    int ans = 0;
    do{
        ll value = 0;
        rep(i,n){
            int si = s[i] - '0';
            value = value * 10 + ll(si);
        }
        auto result =  find(nums.begin(),nums.end(),value);
        if(result != nums.end()) ans++;
    }while(next_permutation(s.begin(),s.end()));
    cout << ans << endl;
    return 0;
}