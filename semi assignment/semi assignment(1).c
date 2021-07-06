#include <stdio.h>

int main()
{
	int code, electricity;
	double charge;

	printf("코드번호(1. 가정용, 2. 산업용, 3. 교육용): ");
	scanf("%d", &code);
	printf("전기사용량(kw): ");
	scanf("%d", &electricity);

	switch (code)
	{
	case 1:
		charge = 1130 + (double)(electricity * 127.8);
		charge = charge + charge * 0.09;
		break;
	case 2:
		charge = 660 + (double)(electricity * 88.5);
		charge = charge + charge * 0.08;
		break;
	case 3:
		charge = 370 + (double)(electricity * 52.0);
		charge = charge + charge * 0.05;
		break;
	default:
		break;
	}

	printf("전기요금 : %.0lf원", charge);

	return 0;
}
