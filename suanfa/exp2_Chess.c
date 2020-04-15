#include <stdio.h>

// 2.1 分治法·残缺棋盘问题

int  amount = 0;  // 记录三格板的个数
int  Board[256][256];  // 创建棋盘

// 声明函数
void Cover(int tr, int tc, int dr, int dc, int size);
void OutputBoard(int size);

int main() {
    int k, a, b;
    int size = 1;  // 记录棋盘边长
    printf("输入2的幂次: ");
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        size = size * 2;
    }

    printf("输入残缺块的坐标: ");
    scanf("%d %d", &a, &b);
    if (a >= 0 && a < size && b >= 0 && b < size) {
        Board[a][b] = 0;
    } else {
        printf(">> 坐标超出合法范围,请重新输入 >>\n");
        return main();
    }

    Cover(0, 0, a, b, size);  // 以残缺方格为依据，开始覆盖棋盘
    OutputBoard(size);  // 输出已补全的棋盘
    return 0;
}

void Cover(int tr, int tc, int dr, int dc, int size)
{   // 覆盖残缺棋盘
    if (size < 2) {
        return;  // do nothing
    }
    int t = ++amount,  // 当前需使用的三格板的数目
        s = size / 2;   // 子棋盘大小

    // 残缺方格位于左上象限
    if (dr < tr + s && dc < tc + s) {
        Cover(tr, tc, dr, dc, s);
    } else {    //本象限中没有残缺方格, 把三格板t放在右下角
        Board[tr + s - 1][tc + s - 1] = t;
        //覆盖其余部分
        Cover(tr, tc, tr + s - 1, tc + s - 1, s);
    }
    // 残缺方格位于右上象限
    if (dr < tr + s && dc >= tc + s) {
        Cover(tr, tc + s, dr, dc, s);
    } else {    //本象限中没有残缺方格, 把三格板t放在左下角
        Board[tr + s - 1][tc + s] = t;
        //覆盖其余部分
        Cover(tr, tc + s, tr + s - 1, tc + s, s);
    }
    // 残缺方格位于左下象限
    if (dr >= tr + s && dc < tc + s) {
        Cover(tr + s, tc, dr, dc, s);
    } else {    //把三格板t放在右上角
        Board[tr + s][tc + s - 1] = t;
        //覆盖其余部分
        Cover(tr + s, tc, tr + s, tc + s - 1, s);
    }
    // 残缺方格位于右下象限
    if (dr >= tr + s && dc >= tc + s) {
        Cover(tr + s, tc + s, dr, dc, s);
    } else {    //把三格板t放在左上角
        Board[tr + s][tc + s] = t;
        //覆盖其余部分
        Cover(tr + s, tc + s, tr + s, tc + s, s);
    }
}

void OutputBoard(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%3d", Board[i][j]);
        printf("\n");
    }
}
