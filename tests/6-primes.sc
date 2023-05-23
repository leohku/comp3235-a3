array primes[100];

func isPrime(n) {
    if (n < 2) {
        return 0;
    }

    for (i = 2; i * i <= n; i = i + 1;) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

puts_("Find first n prime numbers (max 100): ");
geti(maxCount);
count = 0;
num = 2;

while (count < maxCount) {
    if (isPrime(num)) {
        primes[count] = num;
        count = count + 1;
    }

    num = num + 1;
}

puts_("The first ");
puti_(maxCount);
puts_(" prime numbers are: ");
for (i = 0; i < maxCount; i = i + 1;) {
    puti_(primes[i]);
    puts_(" ");
}

// input: 10
// expect "The first 10 prime numbers are: 2 3 5 7 11 13 17 19 23 29"
