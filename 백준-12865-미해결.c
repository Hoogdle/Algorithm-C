// 백준 12865 평범한 배낭
// 조금더 다양한 경우 추가

#include <stdio.h>
#include <stdlib.h>

struct Info{
    int weight;
    int value;
};

int main()
{
    int num,bag;
    scanf("%d%d",&num,&bag);
    int big = 0;
    int mid = 0; 

    struct Info *ex;

    ex = (struct Info*)malloc(sizeof(struct Info)*num);

    for(int i=0;i<num;++i)
    {
        scanf("%d%d",&ex[i].weight,&ex[i].value);
    }

    for(int i=0;i<num-1;++i)
    {
        for(int j=i+1;j<num;++j)
        {
            if(ex[i].value<ex[j].value)
            {
                int temp;
                temp = ex[i].value;
                ex[i].value = ex[j].value;
                ex[j].value = temp;

                temp = ex[i].weight;
                ex[i].weight = ex[j].weight;
                ex[j].weight = temp;
            }
        }
    } // 가치순 정렬

    for(int i=0;i<num-1;++i)
    {   
        int value = ex[i].value;
        int weight = ex[i].weight;
        
        for (int j=i+1;j<num;++j)
        {
            if(weight == bag)
            {
                mid = value;
                if(big<mid)
                {
                    big = mid;
                }
                break;
            } // 첫 번째 무게 == 가방 무게

            weight += ex[j].weight;

            if(weight == bag)
            {
                value += ex[j].value;
                mid = value;
                if(big<mid)
                {
                    big = mid;
                }
                weight = ex[i].weight;
                value = ex[i].value;
                
            } // 더했는데 가방 무게와 같은 경우, 값 저장 후, 초기화

            else if(weight > bag)
            {
                weight = ex[i].weight;
            } // 더했는데 가방 무게 초과, 무게 초기값으로 초기화
            
            else if(weight < bag)
            {
                value += ex[j].value;
                if(value > big)
                {
                    mid = value;
                    big = mid;
                }
            } // 가방 무게 보다 작음, 계속 더하기 but 작음에도 불구하고 value 값이 크다면 value 값 저장

            
           
        }
    }


    printf("%d",big);

    return 0;
}


