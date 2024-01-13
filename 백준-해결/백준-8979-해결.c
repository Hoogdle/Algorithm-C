// 백준-8979-올림픽 (해결) // 제한시간 1초 // 메모리 제한 128mb

// 알고리즘 (입력)
// : 기본 툴은 이차원배열 int array[1000][3] // 국가수 max 1000 금은동 3
// : num 변수에 국가수를 입력 받음
// : num 만큼 for문으로 이차원 배열에 정보 입력 받음

// 알고리즘 (비교)

// : 금메달,은메달,동메달 순으로 값을 비교한다. 
// : if문으로 크기 비교

// 알고리즘 (등수)

// : 각 배열마다 ranking 초기값을 1으로 두고 비교 알고리즘에서 값이 더 작을 때마다 ++ranking


#include <stdio.h>

int main()
{
    int array[1000][3];
    int ranking[1000];

    

    int num;
    int country_num;
    int want;

    scanf("%d%d",&num,&want);

    for(int i=0;i<num;++i)
    {
        ranking[i] = 1;
        scanf("%d",&country_num);
        int temp = country_num - 1;
        scanf("%d%d%d",&array[temp][0],&array[temp][1],&array[temp][2]);
    } // 값 입력


    // 금 index 0
    // 은 index 1
    // 동 index 2

    for(int i=0;i<num-1;++i)
    {
        for(int j=i+1;j<num;++j)
        {
            if(array[i][0]<array[j][0])
            {
                ranking[i]++;
                continue;
            }
            else if(array[i][0]>array[j][0])
            {
                ranking[j]++;
                continue;
            }  // 금메달 먼저 검사, 그대로 간다는 것은 금메달 값이 같다는 것

            if(array[i][1]<array[j][1])
            {
                ranking[i]++;
                continue;
            }
            else if(array[i][1]>array[j][1])
            {
                ranking[j]++;
                continue;
            }  // 은메달 검사, 그대로 감 == 은메달 값이 같음

             if(array[i][2]<array[j][2])
            {
                ranking[i]++;
                continue;
            }
            else if(array[i][2]>array[j][2])
            {
                ranking[j]++;
                continue;
            }  // 동메달 검사, 그대로 감 == 동메달 값이 같음
        }
    }

    printf("%d",ranking[want-1]);
    return 0;
}