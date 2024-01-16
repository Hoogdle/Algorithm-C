// 백준-20125-쿠키의 신체 측정(해결) // 시간제한 1초// 메모리 제한 1024mb

// 알고리즘

// {조건}

// 팔,허리,다리 모두 길이 1 이상
// 심장 위치 찾고 각 부위의 길이 찾기
// 심장 : 머리 아래
// 허리 : 심장 아래
// 팔 : 심장과 같은 줄, *의 시작과 끝
// 다리 : 심장 바로 아래의 왼쪽과 오른쪽 각각 *의 시작과 끝

// {입력}

// : char array[1000][1000] 선언 후 여기에 데이터 입력

// {찾기}

// 1. 머리 : 가장 처음에 입력한 값을 따로 저장.
// 2. 심장 : 머리 바로 아래
// 3. 왼팔 : 심장 기준 왼편에서 *이 끝나는 지점
// 4. 오른팔 : 심장 기준 오른편에서 *이 끝나는 지점
// 5. 허리 : 심장기준 아래에서 *이 끝나는 지점
// 6. 왼다리 : 허리에서 [+1][-1] 지점 아래에서 *이 끝나는 지점
// 7. 오른다리 : 허리에서 [+1][+1] 지점 아래에서 *이 끝나는 지점

// {끝나는 지점 찾기}

// 왼팔 : heartindex --> 0 , heartindex--;
// 오르팔 : heartindex --> boxarea, heartindex++;
// 심장 : heartindex --> boxarea, heartindex++
// 왼다리 : heartindex[+허리+1][-1] --> boxarea, ++
// 왼다리 : heartindex[+허리+1][+1] --> boxarea, ++

// 배운 점

// : scanf 함수는 버퍼의 내용 중 형식지정자에 맞는 내용을 불러온다.
// : 만약 scanf("%d",&num); (num은 정수형) 에서 100\n 을 입력하게 되면
// : 100 만 가져오고 \n 은 남게된다.
// : 이때, 다음 scanf 로 문자형 %c를 받게되면 \n 이 자동으로 입력되지면서 오류가 발생한다.

// 이를 해결 하는 방법으로는 
// {scanf 공백}
// : scanf(" %c",&ch); // 버퍼 중 공백과 개행 문자는 무시, 처음 만나는 문자의 값만 취함.
// {getchar}
// : getchar 함수는 버퍼에 있는 하나의 문자를 사용. 입력된 개행문자 바로 사용 가능


#include <stdio.h>

int main()
{
    char array[1000][1000];
    int num;
    int heart1,heart2;
    int count=0; // 머리를 찾기위한.
    int leftarm = 0;
    int rightarm = 0;
    int weist = 0;
    int leftleg = 0;
    int rightleg = 0;

    scanf("%d",&num);
    getchar();
    for(int i=0;i<num;++i)
    {
        for(int j=0;j<num;++j)
        {
            scanf("%c",&array[i][j]);
            if(array[i][j]=='*'&&count==0)
            {
                heart1=i+1;
                heart2=j;
                ++count; // 값을 더하면 이후 추가되는 *에는 heart 가 초기화 되지 않음
            }
            
        }
        getchar();
    } // 데이터 입력, 심장 인덱스 찾음

    

    for(int i=heart2-1;i>-1;--i)
    {
        if(array[heart1][i]=='_')
            break;
        ++leftarm;
    }

    for(int i=heart2+1;i<num;++i)
    {
        if(array[heart1][i]=='_')
            break;
        ++rightarm;
    }

    for(int i=heart1+1;i<num;++i)
    {
        if(array[i][heart2]=='_')
        {
            break;
        }
        ++weist;
    }
    
    for(int i=heart1+weist+1;i<num;++i)
    {
        if(array[i][heart2-1]=='_')
        {
            break;
        }
        ++leftleg;
    }

     for(int i=heart1+weist+1;i<num;++i)
    {
        if(array[i][heart2+1]=='_')
        {
            break;
        }
        ++rightleg;
    }

    printf("%d %d\n",heart1+1,heart2+1);
    printf("%d %d %d %d %d",leftarm,rightarm,weist,leftleg,rightleg);


    return 0;
}