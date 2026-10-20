#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;

//-------------------------------------------------
//modint について
template <std::uint_fast64_t Modulus> class modint {
    using u64 = std::uint_fast64_t;

public:
    u64 a;

    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
    constexpr u64 &value() noexcept { return a; }
    constexpr const u64 &value() const noexcept { return a; }
    constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
    }
    constexpr modint &operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
        a -= Modulus;
        }
        return *this;
    }
    constexpr modint &operator-=(const modint rhs) noexcept {
        if (a < rhs.a) {
        a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr modint &operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint &operator/=(modint rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
        if (exp % 2) {
            *this *= rhs;
        }
        rhs *= rhs;
        exp /= 2;
        }
        return *this;
    }
};
//------------------------------------------

// (base^exp) % mod を計算する関数
long long power(long long base, long long exp) {
    long long res = 1;
    base %= mod; // base が mod よりも大きい場合の対策
    
    while (exp > 0) {
        // exp の奇数ビットが立っている場合、答えに base を掛ける
        if (exp % 2 == 1) res = (res * base) % mod;
        
        // base を二乗し、指数を半分にする
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
//-----------------------------------------

// a^n mod を計算する
long long modpow(long long a, long long n) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

//-------------------------------------------------------
//nCr
const int MAX = 510000;
const int MOD = mod;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理 初めにこれを実行しとかないといけない
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算　その後これを使える
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//-------------------------------------------
//nCk で n が大きくてkが kmax 以下の時はこっちがいい
const long long KMAX = 1000005;

vector<long long> fact(KMAX), ifact(KMAX);
void init(){
    fact[0] = 1;
    for(int i = 1; i < KMAX; i++){
        fact[i] = fact[i - 1] * i % mod;
    }

    ifact[KMAX - 1] = modpow(fact[KMAX - 1], mod - 2);

    for(int i = KMAX - 2; i >= 0; i--){
        ifact[i] = ifact[i + 1] * (i + 1) % mod;
    }
}
// 二項係数計算　その後これを使う
long long COM(long long n, long long k){
    if(n < k || k < 0) return 0;

    long long num = 1;

    for(long long i = 0; i < k; i++){
        num = num * ((n - i) % mod) % mod;
    }

    return num * ifact[k] % mod;
}


//--------------------------------------------------------


//mod. mでの a の逆元 a^{-1} を計算する
//mod が変わる場合はほかに m として mod も受け取ってから計算するようにしたらいい
long long modinv(long long a) {
	long long b = mod, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= mod; 
	if (u < 0) u += mod;
	return u;
}

//---------------------------------------------------------------

// ユークリッドの互除法を用いて最大公約数を求める関数
int Gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return Gcd(b, a % b);
}

int gcd2(int a, int b){
    int result = gcd(a, b);
    return result;
}
//-------------------------------------------


using mint = modint<mod>;

int main() {
	// mod. 13 での逆元を求めてみる
	for (int i = 1; i < 13; ++i) {
        //1 を i でわったときの mod を表している
		cout << i << " 's inv: " << modinv(i) << endl;
	}

    //mint を使う
    mint a = 10;
    mint b = 3;

    mint c = a + b;
    mint d = a - b;
    mint e = a * b;
    mint f = a / b;

    cout << c.value() << " " << d.value() << " " << e.value() << " " << f.value() << endl;
}
