#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int> > dp(s.size(),vector<int>(2,1));
    rep(i,s.size()) dp[i][s[i]-'0'] = 0;
    while(dp.size() > 1){
        vector<vector<int> > 
    }
}