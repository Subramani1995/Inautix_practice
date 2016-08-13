# Inautix_practice
This repository contains Inautix_practice problems ( most of them are solved in C)

/*iNautix Test – 7
1)	Recursion 

Using Recursion reverse the string such as
Eg 1: Input: one two three
      Output: three two one
Eg 2: Input: I love india
      Output: india love I 
      */
Solution:
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char str[100];
    scanf("%[^\n]",str);
    int len=strlen(str),i,j,noofwords=0;
    char **ans;
    for(i=0;i<len;i++)
    {
        if(str[i]==' ')
            noofwords++;                            //to count no of words and use it for memory allocation
    }
    noofwords=noofwords+1;
    char *token;
    ans=(char **)malloc(noofwords*sizeof(char *));
    token=strtok(str," ");
    i=0;
    while(token!=NULL)
    {
        ans[i]=(char *)malloc(100 * sizeof(char));   // strtok function breaks the sentence into words by using space as delimiter
        strcpy(ans[i],token);
        token=strtok(NULL," ");
        i++;
    }
    for(j=i-1;j>=0;j--)
    {
        printf("%s ",ans[j]);                       //printing the stored words array in reverse
    }
        return 0;
}

/*
2)	Merging two arrays without repetition 

Given two sorted arrays, merge them such that the elements are not repeated
Eg 1: Input: get the no of elements from user(array 1 & array2)
        Array 1: 2 4 5 6 7 9 10 13
        Array 2: 2 3 4 5 6 7 8 9 11 15
       Output:
       Merged array: 2 3 4 5 6 7 8 9 10 11 13 15 
*/
Solution:

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,m,*arr1,*arr2,*merged;
    scanf("%d %d",&n,&m);
    arr1=(int *)malloc(n*sizeof(int));
    arr2=(int *)malloc(m*sizeof(int));
    merged=(int *)malloc((m+n)*sizeof(int));
    int i,j,k=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
        merged[k]=arr1[i];          //store elements of arr1 in merged array also
        k++;
    }
    for(j=0;j<n;j++)
    {
        scanf("%d",&arr2[j]);
        merged[k]=arr2[j];         //store elements of arr2 also in merged
        k++;
    }
    int temp;
    for(i=0;i<k;i++)
    {
        for(j=i+1;j<k;j++)
        {
            if(merged[i]>merged[j])
            {
                temp=merged[i];
                merged[i]=merged[j];        //sorting of merged array with repetitions
                merged[j]=temp;
            }
        }
    }
    for(i=0;i<k;)
    {
        if(merged[i]==merged[i+1])      //if repetition occur make 2nd element 0
        {
            merged[i+1]=0;
            i=i+2;
        }
        else
        {
            i=i+1;
        }
    }
    for(i=0;i<k;i++)
    {
        if(merged[i]!=0)
        {
            printf("%d ",merged[i]);    //print unique elements that are non zero elements
        }
    }

}


/*3)	Alternate String 

Alternate sorting: Given an array of integers, rearrange the array in such a way that the first element is first maximum and second element is first minimum.
    Eg.) Input  : {1, 2, 3, 4, 5, 6, 7}
         Output : {7, 1, 6, 2, 5, 3, 4}
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,*arr,j,temp;
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];        //sorting so that max will be in index 0 min will be in index n-1
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(i=0,j=n-1;i<=j;i++,j--)
    {
        if(i==j)                                        
            printf("%d ",arr[i]);
        else
            printf("%d %d ",arr[i],arr[j]);     //print max min alternatively
    }
    return 0;
}



