// 백준 23971번 ZOAC4 (해결)

// 사용된 알고리즘
// 배치를 할 때 (1,1)를 기점으로 배열을 시작
// 행과 열 각각의 최대 count 수를 구하고 곱하는 방식
// 최대 count 수를 구할 땐 '정해진 영역' 과 '더해지는 수의 관계'를 중심으로 구하기

#include <stdio.h>

int main()
{
    int row, column; // 행 가로(row) 열 세로(column)
    int count_row, count_column;

    int for_mul_column = 1; // 곱하는 개념으로 접근
    int for_mul_row = 1;

    int for_count_row = 1; // 좌표계 개념 도입
    int for_count_column = 1;

    scanf("%d%d%d%d", &column, &row, &count_column, &count_row);

    int add_row = count_row + 1; // 더해나가는 수
    int add_column = count_column + 1;

   

    while (1)
    {
        for_count_row += add_row;
        if (for_count_row > row)
        break;
        ++for_mul_row;
    }
    //printf("%d\n", for_mul_row);

    while (1)
    {
        for_count_column += add_column;
        if (for_count_column > column)
        break;
        ++for_mul_column;
    }
    //printf("%d\n", for_mul_column);

    printf("%d", for_mul_row * for_mul_column);

    return 0;
}