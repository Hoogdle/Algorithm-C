// 백준-1205-등수 구하기(해결) // 시간제한 2초 // 메모리 제한 128mb

// 알고리즘

// {조건}

// -1 == 랭킹에 올라가지 못하는 상황
// : P==N 일 때 영수의 값이 입력되면 P<N 인 상황, 즉 데이터 꽉 찬 상황.
// : 이 때 영수가 꼴찌 or 공동 꼴찌이면 -1 출력

// {입력}
// num : 올갈 수 있는 점수의 갯수 (10<=num<=50) <P>
// num_l : 리스트 점수의 갯수 (0<=num_l<=num) <N>
// score : 영수의 점수
// int array[50] : 점수 리스트
// int rank[50] : 랭킹 리스트

// {과정}
// 1. num_l,score,num 에 각각 data 받음.
// 2. for문 num_l 로 리스트 점수 array[50]에 받기
// 3. 마지막 인덱스에 영수의 점수 받기;
// 4. array 마지막 인덱스 까지 랭킹 값 1로 초기화
// 5. 랭킹 알고리즘으로 랭킹 부여
// 6. 랭킹 알고리즘에서 가장 큰 값을 for 문 돌려 찾기
// 7. 위의 {조건} 만족하는 경우 for문을 한 번 더 돌려 가장 큰 값과 같은 값이 있는지 확인(공동 꼴찌)

// 배운 점
// 끝까지 포기하지 말고 문제의 조건을 하나하나 분석하자!
// 각 반례 case 들을 찾아 추가하지 말자!
// 문제가 요구하는 중심(원리)가 뭔지 파악하고 일반화 하자!

// : 리스트가 full 일 때, 즉 num_l = num 일 때 사용자가 입력한 값이 기존의 값보다 작거나 같으면 -1을 출력
// : 기존의 값에서 비교해야 하므로 원래 리스트에서 smallest 한 것을 발견.
// : 입력 데이터와 비교해서 입력값 <= smallest 라면 -1 출력(문제가 애매하긴 함.)
#include <stdio.h>

int main()
{
    int num_l,score,num;
    int big = -1;
    int small;
    int array[50];
    int rank[50];

    scanf("%d%d%d",&num_l,&score,&num);

    if(num_l==0)
    {
        printf("%d",1);
        return 0;
    }
    

    for(int i=0;i<num_l;++i)
    {
        scanf("%d",&array[i]); // 값 입력 받음
        rank[i] = 1; // 랭크 초기화
    }
    
    array[num_l] = score; // 영수 값을 리스트에 입력
    rank[num_l] = 1; // 영수 랭크 초기화



    for(int i=0;i<=num_l-1;++i)
    {
        for(int j=i+1;j<=num_l;++j)
        {
            if(array[i]>array[j])
            {
                ++rank[j];
            }
            else if(array[i]<array[j])
            {
                ++rank[i];
            }
        }
    } // 랭킹 부여


    small = array[0];
    for(int i=0;i<num_l;++i)
    {
        if(small>array[i])
            small = array[i];
    } // 가장 작은 값 추출

   if(num_l==num)
   {
        if(array[num_l]<=small)
        {
            printf("%d",-1);
            return 0;
        }

   }

for(int i=0;i<num_l;++i)
    {
        if(array[i]>big)
        {
            big = array[i];
        }
    }

    if(num_l==num&&rank[num_l]==big)
    {
        int count = 0;
         for(int i=0;i<=num_l;++i)
        {
            if(big==rank[i])
                ++count;
        }
        if(count>1)
        {
            printf("%d",-1);
            return 0;
        }
    } // -1 출력 상황
    
    printf("%d",rank[num_l]); // -1 출력 상황이 아니다. 일반 랭크 출력
    


    return 0;
}

/*
 for(int i=0;i<num_l;++i)
    {
        if(array[i]>big)
        {
            big = array[i];
        }
    }

    if(num_l==num&&rank[num_l]==big)
    {
        int count = 0;
         for(int i=0;i<=num_l;++i)
        {
            if(big==rank[i])
                ++count;
        }
        if(count>1)
        {
            printf("%d",-1);
            return 0;
        }
    } // -1 출력 상황
*/