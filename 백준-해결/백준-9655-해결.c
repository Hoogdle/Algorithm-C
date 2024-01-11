// 백준-9655-돌게임 (시간제한 1초, 메모리제한 128mb)

// 알고리즘:
// 주어진 돌의 갯수를 3으로 나눈 나머지에 따라 승패가 나뉨

// {마지막으로 낸 사람이 창영} 짝수
// if 나머지 2 : 창영 승리
// if 나머지 1 : 상근 승리
// if 나머지 0 : 창영 승리

// {마지막으로 낸 사람이 상근} 홀수
// if 나머지 2 : 상근 승리
// if 나머지 1 : 창영 승리
// if 나머지 0 : 상근 승리

// 주어진 돌 갯수를 3으로 나눔
// 몫의 홀짝에 따라 마지막으로 낸 사람 결정
// 각 case 마다의 경우를 위를 참고하여 결과 계산

#include <stdio.h>

int main()
{
    int num;
    int value,remain;

    scanf("%d",&num);
    value = num/3;
    remain = num%3;

    if(value%2==0) // 짝수,창영case
    {
        if(remain == 2)
        printf("CY");
        else if(remain==1)
        printf("SK");
        else if(remain==0)
        printf("CY");
    }
    else // 홀수, 상근case
    {
        if(remain == 2)
        printf("SK");
        else if(remain==1)
        printf("CY");
        else if(remain==0)
        printf("SK");
    }

    return 0;
}