/* 2254298 信11 范潇 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int num = 0, Atop, Btop, Ctop, Aplate[10], Bplate[10], Cplate[10], i;
void horizontal()
{
	int i, tenflag = 0;
	printf("A:");
	for (i = 0; i < Atop; i++) {
		if (Aplate[i] == 10)
			tenflag = 1;
		printf("%d ", Aplate[i]);
	}
	for (i = 0; i < 2 * (10 - Atop) + 1 * tenflag + 2; i++)
		printf(" ");
	tenflag = 0;

	printf("B:");
	for (i = 0; i < Btop; i++) {
		if (Bplate[i] == 10)
			tenflag = 1;
		printf("%d ", Bplate[i]);
	}
	for (i = 0; i < 2 * (10 - Btop) + 1 * tenflag + 2; i++)
		printf(" ");
	printf("C:");
	for (i = 0; i < Ctop; i++)
		printf("%d ", Cplate[i]);
	printf("\n");
}

void hanoi(int n, char src, char tmp, char dst)
{
	int temp;
	if (n == 1) {
		num++;
		switch (dst - 'A') {
			case(0):
				switch (src - 'A') {
					case(1):
						Aplate[Atop] = Bplate[Btop - 1];
						Atop++;
						Btop--;
						break;

					case(2):
						Aplate[Atop] = Cplate[Ctop - 1];
						Atop++;
						Ctop--;
						break;
				}
				break;
			case(1):
				switch (src - 'A') {
					case(0):
						Bplate[Btop] = Aplate[Atop - 1];
						Btop++;
						Atop--;
						break;

					case(2):
						Bplate[Btop] = Cplate[Ctop - 1];
						Btop++;
						Ctop--;
						break;
				}
				break;
			case(2):
				switch (src - 'A') {
					case(0):
						Cplate[Ctop] = Aplate[Atop - 1];
						Ctop++;
						Atop--;
						break;
					case(1):
						Cplate[Ctop] = Bplate[Btop - 1];
						Ctop++;
						Btop--;
						break;
				}
				break;
		}
		printf("第%4d步( 1)%c-->%c ", num, src, dst);
		horizontal();
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	num++;
	switch (dst - 'A') {
		case(0):
			switch (src - 'A') {
				case(1):
					Aplate[Atop] = Bplate[Btop - 1];
					temp = Bplate[Btop - 1];
					Atop++;
					Btop--;
					break;

				case(2):
					Aplate[Atop] = Cplate[Ctop - 1];
					temp = Cplate[Ctop - 1];
					Atop++;
					Ctop--;
					break;
			}
			break;
		case(1):
			switch (src - 'A') {
				case(0):
					Bplate[Btop] = Aplate[Atop - 1];
					temp = Aplate[Atop - 1];
					Btop++;
					Atop--;
					break;

				case(2):
					Bplate[Btop] = Cplate[Ctop - 1];
					temp = Cplate[Ctop - 1];
					Btop++;
					Ctop--;
					break;
			}
			break;
		case(2):
			switch (src - 'A') {
				case(0):
					Cplate[Ctop] = Aplate[Atop - 1];
					temp = Aplate[Atop - 1];
					Ctop++;
					Atop--;
					break;
				case(1):
					Cplate[Ctop] = Bplate[Btop - 1];
					temp = Bplate[Btop - 1];
					Ctop++;
					Btop--;
					break;
			}
			break;
	}
	printf("第%4d步(%2d)%c-->%c ", num, temp, src, dst);
	horizontal();
	hanoi(n - 1, tmp, src, dst);
	return;
}

int main()//TODO:输出为浮点数的且未指定格式的，均要求 double 型，C++为 cout 缺省输出，C 为%lf 的缺省输出
{

	int n, ret;
	char src, tmp, dst;
	printf("请输入汉诺塔的层数(1-10)\n");
	while (1) {
		ret = scanf("%d", &n);
		while (getchar() != '\n')
			;
		if (n >= 0 && n <= 16 && ret == 1)
			break;
		printf("请输入汉诺塔的层数(1-10)\n");
	}


	printf("请输入起始柱(A-C)\n");
	while (1) {
		ret = scanf("%c", &src);
		while (getchar() != '\n')
			;
		if ((src == 'A' || src == 'B' || src == 'C' || src == 'a' || src == 'b' || src == 'c') && ret == 1) {
			switch (src) {
				case 'a':
					src = 'A';
					break;
				case 'b':
					src = 'B';
					break;
				case 'c':
					src = 'C';
					break;
			}
			break;
		}
		printf("请输入起始柱(A-C)\n");
	}

	printf("请输入目标柱(A-C)\n");
	while (1) {
		ret = scanf("%c", &dst);
		while (getchar() != '\n')
			;
		if ((dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c') && ret == 1)
			break;
		if (dst == src || dst == (src - 32) || dst == (src + 32))
			printf("目标柱(%c)不能与起始柱(%c)相同\n", src, src);
		printf("请输入目标柱(A-C)\n");
	}
	switch (dst) {
		case 'a':
			dst = 'A';
			break;
		case 'b':
			dst = 'B';
			break;
		case 'c':
			dst = 'C';
			break;
	}
	printf("移动步骤为:\n");
	tmp = (int)(src != 'A') * (int)(dst != 'A') * 'A' + (int)(src != 'B') * (int)(dst != 'B') * 'B' + (int)(src != 'C') * (int)(dst != 'C') * 'C';
	switch (src) {
		case('A'):
			Atop = n;
			for (i = 0; i < n; i++)
				Aplate[i] = n - i;
			break;
		case('B'):
			Btop = n;
			for (i = 0; i < n; i++)
				Bplate[i] = n - i;
			break;
		case('C'):
			Ctop = n;
			for (i = 0; i < n; i++)
				Cplate[i] = n - i;
			break;
	}

	printf("起始:             ");
	horizontal();
	hanoi(n, src, tmp, dst);
	return 0;
}