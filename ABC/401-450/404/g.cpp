#include<iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    vector<long long> a(n);
    for (int i=1; i<=n-1; i++) cin >> c[i];
    for (int i=1; i<=n-1;i++) cin >> a[i];
    long long ans = 0;

    for (int i = n-1; i >= 1;i--) {
        if (a[i] == 0) continue;
        ans++;
        for(int j=c[i];j>=1;]j--){
          if(i-j<=0){
            a[i] = 0;
            break;
          }
          if(a[i-j] != 0){
            a[i] = 0:
            a[i-j] += a[i];
            break;
          }
        }
        if(a[i] != 0) a[max(0,i-c[i])] +=a[i];
        a[i] = 0;
    }
    cout << ans << endl;
    return 0;
}


