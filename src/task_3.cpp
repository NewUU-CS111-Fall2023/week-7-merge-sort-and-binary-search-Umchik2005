#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N, M;
        std::cin >> N >> M;

        std::vector<int> A(N);
        std::vector<int> B(M);
        std::vector<int> result(N + M);

        for (int i = 0; i < N; ++i) {
            std::cin >> A[i];
        }

        for (int i = 0; i < M; ++i) {
            std::cin >> B[i];
        }

        merge(A.begin(), A.end(), B.begin(), B.end(), result.begin(), std::greater<int>());

        for (int i = 0; i < N + M; ++i) {
            std::cout << result[i] << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}