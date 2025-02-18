//recursive insertion sort 
//https://takeuforward.org/arrays/recursive-insertion-sort-algorithm/
//https://www.geeksforgeeks.org/problems/insertion-sort/1
/*
Approach: 
In the iterative method, we did the following:

Take an element from the unsorted array(using an outer loop).
Place it in its corresponding position in the sorted part(using an inner loop).
Shift the remaining elements accordingly.
Now, in the recursive approach, we will just select the element recursively instead of using any loop. This is the only change we will do the recursive insertion sort algorithm and the rest of the part will be completely the same as it was in the case of iterative insertion sort.

The approach will be the following:

First, call the recursive function with the given array, the size of the array, and the index of the selected element(let's say i).
Inside that recursive function, take the element at index i from the unsorted array.
Then, place the element in its corresponding position in the sorted part(using swapping).
After that, Shift the remaining elements accordingly.
Finally, call the recursion increasing the index(i) by 1.
The recursion will continue until the index reaches n(i.e. All the elements are covered).
Base Case: if(i == n) return;
Note: Inside the recursion, the inner loop j will go back up to 1 not up to 0. Because, if the j becomes 0, we will try to access the element arr[j-1] i.e. arr[-1] while swapping. 
And so, it will give a runtime error.
Time Complexity: O(N2), (where N = size of the array), for the worst, and average cases.
Reason: If we carefully observe, we can notice that the recursion call will occur for n times, and for each i, inside the recursive function, the loop j runs from i to 1 i.e. i times. 
For, i = 1, the loop runs 1 time, for i = 2, the loop runs 2 times, and so on. 
So, the total steps will be approximately the following: 1 + 2 + 3 +……+ (n-2) + (n-1). 
The summation is approximately the sum of the first n natural numbers i.e. (n*(n+1))/2.
The precise time complexity will be O(n2/2 + n/2). Previously, we have learned that we can ignore the lower values as well as the constant coefficients. 
So, the time complexity is O(n2). Here the value of n is N i.e. the size of the array.
Space Complexity: O(N) auxiliary stack space.
*/
#include <bits/stdc++.h>
using namespace std;
void insertionSort(vector <int>& arr, int i, int n) {
    if (i == n) return;
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
        int temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
        j--;
    }
    insertionSort(arr, i + 1, n);
}
int main() {
    int n;
    cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    insertionSort(arr, 0, n);
    for (auto i : arr) cout << i << " ";
}
