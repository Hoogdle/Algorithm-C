// 백준-4659-비밀번호 발음하기 // 시간제한 1초 // 메모리제한 128mb

// 알고리즘 (입력)

// : while(1) 과 strcmp 를 이용해서 end가 입력될 때 까지 계속 입력받기
// : 입력될 문자열은 char str[20]

// 알고리즘 (비교)

// : 조건1. count 와 if 문을 이용
// : if 모음 포함, ++count
// : count 가 0 이라면 조건 불만족

// : 조건2. if문 || 과 && 활용
// : 먼저 if문과 || 로 i,i+1,i+2 까지 모음인지 확인
// : 아니라면 i,i+1,i+2 까지 자음인지 확인(if문과 !,&&활용)
// : 맞다면 not acceptable 출력후 continue

// : 조건3. if문을 통해 i,i+1 가 같은지 확인
// : 같을 때 해당 문자열이 e or o 가 아니라면 not acceptable

// *** 조건2, 조건3 에서 for문을 벗어난 뒤 바로 새로운 문자열을 입력 받아야 함.
// --> 각 조건 마다 count를 둔다. (count2,count3)
// 조건을 불만족 시키면 count up
// for문을 나온뒤 count의 값이 1이라면 continue 키워드 사용

#include <stdio.h>
#include <string.h>

int main()
{
    char str[20];
    
    while(1)
    {
        scanf("%s",str);
        if(strcmp(str,"end")==0)
            return 0;
        
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;

        int num = strlen(str);
        // 조건1
        for(int i=0;i<num;++i)
        {
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
                ++count1;
        }
        if(count1==0)
        {
            printf("<%s> is not acceptable.\n",str);
            continue;
        }

        // 조건2
        for(int i=0;i<num-2;++i)
        {
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
                if(str[i+1]=='a'||str[i+1]=='e'||str[i+1]=='i'||str[i+1]=='o'||str[i+1]=='u')
                    if(str[i+2]=='a'||str[i+2]=='e'||str[i+2]=='i'||str[i+2]=='o'||str[i+2]=='u')
                    {
                        ++count2;
                        printf("<%s> is not acceptable.\n",str);
                        break;
                    } // 모음이 3개 연속

            if(str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u')
                if(str[i+1]!='a'&&str[i+1]!='e'&&str[i+1]!='i'&&str[i+1]!='o'&&str[i+1]!='u')
                    if(str[i+2]!='a'&&str[i+2]!='e'&&str[i+2]!='i'&&str[i+2]!='o'&&str[i+2]!='u')
                    {
                        ++count2;
                        printf("<%s> is not acceptable.\n",str);
                        break;
                    } // 자음이 3개 연속
        }
        if(count2==1)
            continue;

        // 조건3
        for(int i=0;i<num-1;++i)
        {
            if(str[i]==str[i+1])
            {
                if(str[i]!='e'&&str[i]!='o')
                {
                    ++count3;
                    printf("<%s> is not acceptable.\n",str);
                    break;
                }
            }
        }
        if(count3==1)
            continue;

        printf("<%s> is acceptable.\n",str);
    }
    return 0;
}