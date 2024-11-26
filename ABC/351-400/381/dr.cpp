#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i],a[i]--;
    int ans = 0;
    {
        queue<int> q;
        vector<int> seen(n);
        rep(i,n/2){
            if(a[2*i] != a[2*i+1]){
                ans = max(ans,(int)q.size()*2);
                while(!q.empty()) q.pop();
            }else{
                if(q.empty()){
                    q.push(a[2*i]);
                    seen[a[2*i]] = i;
                }
                else{
                    if(seen[a[2*i]] >= seen[q.front()]){
                        ans = max(ans,(int)q.size()*2);
                        while(q.front() != a[2*i]){
                            q.pop();
                        }
                        q.pop();
                        seen[a[2*i]] = i;
                        q.push(a[2*i]);
                    }else{
                        seen[a[2*i]] = i;
                        q.push(a[2*i]);
                    }
                }
            }
        }
        ans = max(ans,(int)q.size()*2);
    }
    {
        queue<int> q;
        vector<int> seen(n);
        for(int i=1;i<n/2-1;i++){
            if(a[2*i] != a[2*i+1]){
                ans = max(ans,(int)q.size())*2;
                while(!q.empty()) q.pop();
            }else{
                if(q.empty()){
                    q.push(a[2*i]);
                    seen[a[2*i]] = i;
                }
                else{
                    if(seen[a[2*i]] >= seen[q.front()]){
                        ans = max(ans,(int)q.size()*2);
                        while(q.front() != a[2*i]){
                            q.pop();
                        }
                        q.pop();
                        q.push(a[2*i]);
                        seen[a[2*i]] = i;
                    }else{
                        q.push(a[2*i]);
                        seen[a[2*i]] = i;
                    }
                }
            }
        }
        ans = max(ans,(int)q.size()*2);
    }
    cout << ans << endl;
    return 0;
}