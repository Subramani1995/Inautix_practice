# Inautix_practice
This repository contains Inautix_practice problems ( most of them are solved in C)

/*Solution for Gemstones problem

question link: https://www.hackerrank.com/challenges/gem-stones?h_r=internal-search

solution:

//logic : whenever i encounter a letter in a string, i will increment its corresponding position in integer array, at the end if 'a' is present
         // in all 3 lines, it will be incremented thrice. so if incremented value == size then it is a gemstone!*/
int main()
{
   int size,i,j,flag=0,ans=0,k=0,arr[27]={0};
    scanf("%d",&size);
    char **str;
    str=(char **)malloc(size*sizeof(char *));
    for(i=0;i<size;i++)
    {
        str[i]=(char *)malloc(101*sizeof(char));
        scanf("%s",str[i]);
       
        for(j=0;str[i][j]!='\0';j++)
        {
            for(k=0;k<j;k++)                    // this for loop is used bcs if a letter is repeated within a line of string, we have to neglect it.
                                                 //   we need to increment only once for that letter.
            {
                if(str[i][j]==str[i][k])
                {
                    flag=1;
                    break;
                }
            }
            if(flag!=1)
            {
                arr[str[i][j] -'a']++;
            }
            flag=0;
            
        }
        
    }
    for(i=0;i<26;i++)
    {
        if(arr[i]==size)
        {
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}


//Solution for Modify Prices problem:

int verifyItems( int origItems_size, char **origItems, int origPrizes_size, float *origPrizes, int items_size, char *items, int prices_size, float *prices)
{
  int forgery=0,i,j;
  for(i=0;i<items_size;i++)
  {
    for(j=0;j<n;j++)
    {
      if((strcmp(items[i],origItems[j]==0) && (origprices[j] != prices[i]))
      {
        forgery++;
      }
    }
  }
  return forgery;
}
