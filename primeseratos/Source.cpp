#include <map>
#include <vector>
#include <math.h>
#include <iostream>
#include <chrono>

// This Function returns a vector containing all primes less than n using seive of eratosthenes
std::vector<long long> primes_less_than(long long n)
{
    std::vector<long long> ans(0);
    if (n <= 2)
        return ans;
    std::map<long long, bool> is_prime;
    for (long long i = 0; i < n; i++)
        is_prime[i] = true;
    is_prime[0] = false;
    is_prime[1] = false;
    for (long long i = 2; i < sqrt(n); i++)
        if (is_prime[i])
            for (long long j = i * i; j < n; j += i)
                is_prime[j] = false;
    for (long long i = 0; i < n; i++)
        if (is_prime[i] == true)
        {
            ans.push_back(i);
            // std::cout << "   " << i;
        }
    return ans;
}

int main()
{
    long long number{ 0 };
    std::cout << "\n how many ? ";
    std::cin >> number;
    std::cout << "\n\n" << std::endl;
    std::vector<long long> ldp;
    const std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
    ldp = primes_less_than(number);
    const std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
    std::cout << "\n" << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds  " << std::endl;
    std::cout << "\n\nldp = { ";
    for (long long n : ldp)
        std::cout << n << " ";
    std::cout << "}; \n";
    std::cin.get();
    std::cin.get();
    std::cin.get();
}