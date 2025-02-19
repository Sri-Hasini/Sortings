//counting sort using alphabets
//https://www.geeksforgeeks.org/problems/counting-sort/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
//Given a string arr consisting of lowercase english letters, arrange all its letters in lexicographical order using Counting Sort.
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    string countSort(string arr){
        string h = "";
        for (int i = 0; i < arr.size(); i++) h += 'a';
        vector <int> a(26);
        for (auto i : arr) {
            a[i - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            a[i] += a[i - 1];
        }
        for (int i = arr.size() - 1; i >= 0; i--) {
            h[--a[arr[i] - 'a']] = arr[i];
        }
        return h;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends
