#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<int,int>;
int main(){
    int n;
    cin >> n;
    stack<P> st;
    st.emplace(-1,0);
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        if(i%2 == 1){//奇数
            if(st.top().first == a){
                auto [c,num] = st.top(); st.pop();
                num++;
                st.emplace(c,num);
            }else{
                st.emplace(a,1);
            }
        }else{//偶数
            if(st.top().first == a){
                auto [c,num] = st.top(); st.pop();
                num++;
                st.emplace(c,num);
            }else{ //色が異なる
                auto [c,num] = st.top(); st.pop();
                num++;
                int nc = c^1;
                if(st.size() != 0 && st.top().first == nc){
                    auto [c2,num2] = st.top(); st.pop();
                    st.emplace(nc,num+num2);
                }else{
                    st.emplace(nc,num);
                }
            }
        }
    }
    int ans = 0;
    while(st.size()){
        auto [c,num] = st.top(); st.pop();
        //cout << c << ' ' << num << endl;
        if(c == 0) ans += num;
    }
    cout << ans << endl;
    return 0;
}