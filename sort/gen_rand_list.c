#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
    FILE *fp;
    int num_count;
    int cur_num;
    fp = fopen("num_list.txt","w");
    if (argc == 1){
        num_count = 100;
    }
    else {
        num_count =  atoi(argv[1]);
    }
    
    while (num_count>0) {
        fprintf(fp,"%d\n",rand());
        num_count--;
    }
    fclose(fp);

}
