#include <stdio.h>

void insertion_sort(int * num_list, int  size)
{
    int i,j;
    int tmp;
    for(i=1; i < size; i++){
        j = i;
        while(j!=0 && num_list[j] < num_list[j-1]){
            tmp = num_list[j];
            num_list[j] = num_list[j-1];
            num_list[j-1] = tmp;
            j--;
        }
    }
    return; 
}
