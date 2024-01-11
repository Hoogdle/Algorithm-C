// 백준-11723-집합

// 알고리즘 :
// 특별한 알고리즘은 없음
// 사용자의 입력을 strcmp 로 확인 후 각 case 마다 알맞은 명령 실행.

// tip:
// 문자열을 받을 때 일반적으로 배열의 형태로 받기
// char str[20] (O)
// char* str
// if문 대신 case 문으로 정리하는 것이 더 깔끔해보임

#include <stdio.h>
#include <string.h>


int main()
{
    int array[20]={0};
    int num;

    scanf("%d",&num);
    

    for(int i=0;i<num;++i)
    {
        char str[7];
        int temp;
        int real;
        scanf("%s%d",str,&temp);
        real = temp - 1;

        // add 
        if(strcmp(str,"add")==0)
        {
            if(array[real]==1)
            {
                continue;
            }
            else
            {
                array[real] = 1;
            }
        }

        // remove
        if(strcmp(str,"remove")==0)
        {
            if(array[real]==0)
            {
                continue;
            }
            else
            {
                array[real]=0;
            }
        }
        // check
        if(strcmp(str,"check")==0)
        {
            if(array[real]==1)
            printf("1\n");
            else
            printf("0\n");
        }
        //toggle
        if(strcmp(str,"toggle")==0)
        {
            if(array[real]==0)
            {
                array[real] = 1;
            }
            else
            {
                array[real]=0;
            }
        }
        //all
        if(strcmp(str,"all")==0)
        {
            for(int i=0;i<20;++i)
            {
                array[i] = 1;
            }
        }
        //emtpy
        if(strcmp(str,"empty")==0)
        {
            for(int i=0;i<20;++i)
            {
                array[i] = 0;
            }
        }

    }
}