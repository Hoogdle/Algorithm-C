// 백준-2292-벌집
// 시간제한 2초, 메모리제한 128mb

// 1. 모든 벌집이 균일하게 붙어 있기 때문에 각 set마다 걸리는 최소 거리는 같을 것이다.
// 2. 각 set마다의 최소거리와 방의 num의 관계를 구하고 일반화 하기
// 3. 2에서의 관계는 각 set 의 max min 의 관계와 거리의 관계로 구함

/*{풀이과정}

n=1     거리=1
n=2~7   거리=2
n=8~19  거리=3
n=20~37 거리=4
n=38~61 거리=5 
......

일반화 하기
min = 2,8,20,38 ...
delta min = 6,12,18 (6의 배수가 더해짐을 확인)

max = 7,19,37,61 ...
delta max = 12,18,24 (6의 배수가 더해짐을 확인)

즉 사용자가 입력한 num 가 각 set의 min max에 걸치는지 확인,
걸친다면 count값을 반환
걸치지 않는다면 걸칠 때 까지 min 과 max에 6의 배수를 더해주는 형태*/



#include <stdio.h>
 
int main()
{
    int num;
    int small=2,big=7;
    int count=1;

    scanf("%d",&num);

    if(num==1)
        {
            printf("%d",1);
            return 0;
        } // 1인 경우 1출력 후 종료

    while(1)
    {
        
        
        if(num>=small&&num<=big)
        {
            printf("%d",count+1);
            break;
        }
        else
        {
            small += 6*count;
            big += 6*(count+1);
            ++count;
        }
       


    }
    return 0;
}