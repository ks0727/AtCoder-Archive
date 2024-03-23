p = 998244353
def modpow(a,n,mod):
    res = 1
    while n > 0:
        if n&1:
            res = res*a%mod
        a = a*a%mod
        n >>= 1
    return res

def modinv(a,mod):
    return modpow(a,mod-2,mod)

x = modinv(100,p)
x *= 10
x %= p
print(x)