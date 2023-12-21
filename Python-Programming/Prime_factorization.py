def prime_factorizer(n):
    if n < 2:
        return []
    
    prime_factors = []
    i = 2
    while i * i <= n:
        if n % i == 0:
            count = 0
            while n % i == 0:
                n //= i
                count += 1
            prime_factors.append((i, count))
        i += 1

    if n > 1:
        prime_factors.append((n, 1))

    return prime_factors

# Example of usage
result = prime_factorizer(30)
print(result)