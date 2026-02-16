# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>
// abcabc = 1001*abc
// a number n with 2k digits is an invalid ID if: 
// (10 ^ k + 1) divides n

int get_digit(long long x){
    int digit = 0;
    while(x!=0){
        digit++;
        x /= 10;
    }
    return digit;
}
long long get_factor(int digit){
    long long res = 1;
    while(digit--){
        res *= 10;
    }
    res++;
    return res;
}
bool invalid_id(long long id){
    int digit = get_digit(id);
    if(digit%2!=0) return false;
    long long factor = get_factor(digit/2);
    if (id%factor==0) return true;
    return false;
}

int main(){
    long long upper,lower;
    long long ans=0;
    FILE *fp = fopen("day2.in","r");
    while(fscanf(fp,"%lld%lld",&lower,&upper)==2){
        upper = -upper;
        for(long long i=lower;i<=upper;i++){
            if(invalid_id(i)){
                ans += i;
            }
        }
        fgetc(fp);
    }
    printf("%lld",ans);
    fclose(fp);
    return 0;
}