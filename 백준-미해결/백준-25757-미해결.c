// 백준-25757-임스와 함께하는 미니게임(미해결) // 시간제한 1초 // 메모리제한 512mb

// 알고리즘(입력)

// : num은 플레이 횟수, G_name은 게임이름
// : G_name에서 Y=1, F=2, O=3 으로 계산
// : 사람들의 이름 name[100000][20] 에 저장 

// 알고리즘(비교)

// : 이름을 처음~끝 탐색해서 중복되는 경우 count=0 의 값을 up
// : count == 0, 중복되는 경우가 없음, 플레이 횟수 = num/G_name
// : count != 0, 중복되는 이름이 있음, 플레이 횟수 = (num-count)/G_name

// 배운 점

//  {이차원 문자열}
// : 이차원 형태의 문자열 배열를 입력받을 때는 scanf 에서 str[i]의 형태로 입력 받는다.
// : ex) scanf("%s",str[i]) // not str[i][j] 
// : 각 열(세로)를 단독으로 썼을 땐 "주소"의 의미를 갖고 있다.

// : strcmp 에서도 strcmp(str[i],str[j]) 의 형태로 한다.
// : not strcmp(str[i][j],str[n]str[m])

// *좀 더 간단한 로직을 만들어 보자(for문 제거)

#include <stdio.h>
#include <string.h>


int main()
{
    int num;
    char name[100000][20];
    char G_name;
    int G_count;
    int count = 0;

    scanf("%d %c",&num,&G_name);

    if(G_name=='Y')
        G_count = 1;
    else if(G_name=='F')
        G_count = 2;
    else if(G_name=='O')
        G_count = 3;

    for(int i=0;i<num;++i)
    {
        scanf("%s",name[i]);
    } // 이름 입력

    for(int i=0;i<num-1;++i)
    { 
       for(int j=i+1;j<num;++j)
       {
            if(strcmp(name[i],name[j])==0)
            {
                ++count;
                break;
            }
       }
    }

    if(count==0)
    {
        printf("%d",num/G_count);
    }
    else
    {
        printf("%d",(num-count)/G_count);
    }


    return 0;
}