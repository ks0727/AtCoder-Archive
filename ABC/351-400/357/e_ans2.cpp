#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> deg(n);
    rep(i,n){
        cin >> a[i];
        a[i]--;
        deg[a[i]]++;
    } 
    vector<int> q; 
    rep(i,n)if(deg[i] == 0) q.push_back(i); //まずは入次数0の頂点をプッシュ(木の端)
    rep(i,q.size()){
        int u = q[i]; //その頂点の次の頂点
        deg[a[u]]--;//頂点の入次数を1減らす
        if(deg[a[u]] == 0) q.push_back(a[u]); //もし入次数が0になったらプッシュ
    }
    //ループを抜けた時点で, qに入っているのは, サイクルの外の頂点
    vector<int> ans(n);
    rep(i,n){
        if(ans[i]==0&&deg[i]==1){ //この時点で入次数1なのはサイクル上の頂点
            int u = i;
            int c = 0;
            do{
                c++;
                u = a[u];
            }while(u != i);
            do{
                ans[u] = c;
                u = a[u];
            }while(u != i);
        }
    }
    //ループを抜けた時点でサイクル内の頂点は終わり
    for(int i=q.size()-1;i>=0;i--){
        assert(ans[q[i]] == 0);
        assert(ans[a[q[i]]] != 0);
        ans[q[i]] = ans[a[q[i]]]+1;
    }
    long sum = 0;
    rep(i,n) sum += ans[i];
    cout << sum << endl;
    return 0;
}