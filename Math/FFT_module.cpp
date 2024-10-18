//ROOTS
pii find_c_k(int mod) {
  pii ans;
  for(int k = 1; (1<<k) < mod; k++) {
    int pot = 1<<k;
    if((mod - 1) % pot == 0)
      ans = {(mod-1) / pot, k};
  }
  return ans;
}

int find_primitive_root(int mod) {
  vector<bool> seen(mod);
  for(int r = 2; ; r++) {
    fill(seen.begin(), seen.end(), 0);
    int cur = 1, can = 1;
    for(int i = 0; i <= mod-2 && can; i++) {
      if(seen[cur]) can = 0;
      seen[cur] = 1;
      cur = (1ll*cur*r) % mod;
    }
    if(can)
      return r;
  }
  assert(false);
}
//END ROOTS

const int mod = 998244353, root = 15311432, root_1 = 469870224, root_pw = 1<<23 ;

int pw(int x, int e){
  int ret = 1;
  while(e){
    if(e&1) ret = 1ll * x * ret % mod;
    x = 1ll * x * x % mod;
    e >>= 1;
  }
  return ret;
}

struct FFT
{
  void fft(vector<int> & a, bool invert) {
      int n = a.size();
      for (int i = 1, j = 0; i < n; ++i) {
          int bit = n >> 1;
          for (; j & bit; bit >>= 1)
              j ^= bit;
          j ^= bit;
          if (i < j) swap(a[i], a[j]);
      }

      for (int len = 2; len <= n; len <<= 1) {
          int wlen = invert ? root_1 : root;
          for (int i = len; i < root_pw; i <<= 1)
              wlen = 1LL * wlen * wlen % mod;

          for (int i = 0; i < n; i += len) {
              int w = 1;
              for (int j = 0; j < len / 2; ++j) {
                  int u = a[i+j], v = 1LL * a[i+j+len/2] * w % mod;
                  a[i+j] = u + v < mod ? u + v : u + v - mod;
                  a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                  w = 1LL * w * wlen % mod;
              }
          }
      }

      if (invert) {
          int n_1 = pw(n, mod-2);
          for (int & x : a)
              x = 1LL * x * n_1 % mod;
      }
  }

  vector<int> multiply(vector<int> const& a, vector<int> const& b) {
      vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
      int n = 1;
      while (n < a.size() + b.size()) 
          n <<= 1;

      fa.resize(n);
      fb.resize(n);

      fft(fa, false);
      fft(fb, false);

      for (int i = 0; i < n; i++)
          fa[i] = 1LL * fa[i] * fb[i] % mod;    
      fft(fa, true);
      
      return fa;
  }
};

FFT A;
