//Inversion count - gfg (medium) (acc : 16%)
//https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
/*
Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void merge(vector<int>&arr, int low, int mid, int high, int& cnt) {
        int left = low, right = mid + 1;
        vector <int> temp;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                cnt += mid - left + 1;
                temp.push_back(arr[right]);
                right++;
            }
        }
        while (left <= mid) {//for left part remaining elements
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high) {//for right part remaining elements
            temp.push_back(arr[right]);
            right++;
        }
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    void mergeSort(vector <int>&arr, int low, int high, int& cnt) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid, cnt); // for left part
        mergeSort(arr, mid + 1, high, cnt); // for right part
        merge(arr, low, mid, high, cnt); // for sorting and merging
    }
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        int cnt = 0;
        mergeSort(arr, 0, n - 1, cnt);
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
