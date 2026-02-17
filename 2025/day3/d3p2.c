#include <stdio.h>
#include <stdlib.h>

struct max_res {
    int value;
    int index;
};
struct max_res find_max(int arr[], int start, int end){
    struct max_res res;
    res.index = start;
    res.value = arr[start];
    for(int i=start;i<end;i++){
        if(arr[i]>res.value){
            res.index = i;
            res.value = arr[i];
        }
    }
    return res;
}

int main(){
    FILE *fp = fopen("d3.in","r");
    long long joltage = 0;
    int linecnt, flag = 1;
    int line[1024];
    while(flag){
        linecnt = 0;
        while(1){
            int c = fgetc(fp);
            if(c>='0' && c<='9') {
                line[linecnt] = c-'0';
                linecnt++;             
            }
            else{
                struct max_res max_digit;
                max_digit.index = -1;
                long long bank = 0;
                for (int i=0;i<12;i++){
                    max_digit = find_max(line,max_digit.index+1,linecnt-11+i);
                    bank += max_digit.value;
                    bank *= 10;
                }
                bank/=10;
                joltage += bank;
                if(c==EOF) flag = 0;
                break;
            }
        }
    }
    printf("%lld",joltage);
    fclose(fp);
    return 0;
}