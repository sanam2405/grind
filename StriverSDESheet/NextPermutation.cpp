
/*

1. Start traversing from the end
2. index1 is the first index from back where a[index1] < a[inex1+1]
3. index2 is the first index from back where a[index1] < a[index2]
4. swap a[index1] and a[index2]
5. reverse the array from [index1...n-1]

*/



#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
       int index1=-1,index2=-1;
       
       for(int i = n-2; i >= 0; i--)
       {
           if(permutation[i] < permutation[i+1])
           {
                index1 = i;
                break;
           }
       }
    
      for(int i = n-1; i >= 0; i--)
       {
           if(index1 != -1 && permutation[index1] < permutation[i])
           {
                index2 = i;
                break;
           }
       }
       
       if(index1!=-1 && index2 != -1)
       swap(permutation[index1],permutation[index2]);
    
       int low = index1+1;
       int high = n-1;
    
       while(low<high)
       {
           swap(permutation[low++],permutation[high--]);
       }
    
       return permutation;
}
