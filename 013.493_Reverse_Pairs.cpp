//493. Reverse Pairs - leetcode (hard) (acc : 31%)
//https://leetcode.com/problems/reverse-pairs/description/
/*
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:
0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
*/
class Solution {
public:
    void countpairs(vector <int> &nums, int low, int mid, int high, long long &cnt) {
        for (int i = low; i <= mid; i++) {
            long long target = floor((nums[i] - 1LL) / 2.0);//handles negative numbers and positive numbers properly
            //----------------------------------------------CAN ALSO KEEP THE BELOW CODE INSTEAD OF THE ABOVE LINE------------------------------------
            // if (nums[i] & 1) {
            //     if (nums[i] > 0)
            //     target = (nums[i]/2.0);
            //     else
            //     target = (nums[i]/2.0) - 1;//as we know negative numbers have higher value when coming near to 0, and as it wont correctly yields we will keep -1 as extra eg: -3/2 results -1 instead of -2 (wanted is -2)
            // }
            auto it = upper_bound(nums.begin() + mid + 1, nums.begin() + high + 1, target) - nums.begin();
            cnt += (it - (mid + 1));
        }
    }
    void merge(vector <int> &nums, int low, int mid, int high, long long &cnt) {
        int j = mid + 1;
        int i = low;
        vector <int> temp;
        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            }
            else {
                temp.push_back(nums[j++]);
            }
        }
        while (i <= mid) temp.push_back(nums[i++]);
        countpairs(nums, low, mid, high, cnt);
        while (j <= high) temp.push_back(nums[j++]);
        for (int x = low; x <= high; x++) {
            nums[x] = temp[x - low];
        }
    }
    void mergeSort(vector <int>& nums, int low, int high, long long &cnt) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(nums, low, mid, cnt);
        mergeSort(nums, mid + 1, high, cnt);
        merge(nums, low, mid, high, cnt);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        mergeSort(nums, 0, n - 1, cnt);
        // for (auto i : nums) cout << i << " ";
        return cnt;
    }
};
