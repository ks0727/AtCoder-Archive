#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    
    vector<int> ps;
    int M = 1e6;
    vector<bool> prime(M+1,true);
    for(int i=2;i<=M;i++){
        if(prime[i]) ps.push_back(i);
        for(int j=i*2;j<=M;j+=i) prime[j] = false;
    }
    int a;
    while(cin >> a){
        int x = upper_bound(ps.begin(),ps.end(),a) - ps.begin();
        cout << x << endl;
    }
}  