#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
int ah(int m)
{
    wchar_t cstrs[10];
    cstrs[0]=0x96F6;/*Áã*/cstrs[1]=0x58F9;/*Ò¼*/cstrs[2]=0x8D30;/*·¡*/cstrs[3]=0x53C4;/*Èþ*/cstrs[4]=0x8086;/*ËÁ*/
    cstrs[5]=0x4F0D;/*Îé*/cstrs[6]=0x9678;/*Â½*/cstrs[7]=0x67D2;/*Æâ*/cstrs[8]=0x634C;/*°Æ*/cstrs[9]=0x7396;/*¾Á*/
    setlocale(LC_ALL, "");
    return cstrs[m];
}
int gewi(int a)
{
    int ge=a%10;/*qian=a/1000%10,bai=a/100%10,shi=a/10%10,*/
    wchar_t he=ah(ge);/*hian=ah(qian),hai=ah(bai),chi=ah(shi),*/
    setlocale(LC_ALL, "");
    return he;
}
wchar_t bit[10];
char digits[15];
int main(long long a)
{
    bit[1]=0x4EDF;/*Çª*/bit[2]=0x4F70;/*°Û*/bit[3]=0x62FE;/*Ê°*/bit[4]=0x842C;/*Èf*/bit[5]=0x5104;/*ƒ|*/
    setlocale(LC_ALL, "");
    long long nn=100000000000,mm=0,cn=10000000,cm=0,cmt=0,cnt=1000;
    printf("please write a number which <100000000000>: \n");
    scanf("%lld",&a);
    printf("Number: %lld \n", a);
    long long b=a;
    int digitCount=0;
    long long reminder=1;
    memset(digits, '0', sizeof(digits));
    for (int i=0; i<sizeof(digits); i++)
    {
        unsigned char num=b/reminder%10;
        digits[i]=num;
        reminder*=10;
        if (reminder >b) {
            digitCount=i;
            break;
        }
    }
    if(a>=1000000000000)
    {
        printf("you have written a wrong number");
    }
    else {
        if(a-100000000>=0)
        {
            while(nn>99999999)
            {
                mm++;
                long long b=a/nn%10;
                wchar_t x=gewi(b);

                if(mm==1&& a-100000000000>=0 && b!=0) printf("%lc%lc",x,bit[mm]);
                if(mm==2&& a-10000000000>=0 && b!=0 ) printf("%lc%lc",x,bit[mm]);
                if(mm==3&& a-1000000000>=0 && b!=0) printf("%lc%lc",x,bit[mm]);
                if(mm==4&& a-100000000>=0 && b!=0) printf("%lc",x);
                if (mm==1 && b==0 && a>=1000000000000 && digits[10]!=0) printf("%lc",gewi(0));
                if (mm==2 && b==0 && ( (a>=10000000000 && (digits[11]!=0 && digits[9]!=0)) || (a>=100000000000 && digits[11]==0 && digits[9]!=0))  ) printf("%lc",gewi(0));
                if (mm==3 && b==0 && ( (a>=1000000000 &&(digits[10]!=0 && digits[8]!=0)) || (a>=10000000000 && digits[10]==0 && digits[8]!=0)) ) printf("%lc",gewi(0));
                nn/=10;
            }
            printf("%lc",bit[5]);
        }
        if(a-10000>=0) {
            while(cn>9999)
            {
                cm++;
                long b=a/cn%10;
                wchar_t x=gewi(b);
                if(cm==1 && a-10000000>=0&&b!=0) printf("%lc%lc",x,bit[cm]);
                if(cm==2 && a-1000000>=0&&b!=0) printf("%lc%lc",x,bit[cm]);
                if(cm==3 && a-100000>=0&&b!=0) printf("%lc%lc",x,bit[cm]);
                if(cm==4&&b!=0) printf("%lc",x);
                if (cm==1 && b==0 && a>=100000000 && digits[6]!=0) printf("%lc",gewi(0));
                if (cm==2 && b==0 && ( (a>=1000000 && (digits[7]!=0 && digits[5]!=0)) || (a>=10000000 && digits[7]==0 && digits[5]!=0))  ) printf("%lc",gewi(0));
                if (cm==3 && b==0 && ( (a>=100000 &&(digits[6]!=0 && digits[4]!=0)) || (a>=1000000 && digits[6]==0 && digits[4]!=0)) ) printf("%lc",gewi(0));
                cn/=10;
            }
            if (digits[8]!=0 && (digits[7]==0 && digits[6]==0 && digits[5]==0 && digits[4]==0) &&  digits[3]!=0) printf("%lc",gewi(0));
            if ( (a>=100000000 && (digits[7]!=0 || digits[6]!=0 || digits[5]!=0 || digits[4]!=0)) || (a>=10000 && a<100000000) )
                printf("%lc",bit[4]);
        }
        while(cnt>0)
        { 
            cmt++;
            long b=a/cnt%10;
            wchar_t x=gewi(b);
            if(cmt==1&& a-1000>=0 && b!=0) printf("%lc%lc",x,bit[cmt]);
            if(cmt==2&& a-100>=0 && b!=0) printf("%lc%lc",x,bit[cmt]);
            if(cmt==3&& a-10>=0 && b!=0) printf("%lc%lc",x,bit[cmt]);
            if(cmt==4 && b!=0) printf("%lc",x);
            if (cmt==1 && b==0 && a>=10000 && digits[2]!=0) printf("%lc",gewi(0));
            if (cmt==2 && b==0 && ( (a>=100 && (digits[3]!=0 && digits[1]!=0)) || (a>=1000 && digits[3]==0 && digits[1]!=0))  ) printf("%lc",gewi(0));
            if (cmt==3 && b==0 && ( (a>=10 &&(digits[2]!=0 && digits[0]!=0)) || (a>=100 && digits[2]==0 && digits[0]!=0)) ) printf("%lc",gewi(0));
            cnt/=10;
        }
    }
    if (a==0) printf("%lc",gewi(0));
    printf("\n");
    return 0;
}

