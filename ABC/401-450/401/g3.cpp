#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// Union-Find (Disjoint Set Union) の実装
struct DSU {
    vector<int> parent, size;
    
    DSU(int n) : parent(n+1), size(n+1, 1) {
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int a) {
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return;
        // 小さいサイズのものを大きいサイズに併合
        if(size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N+1);
    
    // グラフの入力（無向グラフ）
    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        // u < v との制約あり
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // min_adj[j] : 頂点 j (j>=2) において，jより小さい隣接頂点のうち最小の番号
    // 存在しなければ N+1 とする
    const int INF = N + 1;
    vector<int> min_adj(N+1, INF);
    for (int j = 2; j <= N; j++){
        for (int u : adj[j]){
            if(u < j){
                min_adj[j] = min(min_adj[j], u);
            }
        }
    }
    
    // 頻度配列 freq[x] = 頂点 j (j>=2) で min_adj[j] == x の個数
    vector<int> freq(N+2, 0);
    for (int j = 2; j <= N; j++){
        if(min_adj[j] <= N) {
            freq[min_adj[j]]++;
        }
    }
    
    // 累積和 P[k] = sum_{x=1}^{k} freq[x]
    vector<int> P(N+1, 0);
    for (int k = 1; k <= N; k++){
        P[k] = P[k-1] + freq[k];
    }
 
    // DSU を用いて S = {1,..., k} の連結性を逐次的に判断する
    DSU dsu(N);
    // 答えを格納する配列（1-indexed）
    vector<int> ans(N+1, 0);
    
    // k = 1 の場合は S = {1} は自明に連結
    // このとき，条件を満たすためには 1 と隣接している (1以外の)頂点を削除する必要があるので，
    // ans[1] = [min_adj[j] <= 1] for j>=2 （j<=1はSに含まれるので除く）
    // ただし，累積和 P[1] は j (>=2) の中で min_adj[j]==1 の個数．
    ans[1] = P[1];  // k-1 = 0 のため
    
    // DSU のコンポーネントサイズ（頂点1を含む成分のサイズ）
    int compSize = 1; // 初めは頂点1のみ．
    
    // k = 2 以降について，頂点 k を追加し，連結性を union-find で更新
    for (int k = 2; k <= N; k++){
        // 頂点 k を追加したとみなし，その k と既に存在する頂点の間の辺 (u,k) (u < k) を処理
        for (int u : adj[k]){
            if(u < k){
                int ru = dsu.find(u);
                int rk = dsu.find(k);
                if(ru != rk){
                    // もし頂点1を含む側と併合するときは compSize を更新
                    // 一方だけが頂点1を含むかどうかをチェック
                    if(dsu.find(1) == ru || dsu.find(1) == rk){
                        compSize += dsu.size[ru] + dsu.size[rk] - max(dsu.size[ru], dsu.size[rk]);
                    }
                    dsu.unite(u, k);
                }
            }
        }
        // DSU内で，頂点 1 を含む成分のサイズを更新（正確には dsu.size[dsu.find(1)] がそれ）
        compSize = dsu.size[ dsu.find(1) ];
 
        // S = {1,2,...,k}が連結でなければ不可能
        if(compSize != k) {
            ans[k] = -1;
        } else {
            // S内はすべて連結なので，S以外で隣接している頂点 j は j>k でかつ min_adj[j] <= k を満たす
            // 全体で j>=2 のうち min_adj[j] <= k の個数は P[k]
            // そのうち S 内 (2 <= j <= k) は必ず条件を満たすので個数は k-1 になるため，
            // 必要な削除回数は P[k] - (k-1) となる．
            ans[k] = P[k] - (k - 1);
        }
    }
    
    // 結果出力
    // k = 1 から N まで，それぞれの条件を満たすのに必要な最小操作回数（不可能なら -1）を出力．
    for (int k = 1; k <= N; k++){
        cout << ans[k] << "\n";
    }
    
    return 0;
}

