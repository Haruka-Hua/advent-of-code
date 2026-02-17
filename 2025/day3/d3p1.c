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
    for(int i=start+1;i<end;i++){
        if(arr[i]>res.value){
            res.index = i;
            res.value = arr[i];
        }
    }
    return res;
}
int main(){
    FILE *fp = fopen("d3.in","r");
    int joltage = 0, linecnt, flag = 1;
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
                int bank = 0;
                struct max_res fst = find_max(line,0,linecnt);
                if(fst.index==linecnt-1){
                    bank += fst.value;
                    struct max_res snd = find_max(line,0,linecnt-1);
                    bank += snd.value*10;
                }
                else{
                    bank += fst.value*10;
                    struct max_res snd = find_max(line,fst.index+1,linecnt);
                    bank += snd.value;
                }
                joltage += bank;
                if(c==EOF) flag = 0;
                break;
            }
        }
    }
    printf("%d",joltage);
    fclose(fp);
    return 0;
}