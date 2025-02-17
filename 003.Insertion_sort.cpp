// I N S E R T I O N    S O R T
//https://takeuforward.org/data-structure/insertion-sort-algorithm/
//https://www.geeksforgeeks.org/problems/insertion-sort/0?category%5B%5D=Algorithms&page=1&query=category%5B%5DAlgorithmspage1&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insertion-sort
/*
Insertion sort is a simple sorting algorithm that works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list. 
It is like sorting playing cards in your hands. You split the cards into two groups: the sorted cards and the unsorted cards. 
Then, you pick a card from the unsorted group and put it in the right place in the sorted group.
-We start with second element of the array as first element in the array is assumed to be sorted.
-Compare second element with the first element and check if the second element is smaller then swap them.
-Move to the third element and compare it with the first two elements and put at its correct position
-Repeat until the entire array is sorted.

Time Complexity of Insertion Sort:
---------------------------------
Best case: O(n), If the list is already sorted, where n is the number of elements in the list.
Average case: O(n2), If the list is randomly ordered
Worst case: O(n2), If the list is in reverse order

Space Complexity of Insertion Sort:
-----------------------------------
Auxiliary Space: O(1), Insertion sort requires O(1) additional space, making it a space-efficient sorting algorithm.

Advantages of Insertion Sort:
----------------------------
-Simple and easy to implement.
-Stable sorting algorithm.
-Efficient for small lists and nearly sorted lists.
-Space-efficient as it is an in-place algorithm.
-Adoptive. the number of inversions is directly proportional to number of swaps. For example, no swapping happens for a sorted array and it takes O(n) time only.

Disadvantages of Insertion Sort:
--------------------------------
-Inefficient for large lists.
-Not as efficient as other sorting algorithms (e.g., merge sort, quick sort) for most cases.

Applications of Insertion Sort:
------------------------------
Insertion sort is commonly used in situations where:
-The list is small or nearly sorted.
-Simplicity and stability are important.
-Used as a subroutine in Bucket Sort
-Can be useful when array is already almost sorted (very few inversions)
-Since Insertion sort is suitable for small sized arrays, it is used in Hybrid Sorting algorithms along with other efficient algorithms like Quick Sort and Merge Sort.
When the subarray size becomes small, we switch to insertion sort in these recursive algorithms. For example IntroSort and TimSort use insertions sort.
*/
#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using insertion Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertion_sort(arr, n);
    return 0;
}
