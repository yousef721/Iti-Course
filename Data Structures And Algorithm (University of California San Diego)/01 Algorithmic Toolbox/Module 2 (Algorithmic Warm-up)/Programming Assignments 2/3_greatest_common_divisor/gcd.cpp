#include <iostream>
using namespace std;

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int euclidGCD(int a, int b)
{
  if (b == 0)
    return a;
  int aPrime = a % b;
  return euclidGCD(b, aPrime);
}

int main() {
  int a, b;
  cin >> a >> b;
  // cout << gcd_naive(a, b) << endl;
  cout << euclidGCD(a, b) << endl;
  return 0;
}

/*
--------------------------------------------
-- Explanation of Euclid's Algorithm
--------------------------------------------
The goal is to find the Greatest Common Divisor (GCD)
of two integers a and b — the largest number that divides both without a remainder.

--------------------------------------------
-- Euclid’s Law (Key Lemma)
--------------------------------------------
If we divide 'a' by 'b' and get a remainder 'aPrime', that is:

  a = b × q + aPrime     (where q is the quotient)

Then, the GCD of 'a' and 'b' is the same as the GCD of 'b' and 'aPrime':

  gcd(a, b) = gcd(b, aPrime)

This can also be written in programming form as:

  gcd(a, b) = gcd(b, a % b)
  and if b = 0 → gcd(a, 0) = a

--------------------------------------------
-- Meaning
--------------------------------------------
This rule allows us to repeatedly replace the larger number (a)
with the remainder (a % b) until the remainder becomes zero.
At that point, the other number (b) is the GCD.

--------------------------------------------
-- Example
--------------------------------------------
Find gcd(48, 18):

  Step 1 → gcd(48, 18) = gcd(18, 48 % 18) = gcd(18, 12)
  Step 2 → gcd(18, 12) = gcd(12, 18 % 12) = gcd(12, 6)
  Step 3 → gcd(12, 6)  = gcd(6, 12 % 6)  = gcd(6, 0)
  --> GCD = 6

--------------------------------------------
-- Why It Works
--------------------------------------------
Because the common divisors of (a, b) are exactly the same
as the common divisors of (b, a % b).
Thus, replacing 'a' with 'a % b' preserves the GCD.

--------------------------------------------
-- Time Complexity
--------------------------------------------
Naive method:     O(min(a, b))       → Slow for large inputs  
Euclid’s method:  O(log(min(a, b)))  → Very fast and efficient
--------------------------------------------
*/

