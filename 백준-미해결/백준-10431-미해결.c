// 백준-10431-줄세우기, 시간제한 1초 메모리 제한 258mb


// 알고리즘 
// : 배열은 항상 오름차순으로 정렬됨.
// : 이중 for문으로 배열중 자신보다 크기가 큰 값을 찾는다.(가장 minimal하게 큰 값임)
// : 큰 값의 인덱스 - 현재 인덱스 를 count 변수에 누적하여 더한 값을 출력한다.
// : (큰 값의 인덱스) - (현재 인덱스) = 현재 인덱스(값이 입력된 인덱스)와 minimal하게 큰 값 사이의 수 중에서 현재 인덱스를 제외하고 모두 한 칸씩 밀려남.

// 어려웠거나 고쳐야 할 점
// : 제한시간이 1초이므로 배열으로 푸는 것은 비효율 적으로 보임, 좀 더 간결한 방법을 찾아야 함.
// : 한 칸씩 뒤로 밀려나게 하는 알고리즘이 다소 복잡하고 비효율적임. 좀 더 효율적인 알고리즘을 모색해야 함.
// : 문제에서 주어진 테스트 케이스는 모두 통과했지만 실패라 뜸 이유를 모르겠음.

#include <stdio.h>

int main()
{
    int num;
    scanf("%d",&num);
    int array[20];

    for(int i=0;i<num;++i)
    {
        int seq;
        int count = 0;
        scanf("%d",&seq);

        for(int i=0;i<20;++i)
        {
            scanf("%d",&array[i]);
            for(int j=0;j<i;++j)
            {
                if(array[i]<array[j]) // j는 minimal big 값 i는 새로운 value
                {
                    int temp = array[i]; // 들어온 value를 temp 에 저장
                  
                    int temp1,temp2;
                   for(int l=j;l<i;++l) // j부터 i-1 까지의 배열을 한 칸씩 뒤로
                   {  
                       if(l==0)
                       {
                        temp1 = array[l];
                        temp2 = array[l+1];
                        array[l+1] = temp1;
                       }
                       else if(l%2!=0) // 1 3 5 7, temp2 에 값이 저장됨. temp1 에 값을 저장
                       {
                        temp1 = array[l+1]; // temp1 의 새로운 기능
                        array[l+1] = temp2; // temp2 의 기능다함
                       }
                       else // 2 4 6 8 , temp1 에 값이 저장됨. temp2 에 저장
                       {
                        temp2 = array[l+1]; // temp2 의 새로운 기능
                        array[l+1] = temp1; // temp2 의 기능다함
                       }
                   }
                   array[j] = temp; // array[j]의 값 교체
                   count += i-j;
                }
            }
        }
        printf("%d %d\n",seq,count);
    }

    return 0;
}