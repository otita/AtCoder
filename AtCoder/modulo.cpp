#include <cstdint>
#include <climits>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

#define MOD 1000000007

// (a + b) % d
u32 modadd(u32 a, u32 b, u32 d) {
  if (a >= d) {
    a %= d;
  }
  if (b >= d) {
    b %= d;
  }
  u64 ans = u64(a) + u64(b);
  ans %= d;
  return u32(ans);
}

// (a * b) % d
u32 modmult(u32 a, u32 b, u32 d) {
  if (a >= d) {
    a %= d;
  }
  if (b >= d) {
    b %= d;
  }
  if (a == 0 || b == 0) {
    return 0;
  }
  u64 res;
  if (a >= d / b) {
    u64 upper = a >> 16;
    u64 lower = a & 0xFFFF;
    u64 x = ((b * upper) % d) << 16;
    u64 y = b * lower;
    res = (x + y) % d;
  }
  else {
    res = a * b;
  }
  return u32(res);
}

// (a ^ b) % d
u32 modpow(u32 a, u32 b, u32 d) {
  u64 res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % d;
    }
    a *= a % d;
    b >>= 1;
  }
  return u32(res);
}