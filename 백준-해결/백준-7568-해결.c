// 백준-7568-덩치(해결) // 시간제한 1초 // 메모리제한 128mb

// 알고리즘 (입력)

// : 이차원 배열 int array[num][2] 에 데이터를 입력 
// : num 은 사람의 수 2 는 몸무게,키

// 알고리즘(비교)

// : 몸무게랑 키를 동시에 비교한다. if문 + && 
// : if 몸무게 키 small, +rank
// : if 몸무게 big 키 small, pass
// : if 몸무게 small 키 big, pass
// : if 몸무게 키 big, pass

// 알고리즘(랭크)

// : 기존 랭크를 모두 1로 초기화 하고 비교문 조건에 따라 +rank

#include <stdio.h>

int main()
{
    int array[50][2];
    int num;
    int rank[50];

    scanf("%d",&num);
    
    for(int i=0;i<num;++i)
    {
        rank[i] = 1;
        scanf("%d%d",&array[i][0],&array[i][1]);
    }

    for(int i=0;i<num-1;++i)
    {
        for(int j=i+1;j<num;++j)
        {
            if(array[i][0]<array[j][0]&&array[i][1]<array[j][1])
            {
                ++rank[i];
            }
            else if(array[i][0]>array[j][0]&&array[i][1]>array[j][1])
            {
                ++rank[j];
            }
        }
    }

    for(int i=0;i<num;++i)
    {
        printf("%d ",rank[i]);
    }
    return 0;
}
