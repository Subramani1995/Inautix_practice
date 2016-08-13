# Inautix_practice
This repository contains Inautix_practice problems ( most of them are solved in C)

/*1)	Maximum difference in an array

The maximum difference between elements in some array, a, is defined as the largest difference between any a[i] and a[j] where i < j and a[i] < a[j]. For example, if a = [4, 1, 2, 3], the maximum difference would be a[3] - a[1] = 3 - 1 = 2 because this is the largest difference between any two elements satisfying the aforementioned criteria.
 
Complete the maxDifference function in the editor below. It has 1 parameter: an array of integers, a. It must return an integer denoting the maximum difference between any pair of elements in a; if no such number exists (e.g., if a is in descending order and all a[j] < a[i]), return -1 instead.
 
Input Format
Locked stub code in the editor reads the following input from stdin and passes it to the function:
The first line contains a single integer, n, denoting the number of elements in array a.
Each line i of the n subsequent lines (where 0 = i < n) contains a single integer describing element a[i].
 
Constraints
•	1 = n = 106
•	-106 = a[i] = 106 ? i ? [0, n - 1]
 
Output Format
The function must return an integer denoting the maximum difference in a. This is printed to stdout by locked stub code in the editor.
 
Sample Input 0
7
2
3
10
2
4
8
1
 
Sample Output 0
8
 
Explanation 0
n = 7, a = [2, 3, 10, 2, 4, 8, 1]
As a[2] = 10 is largest element in the array, we must find the smallest a[i] where 0 = i < 2. This ends up being 2 at index i = 0.
We then calculate the difference between the two elements: a[2] - a[0] = 10 - 2 = 8, and return the result (8).
 
Note: While the largest difference between any two numbers in this array is 9 (between a[2] = 10 and a[6] = 1), this cannot be the maximum difference because the element having the smaller value (a[6]) must be of a lesser index than the element having the higher value (a[2]). As j = 2 is not less than i = 6, these elements cannot be used to calculate the maximum difference.
 
Sample Input 1
6
7
9
5
6
3
2
 
Sample Output 1
2
 
Explanation 1
n = 6, a = [7, 9, 5, 6, 3, 2]
The maximum difference returned by the function is a[1] - a[0] = 9 - 7 = 2, because 2 is the largest difference between any a[i] and a[j] satisfying the conditions that a[i] < a[j] and i < j.
*/
Solution :

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//  Maximum difference in an Array
int MaxDiff(int ,int* );
int main()
{ 
    int n;
    scanf("%d",&n);
    int i,*arr;
    arr=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int result=MaxDiff(n,arr);
    printf("%d",result);
    return 0;
}
int MaxDiff(int n,int *arr)
{
    int max,index,ans,i,j,min;
    max=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]>max)          //finding the maximum element in the array
        {
            max=arr[i];
            index=i;            //storing the index of maximum element in the variale "index"
        }
    }
    min=arr[0];
    for(i=0;i<index;i++)  // to satisfy the condition i<j in the given statement of prob, we stop the iteration with index of max
    {
        if(arr[i]<min)          //finding the minimum element up to index
        {
            min=arr[i];
        }
    }
    ans=max-min;
    return ans;
}



/*2)	 Minimum Unique Array Sum
Complete the getMinimumUniqueSum function in your editor. It has 1 parameter: an array of n integers, arr. This function must return an integer denoting the sum of arr's n unique elements. If 2 or more elements in arr are not unique, it must increase the value of the duplicate element(s) to some other number(s) such that each element in arr is unique and the sum of arrunique's elements is minimal. The value of any element in arr cannot be increased more than 1 time.
 
Input Format
The locked stub code in your editor reads the following input from stdin and passes it to your function:
The first line contains an integer, n, denoting size of the array.
Each line i of the n subsequent lines (where 0 = i < n) contains an integer describing element i in array arr.
 
Constraints
•	1 = n = 2000
•	1 = arri = 3000
 
Output Format
Your function must return a single integer denoting the sum of arrunique's elements. This is printed to stdout by the locked stub code in your editor.
 
Sample Input 0
3
1
2
2
Sample Output 0
6
 
Sample Input 1
3
1
2
3
 
Sample Output 1
6
 
Sample Input 2
4
2
2
4
5
 
Sample Output 2
14
 
Explanation
Sample Case 0: arr = {1, 2, 2}
arr0 is unique, but arr1 and arr2 are duplicate elements. We increase the value of arr2 by 1 (the minimum amount we can increase the value by so that each element is unique) to get arrunique = {1, 2, 3}. We then return the sum of these elements, which is 6.
 
Sample Case 1: arr = {1, 2, 3}
Each number in arr is unique, so we do not need to modify any of its elements (i.e., arr = arrunique). We return the sum of all elements in the array, which is 6.
 
Sample Case 2: arr = {2, 2, 4, 5}
Because arr1  and arr2 are all duplicates, we must increase one of the two elements in such a way that they are two unique elements having a minimal sum. When we do this, we get arrunique = {2, 3, 4, 5}. We then return the sum of these elements, which is 14.
*/
Solution:

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// sum of unique elements in an array
int Unique_sum(int ,int* );
int main()
{ 
    int n;
    scanf("%d",&n);
    int i,*arr;
    arr=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int result=Unique_sum(n,arr);
    printf("%d",result);
    return 0;
}
int Unique_sum(int n,int *arr)
{
    int i,j,sum=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i] == arr[j])        //if 2 elements of the array are equal increment one of them by '1'
            {
                arr[j] = arr[j]+1;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        sum  += arr[i];                 //sum of all elements
    }
    return sum;
}





