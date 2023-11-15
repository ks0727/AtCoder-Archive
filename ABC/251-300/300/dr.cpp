#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll pow(int a, int b){
    ll ans = 1;
    rep(i,b) ans *= a;
    return ans;
}

vector<ll> SieveOfEratosthenes(ll n)
{
    cout << "ok" << endl;
    cout << n << endl;
	bool prime[n+1];
    vector<ll> primes;
	memset(prime, true, sizeof(prime));
	for (ll p=2; (ll)p*p<=n; p++)
	{
		if (prime[p] == true)
		{
			// Update all multiples of p
			for (ll i=p*2; i<=n; i += p)
				prime[i] = false;
		}
	}
	// Print all prime numbers
	for (ll p=2; p<=n; p++) if(prime[p]) primes.push_back(p);
    return primes;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> primes;
    primes = SieveOfEratosthenes(n/10);
    int psize = primes.size();
    int ans = 0;
    rep(i,psize){
        int a = primes[i];
        if(a*a > n) break;
        for(int j = i+1;j<(psize);j++){
            int b = primes[j];
            if(a*a*b > n) break;
            for(int k = j+1;k<(psize);k++){
                int c = primes[k];
                if((ll)a*a*b*c*c <= n){
                    ans++;
                }
                else break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}