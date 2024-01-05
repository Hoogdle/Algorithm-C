// 선택 정렬 알고리즘
// 정렬된 수는 제외 하는 concept 이해하기!(array[j])

#include <stdio.h>

int main()
{
    int i,j,index,temp,min; // index는 인덱스 조회, min은 최소값, temp는 값의 변경을 위해 설정

    int array[10] = {1,10,5,8,7,6,4,3,2,9}; //  임의의 배열 선언

    for(i=0;i<10;++i)
    {
        min = 9999; // 최소값 설정을 위해 임의의 큰수로 초기화
        for(j=i;j<10;++j)
        {
            if(min>array[j])
            {
                min = array[j]; // if array[i], 모든 수 but array[j] 정렬된 수 제외
                index = j; // min의 index 갖고오기 //j값은 이후 없어짐, index 이용!
            }
        }
        temp = array[i];
        array[i] = array[index];
        array[index] = temp;

    }

    for(int i=0;i<10;++i)
    {
        printf("%d ",array[i]);
    }


    return 0;
}