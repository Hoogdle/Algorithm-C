// 시간 초과, 정렬을 사용하지 않고 풀자!

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int *array;

   int num;
   scanf("%d",&num);

   array = (int*)malloc(sizeof(int)*num);

   for(int i=0;i<num;++i)
   {
        scanf("%d",&array[i]);
        if(i==0)
            printf("%d\n",array[0]);
        else if(i ==1)
        {
            int temp;
            temp = array[0]>array[1] ? array[1] : array[0];
            printf("%d\n",temp);
        } // 성공적

        else
        {
            for(int k=0;k<=i-1;++k)
            {
                for(int n=k+1;n<=i;++n)
                {
                    if(array[k]>array[n])
                    {
                        int temp;
                        temp = array[k];
                        array[k] = array[n];
                        array[n] = temp;
                    }
                }
            } // 오름차순으로 정렬

            if((i+1)%2==0) // count 가 짝수인 경우
            {
                int temp,result;
                temp = i/2;
                result = array[temp] > array[temp+1] ? array[temp+1] : array[temp];
                printf("%d\n",result);
            }
            else if((i+1)%2!=0) // count 가 홀수인 경우
            {
                printf("%d\n",array[i/2]);
            }
        }
   }

   free(array);


    return 0;
}