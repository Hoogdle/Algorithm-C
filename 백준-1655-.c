// linked list를 활용한 풀이
// 23.01.04 
// : struct Info* temp 선언후 temp를 malloc로 초기화 한 후 temp -> next 는 NULL 로 초기화 시켜줘야 함.
// : del 함수에서 while(temp==NULL) -> while(temp!=NULL) 로 수정, head = NULL 추가
// : (i+1/2) -> (i+2)/2 로 수정
// : 짝수인 경우 for문 횟수 input -1 , 홀수인 경우 for문 횟수 input
// : 0 1 2 3 짝수개  input 2 want 1 move 1 num = 1

//   0 1 2 3 4 5 짝수개 input 3 want 2 move 2 num 2 // input -1

//   0 1 2 홀수개 input 1 want 1 move 1 num 1

//   0 1 2 3 4 홀수개 input 2 want 2 move 2 num 2


#include <stdio.h>
#include <stdlib.h>

struct Info{
    int value;
    struct Info* next;
};

void sort(struct Info* a);
int search_even(int num);
int search_odd(int num);
void del();

struct Info* head = NULL;

int main()
{
    int num;
    scanf("%d",&num);

    for(int i=0;i<num;++i)
    {
        int data;
        scanf("%d",&data);
        struct Info* temp;
        temp = (struct Info*)malloc(sizeof(struct Info));
        temp->value = data;
        temp->next = NULL;
        sort(temp);

        if(i==0)
        {
            printf("%d\n",data);

        }

        else if(i==1)
        {
            int result1,result2;
            result1 = head->value;
            result2 = data;
            if(result1>result2)
                printf("%d\n",result2);
            else    
                printf("%d\n",result1);
        } // 문제없음
        else if((i+1)%2==0) // 짝수개인 경우
        {
            int result;
            result = search_even((i+1)/2);
            printf("%d\n",result);
        }
        else if((i+1)%2!=0) // 홀수개인 경우
        {
            int result;
            result = search_odd((i+1)/2);
            printf("%d\n",result);
        }

    }
    del();
    return 0;
}

void sort(struct Info* a)
{
    struct Info* search;
    struct Info* prev = NULL;
    if(head == NULL)
        {
            head = a; //// head 까진 잡힘
        }
            
    else
    {
        search = head;
        if(a->value < head->value)
        {
            a->next = head;
            head = a;
        } // 맨 첫 번째 삽입
        else
        {
            while(search != NULL && search->value < a->value)
            {
                prev = search;
                search = search->next;
            } // node 이동 
        
            a->next = search;
            prev->next = a;
        }
    }

    
    
}

int search_even(int num)
{
    int temp1;
    struct Info *temp = head;
    for(int i=0;i<num-1;++i)
    {
        temp1 = temp->value;
        temp = temp->next;
    }

    return temp1;
    
} // 짝수개인 경우 num-1

int search_odd(int num)
{
    int temp1;
    struct Info *temp = head;
    for(int i=0;i<num;++i)
    {
       temp1 = temp->value;
        temp = temp->next;
    }
    return temp1;
} // 홀수개인 경우 num 그대로

void del()
{
    struct Info* temp;
    struct Info* sup = NULL;
    temp = head;

    while(temp != NULL)
    {
        sup = temp->next;
        free(temp);
        temp = sup;

    }
    head = NULL;
}
