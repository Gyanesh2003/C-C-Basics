#include <stdio.h>
void Merge(int * , int , int , int );
void MergeSort(int *array, int left, int right){
   int middle = (left+right)/2;
   if(left<right){
      
      MergeSort(array, left, middle);
	  MergeSort(array, middle + 1, right);
      Merge(array, left, middle, right);
   }
}
void Merge(int *array, int left, int middle, int right){
   int tmp[right - left + 1];
   int pos = 0, leftposition = left, rightposition = middle + 1;
   while (leftposition <= middle && rightposition <= right){
      if (array[leftposition] < array[rightposition]){
         tmp[pos++] = array[leftposition++];
      }
      else{
         tmp[pos++] = array[rightposition++];
      }
   }
   while (leftposition <= middle)
      tmp[pos++] = array[leftposition++];
   while (rightposition <= right)
      tmp[pos++] = array[rightposition++];
   int i;
   for (i = 0; i < pos; i++){
      array[i + left] = tmp[i];
   }
   return;
}
int main(){
   int size;
   printf("enter size of array:");
   scanf("%d", &size);
   int array[size];
   int i, j, k;
   printf("enter the elements in an array:");
   for (i = 0; i < size; i++){
      scanf("%d", &array[i]);
   }
   MergeSort(array, 0, size - 1);
   for (i = 0; i< size; i++){
      printf("%d ", array[i]);
   }
   printf(" ");
   return 0;
}
