//sort 0's, 1's and 2's
//https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s/
//https://leetcode.com/problems/sort-colors/description/
//Dutch national flag algorithm
/*
For this problem, your goal is to sort an array of 0, 1 and 2's but you must do this in place, in linear time and without any extra space (such as creating an extra array). 
This is called the Dutch national flag sorting problem. 
For example, if the input array is [2,0,0,1,2,1] then your program should output [0,0,1,1,2,2] and the algorithm should run in O(n) time.

Approach:
--------
The solution to this algorithm will require 3 pointers to iterate throughout the array, swapping the necessary elements.

(1) Create a low pointer at the beginning of the array and a high pointer at the end of the array.
(2) Create a mid pointer that starts at the beginning of the array and iterates through each element.
(3) If the element at arr[mid] is a 2, then swap arr[mid] and arr[high] and decrease the high pointer by 1.
(4) If the element at arr[mid] is a 0, then swap arr[mid] and arr[low] and increase the low and mid pointers by 1.
(5) If the element at arr[mid] is a 1, don't swap anything and just increase the mid pointer by 1.

This algorithm stops once the mid pointer passes the high pointer.

Complexity:
----------
Time Complexity: O(N), where N = size of the given array.
Reason: We are using a single loop that can run at most N times.

Space Complexity: O(1) as we are not using any extra space.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        if (a[mid] == 0) {
            swap(a[low], a[mid]);
            low++;
            mid++;
        }
        else if (a[mid] == 1) {
            mid++;
        }
        else {
            swap(a[high], a[mid]);
            high--;
        }
    }
    for (auto i : a) cout << i << " ";
}
