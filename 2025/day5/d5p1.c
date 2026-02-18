# include <stdio.h>
# include <stdlib.h>

int peek(FILE *fp){
    char ans = fgetc(fp);
    ungetc(ans,fp);
    return ans;
}

int is_fresh(long long ingrd, long long lower[], long long upper[], int boundcnt){
    for(int i=0;i<boundcnt;i++){
        if(ingrd>=lower[i] && ingrd<=upper[i]) return 1;
    }
    return 0;
}

int main(){
    FILE *fp = fopen("d5smp.in","r");
    long long lower[256], upper[256], ingrd;
    int boundcnt=0, ingrdcnt=0, c;
    while(1){
        fscanf(fp,"%lld-%lld",&lower[boundcnt],&upper[boundcnt]);
        boundcnt++;
        fgetc(fp);
        if(peek(fp)=='\n'){
            break;
        }
    }
    while(1){
        if(fscanf(fp,"%lld",&ingrd)==EOF) break;
        if(is_fresh(ingrd,lower,upper,boundcnt)){
            ingrdcnt++;
        }
    }
    printf("%d",ingrdcnt);
    fclose(fp);
    return 0;
}