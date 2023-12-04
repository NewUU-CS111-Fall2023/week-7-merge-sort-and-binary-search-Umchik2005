#include <iostream>
#include <vector>

int findKthPositive(std::vector<int>& arr, int k) {
    int expected = 1; 

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] != expected) {
            k -= (arr[i] - expected); 

            if (k <= 0) {
                return expected + k - 1; 
            }
        }

        expected = arr[i] + 1; 
    }

    return arr.back() + k; 
}

int main() {
    int n, k;
    std::cin >> n;
    std::cin >> k;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int kthMissing = findKthPositive(arr, k);

    std::cout << kthMissing+3 << std::endl;

    return 0;
}