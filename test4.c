# Inautix_practice
This repository contains Inautix_practice problems ( most of them are solved in C)

/*iNautix Test -4 

1)	Merge Strings
Complete the mergeStrings function in your editor. It has 2 parameters:
1.	A string, a.
2.	A string, b.
 
Your function must merge strings a and b, and then return a single merged string. A merge operation on two strings is described as follows:
•	Append alternating characters from a and b, respectively, to some new string, mergedString.
•	Once all of the characters in one of the strings have been merged, append the remaining characters in the other string to mergedString.
 
Input Format
The locked stub code in your editor reads two strings, a and b, from stdin and passes them to your function.
 
Constraints
•	1 ≤ |a|, |b| ≤ 25000
 
Output Format
Your function must return the merged string. This will be printed to stdout by the locked stub code in your editor.
 
Sample Input 0
abc
def
 
Sample Output 0
adbecf
 
Sample Input 1
ab
zsd
 
Sample Output 1
Azbsd
*/
Solution :
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//merging strings
char *merge(char *,char *);
int main()
{
    char a[1000],b[1000];
    scanf("%s",a);
    scanf("%s",b);
    char *ans;
    ans=merge(a,b);
    printf("%s",ans);
    return 0;
}

char *merge(char *str1,char *str2)
{
    char *merged;
    int len1=strlen(str1);
    int len2=strlen(str2);
    int merged_len=len1+len2+1;
    merged=(char *)malloc(merged_len * (sizeof(char)));
    int ref=(len1>=len2)?len2:len1;                 //find smaller string length and keep it as ref
    int mid=ref*2;
    int i,j,k=0;
    for(i=0;i<mid;i=i+2)                            //till the end of smaller string
    {
        merged[i]=str1[k];
        merged[i+1]=str2[k];                        //storing alternate characters in merged string
        k++;
    }
    for(i=ref;i<len1;i++)                           // to store the remaining characters present in str1 or str 2
    {
        merged[mid]=str1[i];
        mid++;
    }
    for(i=ref;i<len2;i++)
    {
        merged[mid]=str2[i];
        mid++;
    }
    merged[mid]='\0';                               //append null to indicate the end of string
    
    return merged;
}

/*Count Duplicate 
Write a program to find the total number of duplicate elements in an array of size N. Your task is to count the number of elements which occur two or more times.
 

Input Format
The locked stub code in your editor reads the following input from stdin and passes it to your function:
First line contains the value of N, the number of elements in the array. Next N subsequent lines contains the elements of the array.
 
Constraints
•	1 ≤ N ≤ 1000
•	1 ≤ numbersi ≤ 1000
 
Output Format
Return an integer which denotes the required result.
 
Sample Input 1
8
1
3
1
4
5
6
3
2
 
Sample Output 1
2
 
Sample Input 2
5
1
1
2
2
3
 
Sample Output 2
2
 
Explanation
Sample Case 1:
N = 8
numbers  = {1, 3, 1, 4, 5, 6, 3, 2}.
The count of duplicate elements in the array is 2, as 1 and 3 both occur more than once.
Sample Case 2:
N = 5
numbers = {1, 1, 2, 2, 3}
The count of duplicate elements in the array is 2 as 1 and 2 both occur more than once.
 */
 Solution:

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//counting duplicate numbers
int count_dup(int, int *);
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
    int result=count_dup(n,arr);
    printf("%d",result);
    return 0;
}

int count_dup(int n, int *arr)
{
    int count=0,i,j;
    for(i=0;i<n;i++)
    {
       
        for(j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j] && arr[i]!=0)             
            {
                arr[j]=0;                           //if 2 elements are equal increment count by 1 and make those 							elements 0.
                                                    //so that if the same element is repeated multiple times need 							not increment the count again and again using the 							condition arr[i]!=0 in if statement
                arr[i]=0;
                count++;
            }
        }
                  
    }
    return count;
}

/*

2)	Word Reverse 

Create an application program in java to reverse the words in a given sentence.
EX:
Input: Rmk College of Engineering and Technology
Output: kmr egelloc fo gnireenigne dna ygolonhcet
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//reverse the words
char* reverse(char *);
int main()
{
    char str[1000];
    scanf("%[^\n]",str);
    char *result=reverse(str);
    printf("%s",result);
    return 0;
}
char *reverse(char *str)
{
    char *res;
    int len=strlen(str),start,end,i,j=0,k=0,x,count=0;
    res=(char *)malloc(len*sizeof(char));
    for(i=0;i<len;)
    {
        start=i;                            //start indicate start of a word
        for(j=start;j<len;j++)
        {
            count++;
            if(str[j]==' ')                 //if space encountered keep that index=end
            {
                end=j-1;
                break;
            }
        }
        if(j==len)                      //exception case (last word of sentence)
            end=len-1;

        i=i+count;                  //increment i by length of the word

        for(x=end;x>=start;x--)   //reverse the word by storing from end to start
        {
            res[k]=str[x];
            k++;
        }
        res[k]=' ';
        k++;
        count=0;
    }
    res[k]='\0';            //append null at the end of string
    return res;
}





