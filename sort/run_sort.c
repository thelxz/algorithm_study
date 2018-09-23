#include <stdio.h>
#include <stdlib.h>
#include "methods.h"
#include <string.h>
#include <time.h>

void do_sort(int method_id, int * nums, int size) __attribute__((noinline));

void (* sort_func[]) (int*, int) = {
    insertion_sort,
};

void do_sort(int method_id, int * nums, int size)
{
    clock_t t1, t2;
    t1 = clock();
    sort_func[method_id](nums, size);
    t2 = clock();
    printf("sort used time: %d ms\n", (t2-t1)*1000/CLOCKS_PER_SEC);
}

/*
    argv[1]: count of numbers to sort
    argv[2]: sort method id
*/
void main(int argc, char * argv[])
{
    int size;
    int method_id;
    int count;
    int * data, *ptr;
    FILE * fp;
    char tmp_str[100];

    if (argc != 3) {
        printf("Need two arguments, you supply %d \n", argc-1);
        exit(1);
    }
    size = atoi(argv[1]);
    method_id = atoi(argv[2]);

    //printf("Reading the data...\n");
    fp = fopen("num_list.txt","r");
    if (!fp){
        printf("Can't find the data file!\n");
        exit(1);
    }
    
    // read data
    data = malloc(sizeof(int)*size);
    ptr = data;
    count = size;
    while((!feof(fp)) && (count!=0)){
        fscanf(fp,"%s",tmp_str);
        //printf("read a num: %s\n", tmp_str);
        * ptr = atoi(tmp_str);
        ptr ++;
        count --;
    }
    fclose(fp);

    //printf("Starting sort...\n");
    do_sort(method_id, data, size);

    //printf("Write result out...\n");
    char out_fn[100] = "result_";
    strcat(out_fn,argv[2]);
    strcat(out_fn,".txt");
    FILE *ofp = fopen(out_fn,"w");
    ptr = data;
    count = size;
    while(count != 0){
        fprintf(ofp,"%d\n",*ptr);
        count --;
        ptr++;
    }
    fclose(ofp);
    
    //printf("Finsh the job!\n");
    free(data);
}
