// B U B B L E    S O R T
//https://takeuforward.org/data-structure/bubble-sort-algorithm/
//https://www.geeksforgeeks.org/problems/bubble-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bubble-sort
/*
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order. This algorithm is not suitable for large data sets as its average and worst-case time complexity are quite high.
-We sort the array using multiple passes. After the first pass, the maximum element goes to end (its correct position). Same way, after second pass, the second largest element goes to second last position and so on.
-In every pass, we process only those elements that have already not moved to correct position. After k passes, the largest k elements must have been moved to the last k positions.
-In a pass, we consider remaining elements and compare all adjacent and swap if larger element is before a smaller element. If we keep doing this, we get the largest (among the remaining elements) at its correct position.

Time Complexity: O(n2)
Auxiliary Space: O(1)

Advantages of Bubble Sort:
-------------------------
Bubble sort is easy to understand and implement.
It does not require any additional memory space.
It is a stable sorting algorithm, meaning that elements with the same key value maintain their relative order in the sorted output.

Disadvantages of Bubble Sort:
----------------------------
Bubble sort has a time complexity of O(n2) which makes it very slow for large data sets.
Bubble sort has almost no or limited real world applications. It is mostly used in academics to teach different ways of sorting.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = n - 1; i >= 0; i--) {
        bool f = false;
        for (int j = 0; j < i; j++) {// we run only upto less than i, because we need to check with the next element
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                f = true;
            }
        }
        if (!f) break;
    }
    for (auto i : arr) cout << i << " ";
}
