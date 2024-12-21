#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    vector<int> p(5);
    rep(i,5) cin >> p[i];
    vector<pair<int,string> > a;
    rep(i,5){
        auto f = [&](auto f, vector<int> b)->void{
            if(b.size() == i+1){
                int point = 0;
                rep(j,i+1){
                    point += p[b[j]];
                }
                string now = "";
                rep(j,i+1){
                    now += char(b[j]+'A');
                }
                a.emplace_back(-point,now);
            }
            int last = b.size()>0?b.back():-1;
            for(int j=last+1;j<5;j++){
                b.push_back(j);
                f(f,b);
                b.pop_back();
            }
        };
        f(f,vector<int>{});
    }
    sort(a.begin(),a.end());
    rep(i,a.size()){
        cout << a[i].second << endl;
    }
    return 0;
}