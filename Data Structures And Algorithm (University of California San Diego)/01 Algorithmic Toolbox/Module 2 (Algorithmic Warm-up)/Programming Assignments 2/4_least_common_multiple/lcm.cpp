#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd(long long a, long long b)
{
  if (b == 0)
    return a;
  long long aPrime = a % b;
  return gcd(b, aPrime);
}
long long lcm_fast(long a, long long b)
{ 
  return ((long long)(a * b)) / gcd(a, b);
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  // std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}

/*
----------------------------------------------------------
-- Explanation of the program step by step:
----------------------------------------------------------

Goal:
   Find the **Least Common Multiple (LCM)** of two integers a and b.

Definition:
LCM(a, b) is the smallest positive number that is divisible by both a and b.

Example:
a = 6, b = 8
Multiples of 6: 6, 12, 18, 24, 30, ...
Multiples of 8: 8, 16, 24, 32, ...
LCM(6, 8) = 24 

----------------------------------------------------------
-- 1. Naive approach (lcm_naive)
----------------------------------------------------------
- Loops through every number `l` from 1 to a*b.
- Checks if `l` is divisible by both `a` and `b`.
- Returns the first such number.
Slow because it may run up to a*b iterations.

Example:
For a=6, b=8:
It will check 1,2,3,...24 until it finds 24.

----------------------------------------------------------
-- 2. Efficient approach (lcm_fast)
----------------------------------------------------------
- Uses the mathematical relation:
  👉 LCM(a, b) × GCD(a, b) = a × b

- So, LCM(a, b) = (a × b) / GCD(a, b)

To find GCD, we use the **Euclidean algorithm**:
- gcd(a, b) = gcd(b, a % b)
- Repeat until b = 0.
----------------------------------------------------------
-- Example
----------------------------------------------------------
gcd(8, 6)
→ gcd(6, 2)
→ gcd(2, 0)
GCD = 2

Then LCM = (8 × 6) / 2 = 24

----------------------------------------------------------
-- Time Complexity
----------------------------------------------------------
lcm_naive → O(a × b)          → Slow for large inputs  
lcm_fast  → O(log(min(a, b))) → Very fast and efficient

*/