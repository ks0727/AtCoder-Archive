#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
const int MAX_N = 100000;  

vector<int> A(MAX_N);     
vector<int> freq(MAX_N);  
int distinct_count = 0; 

struct Query {
    int left, right, id;
};

void add(int index) {
    freq[A[index]]++;
    if (freq[A[index]] == 1) {
        distinct_count++;
    }
}

void remove(int index) {
    freq[A[index]]--;
    if (freq[A[index]] == 0) {
        distinct_count--;
    }
}

int main() {
    int N;
    cin >> N;
    rep(i,N) cin >> A[i];

    vector<Query> queries;
    int query_id = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            queries.push_back({i, j, query_id++});
        }
    }
    int Q = queries.size();
    int block_size = sqrt(N);
    sort(queries.begin(), queries.end(), [block_size](const Query &a, const Query &b) {
        if (a.left / block_size != b.left / block_size)
            return a.left / block_size < b.left / block_size;
        return a.right < b.right;
    });
    vector<ll> results(Q);
    int current_left = 0, current_right = -1;
    for (const auto& q : queries) {
        int left = q.left;
        int right = q.right;
        while (current_right < right) {
            add(++current_right);
        }
        while (current_right > right) {
            remove(current_right--);
        }
        while (current_left < left) {
            remove(current_left++);
        }
        while (current_left > left) {
            add(--current_left);
        }
        results[q.id] = distinct_count;
    }

    ll total_sum = 0;
    for (const auto& result : results) {
        total_sum += result;
    }
    cout << total_sum << endl;
    return 0;
}
