/*
 * Author: Umchik
 * Date: 04/12/2023
 * Name: Muhammad Umar Toshpo'latov
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int a;
    std::cin >> a;

    while (a--) { 
        int n;
        std::cin >> n;

        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }

        int sum = 0;
        int count = 0;

        for (int i = 0; i < n - 2; ++i) {
            int oddLength = std::min(n - i, 3);

            if (oddLength % 2 == 1) {
                std::vector<int> temp;

                for (int j = i; j < i + oddLength; ++j) {
                    temp.push_back(arr[j]);
                }

                std::sort(temp.begin(), temp.end());
                int median = temp[oddLength / 2];
                sum += median;

                auto it = find(arr.begin() + i, arr.end(), median);
                if (it != arr.end()) {
                    arr.erase(it);
                    ++count;
                }
            }
        }

        int sumOfElements = 0;
        for (int i = 0; i < n - count; ++i) {
            sumOfElements += arr[i];
        }

        std::cout << sumOfElements << std::endl;
    }

    return 0;
}