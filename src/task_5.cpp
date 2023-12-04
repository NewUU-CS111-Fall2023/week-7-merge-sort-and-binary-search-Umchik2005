#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> kFrequentElements(vector<int>& nums, int k) {
    unordered_map<int, int> frequencyMap;
    for (int num : nums) {
        frequencyMap[num]++;
    }

    auto compare = [&](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);

    for (auto& entry : frequencyMap) {
        pq.push(entry);
        if (pq.size() > k) {
            pq.pop();
        }
    }

    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().first);
        pq.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int size;
    cin >> size;

    vector<int> nums(size);
    for (int i = 0; i < size; ++i) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    vector<int> result = kFrequentElements(nums, k);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}