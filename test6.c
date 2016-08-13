# Inautix_practice
This repository contains Inautix_practice problems ( most of them are solved in C)
/*iNautix Test -6 
1)	Number Compliment 
The complement of a number is defined here as the number's bitwise inversion from the highest-order 1-bit through the lowest-order bit. For example, the number n = 5 is represented as 00000101 in binary. The binary complement of n is 010, which is 2 in decimal notation.
 
Complete the getIntegerComplement function in your editor. It has has 1 parameter: a base-10 integer, n. This function must return the complement of n as a base-10 integer.
 
Input Format
The locked stub code in your editor reads a single integer, n from stdin and passes it to your function.
 
Constraints
0 ≤ n ≤ 105
 
Output Format
Return an integer denoting the complement of n.
 
Sample Input 1
50
 
Sample Output 1
13
 
Sample Input 2
100
 
Sample Output 2
27
 
Explanation
 
Sample Case 1:
(50)10 converts to (110010)2. When we invert each bit in the sequence we get (001101)2, which equals (13)10. Thus, we return 13.
 
Sample Case 2:
(100)10 converts to (1100100)2. When we invert each bit in the sequence we get (0011011)2, which equals (27)10. Thus, we return 27.
*/
Solution:

#include<stdio.h>
#include<string.h>
int getComplement(int);
int main()
{
    int n;
    scanf("%d",&n);
    int res=getComplement(n);
    printf("%d",res);
    return 0;
}

int getComplement(int n)
{
    int i,arr[100],j,k=0,ans=0;
    int val=n;
    while(n!=0)                         //conversion of decimal to binary
    {
        arr[k]=n%2;
        n=n/2;
        k++;
    }
    for(i=0;i<k;i++)
    {
        if(arr[i]==0)
        {                                   //complementing
            arr[i]=1;
        }
        else
        {
            arr[i]=0;
        }
        ans=ans+(arr[i]*pow(2,i));      //convertion of binary to decimal
    }
    return ans;
}

/*
2)	4th Bit 
Complete the fourthBit function in your editor. It has 1 parameter: an integer, num. It must return the binary integer (i.e.: 0 or 1) corresponding to the 4th least-significant bit of the 32-bit value passed to it as an argument.
 
Input Format
The locked stub code in your editor reads a single integer, num, from stdin and passes it to your function.
 
Constraints
•	num is a 32-bit integer.
 
Output Format
Your function must return the binary integer corresponding to the 4th least-significant bit of the integer argument passed as num. This is printed to stdout by the locked stub code in your editor.
 
Sample Input 0
32
 
Sample Output 0
0
 
Sample Input 1
77
 
Sample Output 1
1
 
Explanation
Sample Case 0:
The integer (32)10 converts to (100000)2. If we 1-index each bit from least to most significant, they are indexed as 654321. Because the bit at index 4 is 0, we return 0 as our answer.
 
Sample Case 1:
The integer (77)10 converts to (1001101)2. If we 1-index each bit from least to most significant, they are indexed as 7654321. Because the bit at index 4 is 1, we return 1 as our answer.
*/
Solution:

#include<stdio.h>
#include<string.h>
int getBit4(int);
int main()
{
    int n;
    scanf("%d",&n);
    int res=getBit4(n);
    printf("%d",res);
    return 0;
}

int getBit4(int n)
{
    int i,arr[100],j,k=0,ans=0;
    int val=n;
    while(n!=0)                         //conversion of decimal to binary
    {
        i=n%2;
        k++;
        if(k==4)                            //return 4th bit
            return i;
        n=n/2;
    }
}

/*3)	Lonely Integer 

Complete the function lonelyInteger that has one parameter- an array numbers, of n integers. In the array, all the elements except one, occur more than one times. The function should return the integer, which occurs only one time.
 
Input Format
The first line of the input is an integer, n, total number of elements in array numbers. Each of the next n lines, contains single integer.
 
Constraints
•	1 ≤ n ≤ 100
•	n is odd.
•	0 ≤ Ai ≤ 100, 0 ≤ i < n
 
Output Format
Your function should return the integer, which occurs only once in the array.
 
Sample Input 1
1
1
 
Sample Output 1
1
 
Sample Input 2
3
1 
1 
2
 
Sample Output 2
2
 
Explanation
Sample Case 1
The array contains only one element 1, so the function returns 1.
 
Sample Case 2
The array is {1, 1, 2} and 2 is the element which occurs only one time, so the function returns 2.
*/
Solution:

#include<stdio.h>
#include<stdlib.h>
int unique(int, int*);
int main()
{
    int n,*arr,res,i;
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    res=unique(n,arr);
    printf("%d",res);
}

int unique(int n,int *arr)
{
    int i,j,flag=0;
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=i+1;j<n;j++)
        {
            if(arr[i] == arr[j])            //if repetition occurs make those as 0
            {
                flag=1;
                arr[j]=0;
                break;
            }
        }
        if(flag==1)                 // if a copy of a number is present in preceding array make that as 0
            arr[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]!=0)               //only one non zero element will be present
            return arr[i];
    }

}


