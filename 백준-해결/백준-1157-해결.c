// 백준-1157-단어공부
// * 아스키코드의 활용
// * max 값을 저장하는 알고리즘

// 알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 
// 단, 대문자와 소문자를 구분하지 않는다.

// 1. 알파벳은 총 26가지 즉, 26가지의 count 배열을 생성한다.
// 2. 알파벳 배열을 모두 대문자로 변경하고 그 과정에서 count배열을 +1한다.(아스키코드활용)
// 3. count 배열을 순환하면서 가장 큰 값과 알파벳을 찾는다. 알파벳은 index와 아스키코드를 활용해서 찾는다.
// 4. 중복된 값을 찾을 땐 i의 값(해당 알파벳index가 아닌경우) && maxcount와 같은 경우 의 조건으로 찾는다.
// 5. 만약 문자열의 길이가 1이라면 위 프로세스 중 대문자로 변환하는 단계를 거친후 문자 바로 출력

#include <stdio.h>
#include <string.h>


int main()
{
    char str[1000000];
    int count[26]={0}; // 알파벳은 총 26가지임 a~z

    scanf("%s",str);

    int num = strlen(str);

    

    int max = 0;
    char max_char = 'A';

   

    for(int i=0;i<num;++i)
    {  
        if(str[i]>='a'&&str[i]<='z')
        {
            str[i]-=32;
        }
        ++count[str[i]-'A'];
    } // 대문자로 변환 + count 세기

    if(num==1)
    {
        printf("%c",str[0]);
        return 0;
    }

    for(int i=0;i<26;++i)
    {
        if(count[i]>max)
        {
            max = count[i];
            max_char = i+'A';
        }
    } // max count와 max인 알파벳 찾기

    for(int i=0;i<26;++i)
    {
        if(i !=max_char-'A'&& max==count[i])
        {
            printf("?");
            return 0;
        }
    }

    printf("%c",max_char);



    return 0;
}