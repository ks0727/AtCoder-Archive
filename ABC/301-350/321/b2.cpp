#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n-1);
    rep(i,n-1)  cin >> a[i];
    int key = 0;
    while(key < 101){
        vector<int> s;
        rep(i,n-1) s.push_back(a[i]);
        s.push_back(key);
        sort(s.begin(),s.end());
        int sum = 0;
        if(n == 3) sum = s[2];
        else for(int i=1;i<n-1;i++) sum += s[i];
        if(sum < x){
            key += 1;
        }
        else break;
    }
    if(key == 101){
        cout << -1 << endl;
        return 0;
    }
    else cout << key << endl;
    return 0;
}

