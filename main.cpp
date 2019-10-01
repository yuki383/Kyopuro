#include <bits/stdc++.h>
using namespace std;

vector<long> divisor(long n) {
  vector<long> ret;
  for(long i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(ret.begin(), ret.end());
  return (ret);
}

bool isPrime(int x); // 素数求める
int gcd(int a, int b); // 最大公約数求める
vector<int> primeFactorization(int x); // 素因数分解する
void forPrint(vector<long> list, string str); // intプリントする


vector<long> pickPrime(vector<long> x) {
  vector<long> ans;

  for (int i = 0; i < x.size(); i++) {
    if (isPrime(x[i])) {
      ans.push_back(x[i]);
    }
  }
  
  return ans;
}

int main() {
  long a, b;
  cin >> a >> b;

  // a, bの約数から素数を求める
  vector<long> a_primes = pickPrime(divisor(a));
  vector<long> b_primes = pickPrime(divisor(b));



  int ans = 0;
  //　a, b両方持っている約数(公約数)の数を求める
  for (int x = 0; x < a_primes.size(); x++) {
    for (int y = 0; y < b_primes.size(); y++) {
      if (a_primes[x] == b_primes[y]) {
        ans++;
      }
    }
  }

  // 1は素数ではないのでここで追加
  ans++;
  cout << ans << endl;
}

// 最大公約数
int gcd(int a, int b) {
  if (a%b == 0) {
    return b;
  } else return gcd(b, a%b);
}

bool isPrime(int x) {
  if (x < 2) return false;
  if (x == 2) return true;
  if (x % 2 == 0) return false;

  double num = sqrt(x);
  for (int i = 3; i <= num; i+=2) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

vector<int> primeFactorization(int x) {
  vector<int> ans;
  int i = 2;
  while (i*i <= x) {
    if (x % i == 0) {
      ans.push_back(i);
      x /= i;
    } else {
      i++;
    }
  }
  ans.push_back(x);
  return ans;
}

void forPrint(vector<long> list, string str) {
  for (int i = 0; i < list.size(); i++) {
    cout << str << ": " << list[i] << endl;
  }
}