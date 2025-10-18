var isEven = function(n) {
    return n % 2 === 0;  // returns true if n is divisible by 2
};

var isOdd = function(n) {
    return !isEven(n);   // returns true if n is not divisible by 2
};

var power = function(x, n) {
    println("Computing " + x + " raised to power " + n + ".");
    
    // Base case: Any number raised to the power of 0 equals 1.
    // Mathematical law: x^0 = 1    (as long as x ≠ 0)
    if (n === 0)
    {
        return 1;
    }

    // Recursive Case 1: if n is negative, use reciprocal rule
    // Mathematical law: x^-n = 1 / (x^n)
    // Example: 2^-3 = 1 / (2^3) = 1/8 = 0.125
    if (n < 0)
    {
        return 1 / power(x, -n);
    }

    // Recursive Case 2: if n is odd
    // Mathematical law: x^n = x * x^(n-1)
    // Example: 3^3 = 3 * 3^2 = 3 * 9 = 27
    if (isOdd(n))
    {
        return x * power(x, n - 1);
    }

    // Recursive Case 3: if n is even
    // Mathematical law: x^n = (x^(n/2))²   when n is even
    // Example: 2^4 = (2^2)² = (4)² = 16
    // This reduces the number of recursive calls,
    // making the function faster than multiplying repeatedly.
    if (isEven(n))
    {
        var y = power(x, n / 2);
        return y * y;
    }
};

var displayPower = function(x, n) {
    println(x + " to the " + n + " is " + power(x, n));
};

displayPower(3, 0);
Program.assertEqual(power(3, 0), 1);

displayPower(3, 1);
Program.assertEqual(power(3, 1), 3);

displayPower(3, 2);
Program.assertEqual(power(3, 2), 9);

displayPower(3, -1);
Program.assertEqual(power(3, -1), 1/3);

displayPower(100, -1);
Program.assertEqual(power(100, -1), 1/100);

displayPower(2, -2);
Program.assertEqual(power(2, -2), 1/4);


/* 
    Example: power(2, -2)

        Step 1 → n = -2, so negative case applies
        → return 1 / power(2, 2)

        Step 2 → compute power(2, 2)
        since n = 2 (even)
        → y = power(2, 1)
        → return y * y

        Step 3 → compute power(2, 1)
        since n = 1 (odd)
        → return 2 * power(2, 0)

        Step 4 → power(2, 0) = 1  (base case)

    Now we go back up:

        power(2, 1) = 2 * 1 = 2
        power(2, 2) = 2 * 2 = 4
        power(2, -2) = 1 / 4 = 0.25

    Final Answer: 
    
        2^-2 = 0.25 
 */
