//Recursive bubble sort 
//https://takeuforward.org/arrays/recursive-bubble-sort-algorithm/
//https://www.geeksforgeeks.org/problems/bubble-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bubble-sort
/*
In the iterative method, we usually select a range(using a loop), and for each range, we repeatedly swap(using another loop) the adjacent elements(if arr[i] > arr[i+1]) until the maximum element in that range reaches the end.

The flow of the algorithm goes like this: in the first iteration, we select the range 0 to n-1 and swap adjacent elements(if arr[i] > arr[i+1]) until the maximum element reaches the (n-1)th index. Similarly, in the second iteration, the second maximum element reaches the (n-2)th index. So, the sorting basically occurs in the backward direction.  After (n-1) such iterations we get the sorted array.

Now, in the recursive approach, we will just select the range recursively instead of using any loop. This is the only change we will do the recursive bubble sort algorithm and the rest of the part will be completely the same as it was in the case of iterative bubble sort.

The approach will be the following:

First, call the recursive function with the given array and the range of n(size of the array).
Inside that recursive function, repeatedly swap 2 adjacent elements if arr[j] > arr[j+1].
Here, the maximum element of the unsorted array reaches the end of the unsorted array after each recursive call.
Each time after step 2, call the recursion again decreasing the range by 1.
The recursion will continue until the range(i.e. the size) of the array is reduced to 1.
Base Case: if(n == 1) return;

The best case occurs if the given array is already sorted. We can reduce the time complexity to O(N) by just adding a small check inside the recursive function. 

We will check in the first recursion call if any swap is taking place. If the array is already sorted no swap will occur and we will return from the recursion call. 
Thus the number of recursions will be just 1. And our overall time complexity will be O(N).
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void bs(vector <int>& arr, int n) {
        if (n == 1) return;//base case
        bool f = true;
        for (int j = 0; j < n - 1; j++) {
            //kept j < n - 1, because we are checking with the next element
            if (arr[j] > arr[j + 1]) {//perform same bubble sort here
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                f = false;
            }
        }
        if (f) return;//if no operation is performed, we can return
        bs(arr, n - 1);// call with n - 1
    }
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        bs(arr, n);
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;

        ob.bubbleSort(arr);
        for (int e : arr) {
            cout << e << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Endshttps://media.geeksforgeeks.org/img-practice/chatIcon-1653561581.svg
