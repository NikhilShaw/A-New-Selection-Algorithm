/*
Created by: Nikhil Shaw
Date of creation: 29 Sep 2016
Aim: To find the Kth smallest element in an unsorted array of numbers
*/

/*
arr: Unsorted array of numbers.
k: Kth smallest element in the array.
n: Total number of elements in the unsorted array.
Ns: Closest elememt smaller than Kth element encountered.
Nl: Closest element greater than Kth element encountered.
smallcount: Keeps count of elements smaller than arr[j].
largecount: Keeps count of elements larger than arr[j].
smalllimit: Number of possible elements smaller than Kth element.
largelimit: Number of possible elements greater than Kth element. 
*/

/*
Algorithm:

1. Start

2. Input the unsorted array (arr[]), its size (n) and value of k (Kth smallest element)

3. smalllimit=k-1
   largelimit-n-k
   Ns= -infinity (minimum value possible)
   Nl= +infinity (maximum value possible)

4.  Note: Keep count of smallcount, largecount, smalllimit, largelimit, Ns and Nl

  from i=0 till i<n:
   {
      smallcount=largecount=0
      j=i+1

      if i==n-1 then:
        print the element (this is the Kth element)

      if arr[j] doesn't lie between Ns and Nl, then:
      {
          if arr[j]<Ns then:
            decrement smalllimit by 1
          else:
            decrement largelimit by 1
          i++
          continue the loop 
      }

      from j=i+1 till j<n:
      {
          if arr[j] < arr[i] then:
            increment smallcount by 1
          else:
            increment largecount by 1

          if smallcount>smalllimit then:
            Decrement largelimit by 1
            Nl= arr[i]
            break out of the loop

          else if largecount > largelimit:
            Decrement smalllimt by 1
            Ns= arr[i]
            break out of the loop

        Increment j by 1
      }

      if smallcount is equal to smalllimit and largecount is equal to largelimit 
          print the element in the array (ie. print arr[i])
   }

5. End
*/

/*
Following is the code in C++
*/


#include<iostream>

using namespace std;

int main()
{ 

  int arr[20], smalllimit, largelimit, smallcount, largecount, Ns, Nl, k, n, i, j;
  cout<<"Enter the number of elements in the unsorted array"<<endl;
  cin>>n;
  cout<<"Enter the unsorted array"<<endl;
  for(i=0;i<n;i++)
    cin>>arr[i];
  cout<<"Enter the Kth smallest element in the array you want to find"<<endl;
  cin>>k;
  while((k<1)||(k>n))                        // condition for valid value of k
  {
    cout<<"Enter K between 1 and "<<n<<endl;
    cin>>k;
  }
  smalllimit=k-1;
  largelimit=n-k;
  Ns=-30000;                                 // very low value initially
  Nl=30000;                                  // very high value initially
  for(i=0;i<n;i++)
  {
    smallcount=0;
    largecount=0;
     j=i+1;

    if(i==n-1)                               // Only one element left in the array to process
    {
      cout<<"The element is "<<arr[i];
      break;
    }
    else if( (arr[i]>Nl)||(arr[i]<Ns) )      // if element doesn't lie between Ns and Nl
    {
      if(arr[i]<Ns)
       {
        smalllimit--;
       } 
      else
        largelimit--;
      continue;
    }

    else
    {
      for(j=i+1;j<n;j++)
      {
        if(arr[j]<arr[i])
          smallcount++;
        else
          largecount++;

        if(smallcount>smalllimit)
        {
          largelimit--;
          Nl=arr[i];
          break;
        }
        else if(largecount>largelimit)
        { 
          smalllimit--;
          Ns=arr[i];
          break;
        }
        else{}
      }
    }

    if( (smallcount==smalllimit)&&(largecount==largelimit) )     // It is the Kth elements with exactly k-1 elements smaller than it and n-k elements greter than it.
    { 
      cout<<"The element is "<<arr[i];
      break;
    }
  }

return 0;
}
