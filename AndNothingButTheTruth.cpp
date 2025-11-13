// AndNothingButTheTruth.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 1) Check if sorted
bool isSorted(const vector<int>& v) {
    for (size_t i = 1; i < v.size(); ++i)
        if (v[i] < v[i - 1]) return false;
    return true;
}

// 2) Verify subset sum
bool verifySubsetSum(const vector<int>& nums, const vector<int>& indices, int target) {
    int sum = 0;
    for (int idx : indices) {
        if (idx < 0 || idx >= (int)nums.size()) return false;
        sum += nums[idx];
    }
    return sum == target;
}

// Helper for #3
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0) return false;
    return true;
}

// 3) Verify prime factorization
bool verifyPrimeFactorization(int number, const vector<int>& factors) {
    if (number <= 1) return false;
    long long product = 1;
    for (int f : factors) {
        if (!isPrime(f)) return false;
        product *= f;
    }
    return product == number;
}

// Demo
int main() {
    // Test 1
    vector<int> sorted = { 1, 2, 3, 4 };
    cout << "Sorted? " << (isSorted(sorted) ? "true" : "false") << endl;

    // Test 2
    vector<int> nums = { 4, 2, 7, 1 };
    vector<int> indices = { 1, 2 }; // 2 + 7 = 9
    cout << "Subset sum valid? " << (verifySubsetSum(nums, indices, 9) ? "true" : "false") << endl;

    // Test 3
    int number = 60;
    vector<int> factors = { 2, 2, 3, 5 }; // 2*2*3*5 = 60
    cout << "Prime factorization valid? " << (verifyPrimeFactorization(number, factors) ? "true" : "false") << endl;

    return 0;
}

