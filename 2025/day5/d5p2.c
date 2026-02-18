# include <stdio.h>
# include <stdlib.h>
# include <math.h>
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))


int peek(FILE *fp){
    char ans = fgetc(fp);
    ungetc(ans,fp);
    return ans;
}

int intersect(long long a, long long b, long long c, long long d){
    // 2 ranges[a,b] and [c,d]
    return (a>=c && a<=d) || (b>=c && b<=d) || (c>=a && c<=b) || (d>=a && d<=b);
}

int combine(long long lower[], long long upper[], int boundcnt){
    for(int i=0;i<boundcnt-1;i++){
        for(int j=i+1;j<boundcnt;j++){
            if(lower[i]!=0 && lower[j]!=0 && intersect(lower[i],upper[i],lower[j],upper[j])){
                lower[i] = MIN(lower[i],lower[j]);
                upper[i] = MAX(upper[i],upper[j]);
                lower[j] = 0;
                upper[j] = 0;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    FILE *fp = fopen("d5.in","r");
    long long lower[256], upper[256], ingrdcnt=0;
    int boundcnt=0;
    while(1){
        fscanf(fp,"%lld-%lld",&lower[boundcnt],&upper[boundcnt]);
        boundcnt++;
        fgetc(fp);
        if(peek(fp)=='\n'){
            break;
        }
    }
    while (combine(lower,upper,boundcnt));
    for(int i=0;i<boundcnt;i++){
        if(lower[i]!=0){
            ingrdcnt += upper[i]-lower[i]+1;
        }
    }
    printf("%lld",ingrdcnt);
    fclose(fp);
    return 0;
}