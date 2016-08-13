# Inautix_practice
This repository contains Inautix_practice problems ( most of them are solved in C)

/*
iNautix Test 13:

1)	Filling Jars 
Calvin has N empty candy jars, numbered from 1 to N, with infinite capacity. He performs M operations. Each operation is described by 3 integers a, b and k, where, a and b are indices of the jars, and k is the number of jelly beans to be added inside each jar whose index lies between a and b (inclusive of both a and b). Your task is to compute the average number of jelly beans per jar after M operations?

Input Format
The first line contains two integers N and M separated by a single space.
M lines follow. Each of the M lines contain the three integers described above, a, b and k, separated by a single space.

Output Format
A single line containing the average number of candies across N jars, rounded down to the nearest integer.
(Rounded down means finding the greatest integer which is less than or equal to given number. Eg, 13.65 and 13.23 is rounded down to 13, while 12.98 is rounded down to 12.)

Constraints
3 ≤ N ≤ 107
1 ≤ M ≤ 105
1 ≤ a ≤ b ≤ N
0 ≤ k ≤ 106

Sample Input #00
5 3
1 2 100
2 5 100
3 4 100

Sample Output #00
160

Explanation 
Initially each of the jar contains 0 candies
0 0 0 0 0  
First operation
100 100 0 0 0  
Second operation
100 200 100 100 100  
Third operation
100 200 200 200 100  
Total = 800, Average = 800/5 = 160
*/
Solution:

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    long long int n,m;
   long long int a,b,k;
    scanf("%ld %ld",&n,&m);
    long long int i,sum=0;
    while(m--)
    {
        scanf("%ld %ld %ld",&a,&b,&k);
        sum=sum+((b-a+1)*k);			//(b-a+1) -> no of jars added  (   multiply by )   k (amount added)
    }
    printf("%ld",sum/n);
 
    return 0;
}


/*
2)	Cut the Sticks:

Given an array, lengths, of N stick lengths (where each length is a positive integer), a cut operation reduces the length of each stick in the array by the length of the array's shortest stick. A stick can only be cut if it has a length ≥ 1.
 
Complete the cutSticks function in your editor, It has 1 parameters:
1.	An integer array of stick lengths, lengths (as well as the size of the array where required by the language).
 
Your function must perform cut operations on lengths until every stick length is reduced to 0 and return an integer array, where ith element of the array denotes the individual sticks cut during the ith operation.
 
Input Format
The following input from stdin is handled for you by the locked stub code in your editor:
The first line contains an integer, N, the length of lengths. The N subsequent lines describe the elements in lengths.
 
Constraints
•	1 ≤ N ≤ 103
•	1 ≤ lengths[i] ≤ 103, where 0 ≤ i ≤ N−1
 
Output Format
Your function must return an integer array, where ith element of the array denotes the individual sticks cut during the ith operation. This is printed to stdout by the locked stub code in your editor.
 
Sample Input 1
6
5
4
4
2
2
8
 
Sample Output 1
6
4
2
1
 
Sample Input 2
8
1
2
3
4
3
3
2
1
 
Sample Output 2
8
6
4
1
 
Explanation
Sample Case 1:
|lengths| = 6, lengths = {5, 4, 4, 2, 2, 8}
Cut Operation 1: The smallest length in lengths is 2, so the cut length for this cut operation is 2. After cutting (reducing) each stick in lengths by 2, lengths1 = {3, 2, 2, 0, 0, 6} and we print 6 (the number of sticks cut during the cut operation) on a new line.
 
Cut Operation 2: The smallest length in lengths1 = {3, 2, 2, 0, 0, 6} is 2, so the cut length for this cut operation is 2. After cutting (reducing) each stick in lengths1 by 2, lengths2 = {1, 0, 0, 0, 0, 4} and we print 4 (the number of sticks cut during the cut operation) on a new line.
 
Cut Operation 3: The smallest length in lengths2 = {1, 0, 0, 0, 0, 4} is 1, so the cut length for this cut operation is 1. After cutting (reducing) each stick in lengths2 by 1, lengths3 = {0, 0, 0, 0, 0, 3} and we print 2 (the number of sticks cut during the cut operation) on a new line.
 
Cut Operation 3: The smallest length in lengths3 = {0, 0, 0, 0, 0, 3} is 3, so the cut length for this cut operation is 3. After cutting (reducing) each stick in lengths3 by 3, lengths4 = {0, 0, 0, 0, 0, 0} and we print 1 (the number of sticks cut during the cut operation) on a new line.
 
At this point, there are no more sticks to be cut and we cease performing cut operations.
 
Sample Case 2:
    lengths       cut length   count cuts
1 2 3 4 3 3 2 1       1           8
_ 1 2 3 2 2 1 _       1           6
_ _ 1 2 1 1 _ _       1           4
_ _ _ 1 _ _ _ _       1           1
_ _ _ _ _ _ _ _     DONE        DONE
*/

Solution: 

int main()
{
	int n,i,*a,result_size;
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	int *ans;
	ans=cutSticks(n,a,&result_size);
	for(i=0;i<result_size;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
int *cutSticks (int n,int *lengths,int *result_size)
{
	int i,j,min;
	while(cuts>1)
	{
		int zero=0,cuts=0;
		for(i=0;i<n;i++)
		{
			if(lengths[i]!=0)
			{
				min=lengths[i];		// to make sure initial minimum value is not 0
			}
		}
		for(i=0;i<n;i++)
		{
			if(lengths[i]<min && lengths[i]!=0)
			{
				min=lengths[i];			//finding the minimum value
			}
		}
		for(i=0;i<n;i++)
		{
			if(lengths[i]!=0)
			{
				lengths[i] -= min;			//actual cut operations
				cuts++;
			}
			elseif(lengths[i] == 0)
			{
				zero++;				//no of sticks completely cut
			}
		}
		if(n==zero)
		{
			break;				// IF ALL sticks are cut then break the loop
		}
		result[k]=cuts;				//Store the no of cuts in array
		k++;
	}
	return result;
}
