#include <stdio.h>
 
int main()
{
 
    int rows = 0, cols = 0;
    while (scanf("%d %d", &rows, &cols) != EOF)
    {
        int find;
        scanf("%d", &find);
 
        int ** arr = new int *[rows];
        for (int r = 0; r < rows; r ++)
        {
            arr[r] = new int [cols];
            for (int c = 0; c < cols; c ++)
            {
                scanf("%d", &arr[r][c]);
            }
        }
 
        // Check
        // 鉴于递增的规律性，此处通过判断每一行的第一个数组元素来决定需要检查的数字在哪一个范围内
        int rrr = 0; //保存属于的行数组
        int find_flag = 0; //是否已经确定结论的标记
        // 为了快速，先判断第一个元素是否等于当前的检查值
        if (arr[0][0] == find)
        {
            find_flag = 1;
            printf("%s", "Yes");
        }
        else
        {
            for (int rr = 1; rr < rows; rr ++)
            {
                if (arr[rr][0] == find)
                {
                    find_flag = 1;
                    printf("%s", "Yes");
                    break;
                }
                else
                {
                    if (arr[rr - 1][0] < find && arr[rr][0] > find)
                    {
                        find_flag = 2; //不需要进行末行处置
                        rrr = rr - 1;
                    }
                    // 末行修正判断
                    if (find_flag != 2 && rr == rows - 1)
                    {
                        if (arr[rr][0] > find)
                        {
                            find_flag = 1;
                            rrr = 0;
                            printf("%s", "No");
                            break;
                        }
                        else
                        {
                            rrr = rr;
                        }
                    }
                }
            }
        }
 
        // check
        if (find_flag != 1)
        {
            for (int cc = 0; cc < cols; cc ++)
            {
                if (arr[rrr][cc] == find)
                {
                    find_flag = 1;
                    printf("%s", "Yes");
                    break;
                }
            }
            if (find_flag != 1)
            {
                printf("%s", "No");
            }
        }

        printf("%s", "\n");
 
        // Release
        for (int r = 0; r < rows; r ++)
        {
            delete arr[r];
        }
        delete [] arr;
    }
 
    return 0;
}
/**************************************************************
    Problem: 1384
    User: greenrock
    Language: C++
    Result: Accepted
    Time:860 ms
    Memory:4844 kb
****************************************************************/