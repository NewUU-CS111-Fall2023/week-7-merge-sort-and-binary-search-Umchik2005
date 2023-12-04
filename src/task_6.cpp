#include <iostream>
#include <vector>

using namespace std;

pair<int, int> searchPosition(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int index = 0;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            found = true;
            index = mid;
            break;
        } else if (nums[mid] < target) {
            left = mid + 1;
            index = left;
        } else {
            right = mid - 1;
            index = mid;
        }
    }

    if (found) {
        return make_pair(1, index);
    } else {
        return make_pair(-1, index);
    }
}

int main() {
    int size;
    cin>>size;
    vector<int> nums;
    for(int i = 0; i<size; i++){
        int tmp;
        cin>>tmp;
        nums.push_back(tmp);
    }
    int target;
    cin >> target;

    pair<int, int> result = searchPosition(nums, target);

    if (result.first == 1) {
        cout << "1 " << result.second << endl;
    } else {
        cout << "-1 " << result.second << endl;
    }

    return 0;
}