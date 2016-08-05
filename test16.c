# Inautix_practice
This repository contains Inautix_practice problems ( most of them are solved in C)


//factorial

ques :  find the factorial of the given number 'n'

Solution: (using recursion)


int main()
{
  int n;
  scanf("%d",&n);
  int ans=factorial(n);
  printf("%d",ans);
  return 0;
}
int factorial(int n)
{
  int fact=1;
  if(n==1)
  {
    return 1;
  }
  else
  {
    fact=n*factorial(n-1);
    return fact;
  }
}

ques: find sum of elements in the given array

solution:
int main() {
    int *arr,i,size;
    scanf("%d",&size);
    arr=(int *)malloc(size * sizeof(int));
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    int ans=sum(size,arr);
    printf("%d",ans);
}

int sum(int size, int *arr)
{
  int sum=0,i;
  for(i=0;i<size;i++)
  {
      sum=sum+arr[i];
  }
  return sum;
}
