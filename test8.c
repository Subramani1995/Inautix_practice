# Inautix_practice
This repository contains Inautix_practice problems ( most of them are solved in C)

iNautix Test – 8

/*1)	Power of 2
Complete the function provided to identify if the given integer is a power of 2, returning 1 if it is and 0 otherwise. The code to handle input and output is already provided.
 
Input Format
An array A of positive integers 
 
Output Format
An array of integers containing 1's and 0's
 
Constraints
•	1 <= Array Size <= 100
•	1 <= A[i] <= 5x107
 
Sample Input #1:
{2,3,4}
 
Sample Output #1:
{1,0,1}
 
Sample Input #2:
{1024,2048,1048576}
 
Sample Output #2: 
{1,1,1} 
*/
Solution:

#include<stdio.h>
#include<stdlib.h>
int* countPowers(int ,int *);
int main()
{
    int n,*arr,i,*res;
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    res=countPowers(n,arr);
    for(i=0;i<n;i++)
        printf("%d ",res[i]);
    return 0;
}
int* countPowers(int n,int *arr)
{
    int *res=(int *)malloc(n*sizeof(int));
    int i,k,flag=0;
    for(i=0;i<n;i++)
    {
        flag=0;
       int val=arr[i];
       while(val!=1)                //logic behind this is binary form of a 2^n is always like 10,100,1000,10000.....
       {
           k=val%2;
           if(k!=0)
           {
               flag=1;
               res[i]=0;
               break;
           }
           val=val/2;
        }
        if(flag!=1)
            res[i]=1;
    }
    return res;
}

/*
2)	Braces
Braces in a string are considered to be balanced if the following criteria are met:
•	For every opening brace (i.e.: (, {, or [), there is a matching closing brace (i.e.: ), }, or ]) of the same type (i.e.: ( matches ), { matches }, and [ matches ]). An opening brace must appear before (to the left of) its matching closing brace (e.g.: ]{}[ is not balanced).
•	No unmatched braces lie between some pair of matched braces. For example, ({[]}) is balanced, but {[}] and [{)] are not balanced.
 
Complete the braces function in your editor. It should take an array of strings named values as a parameter, determine if all its braces are balanced, and then return an array of strings where each element indicates whether or not the element in the corresponding index of values was balanced. If the string in values[i] (where 0 ≤ i ≤ |values| - 1) has balanced braces, then index i in the return array should contain the string YES; otherwise, index i in the return array should contain the string NO.
 
Input Format
Input from stdin is handled by the locked stub code in your editor. The first line contains N, the length of values. Each line i of the N subsequent lines describes values[i].
 
Constraints
•	1 ≤ |values| ≤ 15
•	1 ≤ |values[i]| ≤ 100, where 0 ≤ i ≤ |values|
 
Output Format
Printing the contents of your returned array to stdout is handled by the locked stub code in your editor. Each line i of the N lines of output denotes whether or not the string in values[i] was balanced.
 
Sample Input
2
{}[]()
{[}]}
 
 
Sample Output
YES
NO
 
 
Explanation
values[0]: {}[]() meets the criterion for a balanced string, so index 0 in our return array should contain the string YES.
values[1]: {[}] contains unmatched braces between a matched pair (in the substrings [}, {[}, and [}]), so index 1 in our return array should contain the string NO.
*/
 Solution: 


#include<stdio.h>
#include<conio.h>
#define max 50

void main()
{
	char stk[max],exp[100];
	int top,i;
    top = -1;
	printf("\nEnter an infix expression ");
	gets(exp);
	for(i=0; exp[i] != '\0'; i++)
	{
		if( exp[i]=='(' || exp[i] =='[' || exp[i] == '{' )
		{
			top++;
			stk[top]= exp[i];
		}
		else if ( exp[i] == ')' )
		{
			if( stk[top] == '(' )
			top--;

		else
		{
			printf("Unbalanced exp");
			break;
		}
		}
		else if ( exp[i] == ']' )
		{
		if( stk[top] == '[' )
			top--;
		else
		{
			printf("Unbalanced exp");
			break;
		}
		}
		else if ( exp[i] == '}' )
		{
		if( stk[top] == '{' )
			top--;
		else
		{
			printf("Unbalanced exp");
			break;

		}
		}
	} 
	if( top == -1 )
		printf("Exp is balanced");
	else
		printf("Exp is not balanced");
} 

/*
3)	Emma and Squares
Emma is given two integers A and B and is asked to count the number of square integers in the interval [A-B] (inclusive of both extreme points).
A square integer is an integer which is the square of any integer. For example, 1, 4, 9 and 16 are some of the square integers as they are respectively the squares of 1, 2, 3 and 4.
Complete the getMinimumUniqueSum function in your editor. It has 1 parameter: an array of n strings, arr. Parse each element in arr using space as a delimiter to retrieve the values of A and B for each test case. arr[i] contains A and B values for the ith test case. Return an array where ith element in the array is the result for ith test case.
 
Input Format
First line contains T, the number of test cases. T test cases follow, each on a separate line.
Each test case consists of two space-separated integers A and B.
The handling of the above Input is done by the locked code stub in the Editor. 
 
Constraints
1 ≤ T ≤ 100
1 ≤ A ≤ B ≤ 109
 
Output Format
Return an array where ith element in the array is the result for ith test case
 
Sample Input 1
2
3 9
17 24
 
Sample output 1
2
0
 
Explanation 1
In the first test case, 4 and 9 are the square numbers.
In the second test case, none of the integers 17, 18, 19, 20, 21, 22, 23 and 24 are square numbers.
*/
#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
       scanf("%d %d",&a,&b);
       int i,count=0;
       for(i=a;i<=b;i++)
       {
           if((int)sqrt(i)*(int)sqrt(i) == i)
           {
             count++;
             i=i+(2*(int)sqrt(i));        // to avoid terminatio due to time out :-) -> no need to check all i values
           }

       }
       printf("%d\n",count);
    }
    return 0;
}


