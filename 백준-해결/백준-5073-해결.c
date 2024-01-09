// 삼각형과 세변

// 논리연산자의 활용, 특별한 풀이 방법은 없음


#include <stdio.h>

int main()
{
    int num1,num2,num3;
    int big;

    while(1)
    {
        scanf("%d%d%d",&num1,&num2,&num3);


        if(num1==0&&num2==0&num3==0)
        {
            break;
        }

       //삼각형이 아닌 경우 제외
       if(num1>=num2+num3||num2>=num1+num3||num3>=num1+num2)
       {
        printf("Invalid\n");
        continue;
       }
        
        //정삼각형
        if(num1==num2&& num2==num3)
        {
            printf("Equilateral\n");
            continue;
        }
        else if((num1==num2&&num1!=num3)||(num2==num3&&num2!=num1)||(num1==num3&&num1!=num2))
        {
            printf("Isosceles\n");
            continue;
        }
        else if(num1!=num2 && num2!=num3 && num1!=num3)
        {
            printf("Scalene\n");
            continue;
        }
        
        if(num1==0&&num2==0&num3==0)
        {
            break;
        }

        
        

    }

    return 0;
}