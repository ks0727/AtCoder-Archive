    #include <bits/stdc++.h>
    using namespace std;
    #define rep(i,n) for(int i=0;i<(n);i++)

    int main(){
        int n;
        cin >> n;
        vector<int> a(n*3);
        rep(i,3*n) cin >> a[i];
        vector<pair<int,int> > ans(n,pair<int,int>(-1,0));
        set<int> st;
        rep(i,3*n){
            a[i]--;
            if(!st.count(a[i])){
                st.insert(a[i]);
                continue;
            } 
            if(ans[a[i]].first == -1){
                ans[a[i]].first = i;
                ans[a[i]].second = a[i];
            }
        }
        sort(ans.begin(),ans.end());
        rep(i,n) cout << ans[i].second + 1 << ' ';
        return 0;
    }