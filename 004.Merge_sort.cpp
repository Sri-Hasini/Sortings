// M E R G E    S O R T
//https://takeuforward.org/data-structure/merge-sort-algorithm/
//https://www.geeksforgeeks.org/problems/merge-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-sort
/*
Merge sort is a sorting algorithm that follows the divide-and-conquer approach. It works by recursively dividing the input array into smaller subarrays and sorting those subarrays then merging them back together to obtain the sorted array.
In simple terms, we can say that the process of merge sort is to divide the array into two halves, sort each half, and then merge the sorted halves back together. This process is repeated until the entire array is sorted.
It is a DIVIDE AND CONQUER algorithm. It divides the given array into 2 equal parts and then merges the 2 sorted parts.
Merge sort is a popular sorting algorithm known for its efficiency and stability. It follows the divide-and-conquer approach to sort a given array of elements.
  Divide:  Divide the list or array recursively into two halves until it can no more be divided. 
  Conquer:  Each subarray is sorted individually using the merge sort algorithm. 
  Merge:  The sorted subarrays are merged back together in sorted order. The process continues until all elements from both subarrays have been merged. 

There are 2 main functions :
merge(): This function is used to merge the 2 halves of the array. It assumes that both parts of the array are sorted and merges both of them.
mergeSort(): This function divides the array into 2 parts. low to mid and mid+1 to high where,
 low = leftmost index of the array
 high = rightmost index of the array
 mid = Middle index of the array 
We recursively split the array, and go from top-down until all sub-arrays size becomes 1.

Approach:

We will be creating 2 functions mergeSort() and merge().
mergeSort(arr[], low, high):
----------------------------
In order to implement merge sort we need to first divide the given array into two halves. Now, if we carefully observe, we need not divide the array and create a separate array, but we will divide the array's range into halves every time. For example, the given range of the array is 0 to 4(0-based indexing). Now on the first go, we will divide the range into half like (0+4)/2 = 2. So, the range of the left half will be 0 to 2 and for the right half, the range will be 3 to 4. Similarly, if the given range is low to high, the range for the two halves will be low to mid and mid+1 to high, where mid = (low+high)/2. This process will continue until the range size becomes.
So, in mergeSort(), we will divide the array around the middle index(rather than creating a separate array) by making the recursive call :
1. mergeSort(arr,low,mid)   [Left half of the array]
2. mergeSort(arr,mid+1,high)  [Right half of the array]
where low = leftmost index of the array, high = rightmost index of the array, and mid = middle index of the array.
Now, in order to complete the recursive function, we need to write the base case as well. We know from step 2.1, that our recursion ends when the array has only 1 element left. So, the leftmost index, low, and the rightmost index high become the same as they are pointing to a single element.
Base Case: if(low >= high) return;

merge(arr[], low, mid, high):
-----------------------------
In the merge function, we will use a temp array to store the elements of the two sorted arrays after merging. Here, the range of the left array is low to mid and the range for the right half is mid+1 to high.
Now we will take two pointers left and right, where left starts from low and right starts from mid+1.
Using a while loop( while(left <= mid && right <= high)), we will select two elements, one from each half, and will consider the smallest one among the two. Then, we will insert the smallest element in the temp array.
After that, the left-out elements in both halves will be copied as it is into the temp array.
Now, we will just transfer the elements of the temp array to the range low to high in the original array.

Time Complexity:
---------------
Reason: At each step, we divide the whole array, for that logn and we assume n steps are taken to get sorted array, so overall time complexity will be nlogn
  Best Case: O(n log n), When the array is already sorted or nearly sorted.
  Average Case: O(n log n), When the array is randomly ordered.
  Worst Case: O(n log n), When the array is sorted in reverse order.
Auxiliary Space: O(n), Additional space is required for the temporary array used during merging.

Applications of Merge Sort:
---------------------------
Sorting large datasets
External sorting (when the dataset is too large to fit in memory)
Inversion counting
Merge Sort and its variations are used in library methods of programming languages.
Its variation TimSort is used in Python, Java Android and Swift. The main reason why it is preferred to sort non-primitive types is stability which is not there in QuickSort.
Arrays.sort in Java uses QuickSort while Collections.sort uses MergeSort.
It is a preferred algorithm for sorting Linked lists.
It can be easily parallelized as we can independently sort subarrays and then merge.
The merge function of merge sort to efficiently solve the problems like union and intersection of two sorted arrays.

Advantages:
-----------
Stability : Merge sort is a stable sorting algorithm, which means it maintains the relative order of equal elements in the input array.
Guaranteed worst-case performance: Merge sort has a worst-case time complexity of O(N logN) , which means it performs well even on large datasets.
Simple to implement: The divide-and-conquer approach is straightforward.
Naturally Parallel : We independently merge subarrays that makes it suitable for parallel processing.

Disadvantages:
--------------
Space complexity: Merge sort requires additional memory to store the merged sub-arrays during the sorting process.
Not in-place: Merge sort is not an in-place sorting algorithm, which means it requires additional memory to store the sorted data. This can be a disadvantage in applications where memory usage is a concern.
Merge Sort is Slower than QuickSort in general as QuickSort is more cache friendly because it works in-place.

*/
#include <bits/stdc++.h>
using namespace std;

//sorting & merging
void merge(vector <int>& arr, int low, int mid, int high) {
    int left = low, right = mid + 1;
    vector <int> temp;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    //if any elements remained in the left part, add them to the array
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    //if any elements remained in the right part, add them to the array
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    //update this sorted hypothetical arrays in the main array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

//dividing
void mergeSort(vector <int>&arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    //calling for dividing left part
    mergeSort(arr, low, mid);
    //calling for dividing right part
    mergeSort(arr, mid + 1, high);
    //conquering
    merge(arr, low, mid, high);
}

int main() {
    int n;
    cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    mergeSort(arr, 0, n - 1);
    for (auto i : arr) cout << i << " ";
}
