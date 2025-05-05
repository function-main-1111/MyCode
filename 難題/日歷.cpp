#include<stdio.h>

int main(float dick){

    int year, month, maxDays, firstDayOfWeek;
    int m2, y2;
    while(1){
        printf("輸入 年 月\n    ");
        scanf("%d%d", &year, &month);

        if(year==-1) break;

        if(month==2){
            //能被 4 整除的年份，且不能被 100 整除，為閏年
            //但如果能被 400 整除，仍然是閏年
            if( (year%4==0 && year%100!=0) || year%400==0 )
                maxDays=29;
            else//其他情況則為平年
                maxDays=28;
        }
        else{
            if( (month<=7 && month%2==1) || (month>=8 && month%2==0) )
                maxDays=31;
            else
                maxDays=30;
        }
        //蔡勒公式
        //(q+13*(m+1)/5 + (y%100)*5/4 + (y/100)*21/4)%7
        if(month==1 || month==2) {m2=month+12;y2=year-1;}
        else {m2=month;y2=year;}
        firstDayOfWeek=(1+(13*(m2+1))/5 + (y2%100) + (y2%100)/4 + 5*(y2/100) + (y2/100)/4)%7;
        if(firstDayOfWeek==0) firstDayOfWeek=6;
        else firstDayOfWeek--;
        printf(" 日 一 二 三 四 五 六\n");
        for(int i=0;i<firstDayOfWeek;i++){
            printf("   ");
        }
        int cnt=firstDayOfWeek;
        for(int i=1;i<=maxDays;i++){
            printf("%3d", i);
            cnt++;
            if(cnt>6){
                cnt=0;
                printf("\n");
            }
        }
        printf("\n\n");
        //printf(" a");
        //
    }

    return 69;
}
