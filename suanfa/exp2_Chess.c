#include <stdio.h>

// 2.1 ���η�����ȱ��������

int  amount = 0;  // ��¼�����ĸ���
int  Board[256][256];  // ��������

// ��������
void Cover(int tr, int tc, int dr, int dc, int size);
void OutputBoard(int size);

int main() {
    int k, a, b;
    int size = 1;  // ��¼���̱߳�
    printf("����2���ݴ�: ");
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        size = size * 2;
    }

    printf("�����ȱ�������: ");
    scanf("%d %d", &a, &b);
    if (a >= 0 && a < size && b >= 0 && b < size) {
        Board[a][b] = 0;
    } else {
        printf(">> ���곬���Ϸ���Χ,���������� >>\n");
        return main();
    }

    Cover(0, 0, a, b, size);  // �Բ�ȱ����Ϊ���ݣ���ʼ��������
    OutputBoard(size);  // ����Ѳ�ȫ������
    return 0;
}

void Cover(int tr, int tc, int dr, int dc, int size)
{   // ���ǲ�ȱ����
    if (size < 2) {
        return;  // do nothing
    }
    int t = ++amount,  // ��ǰ��ʹ�õ���������Ŀ
        s = size / 2;   // �����̴�С

    // ��ȱ����λ����������
    if (dr < tr + s && dc < tc + s) {
        Cover(tr, tc, dr, dc, s);
    } else {    //��������û�в�ȱ����, �������t�������½�
        Board[tr + s - 1][tc + s - 1] = t;
        //�������ಿ��
        Cover(tr, tc, tr + s - 1, tc + s - 1, s);
    }
    // ��ȱ����λ����������
    if (dr < tr + s && dc >= tc + s) {
        Cover(tr, tc + s, dr, dc, s);
    } else {    //��������û�в�ȱ����, �������t�������½�
        Board[tr + s - 1][tc + s] = t;
        //�������ಿ��
        Cover(tr, tc + s, tr + s - 1, tc + s, s);
    }
    // ��ȱ����λ����������
    if (dr >= tr + s && dc < tc + s) {
        Cover(tr + s, tc, dr, dc, s);
    } else {    //�������t�������Ͻ�
        Board[tr + s][tc + s - 1] = t;
        //�������ಿ��
        Cover(tr + s, tc, tr + s, tc + s - 1, s);
    }
    // ��ȱ����λ����������
    if (dr >= tr + s && dc >= tc + s) {
        Cover(tr + s, tc + s, dr, dc, s);
    } else {    //�������t�������Ͻ�
        Board[tr + s][tc + s] = t;
        //�������ಿ��
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
