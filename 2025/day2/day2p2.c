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
long long pow_10(int power){
    long long ret=1;
    while(power--){
        ret*=10;
    }
    return ret;
}
bool repeated(long long id, int base){
    long long base_ = pow_10(base);
    long long cell = id%base_;
    while (id>0){
        if(id%base_!=cell) return false;
        id /= base_;
    }
    return true;
}
bool invalid_id(long long id){
    int digit = get_digit(id);
    for(int base=1; base<=digit/2; base++){
        if (digit%base!=0) continue;
        if(repeated(id,base)) return true;
    }
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