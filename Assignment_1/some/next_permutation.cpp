
#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // current subarray = arr[i.....j]

            //add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            int sum = 0;
            for(int k=i;k<=j;k++){
            sum += arr[j];

            }

            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}

int main()
{
    int arr[] = { 1,3,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
