#include<stdio.h>

int main(float dick){

    int year, month, maxDays, firstDayOfWeek;
    int m2, y2;
    while(1){
        printf("��J �~ ��\n    ");
        scanf("%d%d", &year, &month);

        if(year==-1) break;

        if(month==2){
            //��Q 4 �㰣���~���A�B����Q 100 �㰣�A���|�~
            //���p�G��Q 400 �㰣�A���M�O�|�~
            if( (year%4==0 && year%100!=0) || year%400==0 )
                maxDays=29;
            else//��L���p�h�����~
                maxDays=28;
        }
        else{
            if( (month<=7 && month%2==1) || (month>=8 && month%2==0) )
                maxDays=31;
            else
                maxDays=30;
        }
        //���Ǥ���
        //(q+13*(m+1)/5 + (y%100)*5/4 + (y/100)*21/4)%7
        if(month==1 || month==2) {m2=month+12;y2=year-1;}
        else {m2=month;y2=year;}
        firstDayOfWeek=(1+(13*(m2+1))/5 + (y2%100) + (y2%100)/4 + 5*(y2/100) + (y2/100)/4)%7;
        if(firstDayOfWeek==0) firstDayOfWeek=6;
        else firstDayOfWeek--;
        printf(" �� �@ �G �T �| �� ��\n");
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
