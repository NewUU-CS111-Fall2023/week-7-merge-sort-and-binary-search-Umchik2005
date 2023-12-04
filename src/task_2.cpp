#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> permutation[i];
    }

    int originalBeautifulness = 0;
    for (int i = 0; i < n; ++i) {
        originalBeautifulness += abs(permutation[i] - (i + 1));
    }

    int maxBeautifulness = originalBeautifulness;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            std::swap(permutation[i], permutation[j]);

            int currentBeautifulness = 0;
            for (int k = 0; k < n; ++k) {
                currentBeautifulness += abs(permutation[k] - (k + 1));
            }

            maxBeautifulness = std::max(maxBeautifulness, currentBeautifulness);

            std::swap(permutation[i], permutation[j]);
        }
    }

    std::cout << maxBeautifulness << std::endl;

    return 0;
}