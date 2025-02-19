// C O U N T I N G   S O R T
//https://www.geeksforgeeks.org/problems/counting-sort/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
/*
It is not a comparision based sorting algorithm.It is particularly efficient when the range of input values is small compared to the number of elements to be sorted. The basic idea behind Counting Sort is to count the frequency of each distinct element in the input array and use that information to place the elements in their correct sorted positions.
For example, for input [1, 4, 3, 2, 2, 1], the output should be [1, 1, 2, 2, 3, 4]. The important thing to notice is that the range of input elements is small and comparable to the size of the array.
If the max element is of order more than n Log n where n is size of the array, then we can better sort the array using a standard comparison based sorting algorithm.

Working of Counting Sort:
-------------------------
Step1 :
Find out the maximum element from the given array.

Step 2:
Initialize a countArray[] of length max+1 with all elements as 0. This array will be used for storing the occurrences of the elements of the input array.

Step 3:
In the countArray[], store the count of each unique element of the input array at their respective indices.
For Example: The count of element 2 in the input array is 2. So, store 2 at index 2 in the countArray[]. Similarly, the count of element 5 in the input array is 1, hence store 1 at index 5 in the countArray[].

Step 4:
Store the cumulative sum or prefix sum of the elements of the countArray[] by doing countArray[i] = countArray[i – 1] + countArray[i]. This will help in placing the elements of the input array at the correct index in the output array.

Step 5:
Iterate from end of the input array and because traversing input array from end preserves the order of equal elements, which eventually makes this sorting algorithm stable.

Counting Sort Algorithm:
-----------------------
Declare an auxiliary array countArray[] of size max(inputArray[])+1 and initialize it with 0.
Traverse array inputArray[] and map each element of inputArray[] as an index of countArray[] array, i.e., execute countArray[inputArray[i]]++ for 0 <= i < N.
Calculate the prefix sum at every index of array inputArray[].
Create an array outputArray[] of size N.
Traverse array inputArray[] from end and update outputArray[ countArray[ inputArray[i] ] – 1] = inputArray[i]. Also, update countArray[ inputArray[i] ] = countArray[ inputArray[i] ]- – .

Complexity Analysis of Counting Sort:
-------------------------------------
Time Complexity: O(N+M), where N and M are the size of inputArray[] and countArray[] respectively.
Worst-case: O(N+M).
Average-case: O(N+M).
Best-case: O(N+M).
Auxiliary Space: O(N+M), where N and M are the space taken by outputArray[] and countArray[] respectively.

Advantage of Counting Sort:
---------------------------
Counting sort generally performs faster than all comparison-based sorting algorithms, such as merge sort and quicksort, if the range of input is of the order of the number of input.
Counting sort is easy to code
Counting sort is a stable algorithm.

Disadvantage of Counting Sort:
------------------------------
Counting sort doesn’t work on decimal values.
Counting sort is inefficient if the range of values to be sorted is very large.
Counting sort is not an In-place sorting algorithm, It uses extra space for sorting the array elements.

Applications of Counting Sort:
------------------------------
It is a commonly used algorithm for the cases where we have limited range items. For example, sort students by grades, sort a events by time, days, months, years, etc
It is used as a subroutine in Radix Sort
The idea of counting sort is used in Bucket Sort to divide elements into different buckets.
*/
#include <bits/stdc++.h>
using namespace std;
//counting sort
int find_max(vector<int>& a) {
    int maxi = 0;
    for (auto i : a) {
        if (maxi < i) maxi = i;//calculating maximum value
    }
    return maxi;
}

vector <int> countingSort(vector <int>& a) {
    int maxi = find_max(a);//finding the maximum element
    vector <int> count(maxi + 1);//declaring count array with size maxi + 1
    vector <int> b(a.size());
    for (auto i : a) count[i]++;//counting frequencies of elements
    //doing prefix sum for the index 
    for (int i = 1; i < count.size(); i++) count[i] += count[i - 1];
    for (int i = a.size() - 1; i >= 0; i--) {
        b[--count[a[i]]] = a[i];//pre decrementing and storing in that index
    }
    return b;
}

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector <int> ans = countingSort(a);//called sort and stored in another vector 
    for (auto i : ans) cout << i << " ";
}
