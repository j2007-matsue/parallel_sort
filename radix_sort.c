#include <stdio.h>

int bits(int x, int k, int i);
void RadixSort(int x[], int n, int w);
void ShowData(int x[], int n);

#define NUM_DATA 10

static int rad[NUM_DATA]; // ������܂��z��
static int y[NUM_DATA]; // ��Ɨp�z��

// x��k�r�b�g�E�V�t�g��, ���̍�i�r�b�g�����o��
int bits(int x, int k, int i) {
	return (x >> k) & ~(~0 << i);
}

// ��\�[�g���s
void RadixSort(int x[], int n, int w)
{
	int i, j, k;
	int s = 4; // �V�t�g����r�b�g��

	for (int m = 0; m < w / s; m++)
	{
		for (i = 0; i < n; i++)
			//rad[i] = (x[i] / m) % 10;
			rad[i] = bits(x[i], m * s, s);
		k = 0;
		for (i = 0; i <= 16 - 1; i++)
			for (j = 0; j < n; j++)
				if (rad[j] == i)
					y[k++] = x[j];

		for (i = 0; i < n; i++)
			x[i] = y[i];

		// �r���o��
		printf("\n�\�[�g��:\n");
		ShowData(x, n);

		//m *= 10;
	}
}

// �f�[�^��\������
void ShowData(int x[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d\t", x[i]);
}

void main(void)
{
	// int x[NUM_DATA] = { 5489, 147, 78, 1058, 9448, 8, 7979, 2163, 1856, 311 };
	int x[NUM_DATA] = { 2, 1, 8, 5, 4, 7, 9, 0, 6, 3 };
	int w = 8; // �z��̗v�f�̍ő�r�b�g��

	// �\�[�g�O
	printf("�\�[�g�O:\n");
	ShowData(x, NUM_DATA);
	printf("\n");

	RadixSort(x, NUM_DATA, w);

	// �\�[�g��
	printf("\n\n�\�[�g��:\n");
	ShowData(x, NUM_DATA);
}