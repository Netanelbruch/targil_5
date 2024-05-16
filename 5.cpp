#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>





// A function to calculate the maximum complexity subseries operations O(n^3)
long maxSubArraySumN3(int a[], int size) {
    long maxSum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            long currentSum = 0;
            for (int k = i; k <= j; k++) {
                currentSum += a[k];
            }
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }
    return maxSum;
}

// A function to calculate the maximum complexity subseries operations O(n^2)
long maxSubArraySumN2(int a[], int size) {
    long maxSum = 0;
    for (int i = 0; i < size; i++) {
        long currentSum = 0;
        for (int j = i; j < size; j++) {
            currentSum += a[j];
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }
    return maxSum;
}

// A function to calculate the maximum complexity subseries operations O(n)
long maxSubArraySumN(int a[], int size) {
    long maxSum = 0, currentSum = 0;
    for (int i = 0; i < size; i++) {
        currentSum = std::max((long)a[i], (long)(currentSum + a[i]));
        maxSum = std::max(maxSum, currentSum);
    }
    return maxSum;
}

//A function to create a random array
void generateRandomArray(int a[], int size, int seed) {
    std::srand(seed);
    for (int i = 0; i < size; i++) {
        a[i] = std::rand() % 100 - 25; // Random numbers in the range -25 to 74
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Error\n";
        return 1;
    }

    int seed = std::atoi(argv[1]);
    int size = std::atoi(argv[2]);
    int* a = new int[size];

    generateRandomArray(a, size, seed);

    auto start = std::chrono::high_resolution_clock::now();
    long sumN3 = maxSubArraySumN3(a, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedN3 = end - start;
    std::cout << "O(n^3) Time: " << elapsedN3.count() << "s, Sum: " << sumN3 << std::endl;

    start = std::chrono::high_resolution_clock::now();
    long sumN2 = maxSubArraySumN2(a, size);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedN2 = end - start;
    std::cout << "O(n^2) Time: " << elapsedN2.count() << "s, Sum: " << sumN2 << std::endl;

    start = std::chrono::high_resolution_clock::now();
    long sumN = maxSubArraySumN(a, size);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedN = end - start;
    std::cout << "O(n) Time: " << elapsedN.count() << "s, Sum: " << sumN << std::endl;

    delete[] a;
    return 0;
}
