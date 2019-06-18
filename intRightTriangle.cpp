#include <stdio.h>

bool isRightTriangle(int, int, int);
int intRightTri(int);

int main()
{
	printf("%d\n", intRightTri(1000));

	return 0;
}

bool isRightTriangle(int a, int b, int c)
{
	return c * c == b * b + a * a;
}

int intRightTri(int maxPerim)
{
	int a, b, c, p, count, maxCount, optPerim;
	maxCount = 0;

	for(int i = 3; i < maxPerim; i++)
	{
		p = i;
		count = 0;
		for(int j = 1; j < p - 1; j++)
		{
			a = j;
			for(int k = 1; k < p - a; k++)
			{
				b = k;
				c = p - a - b;
				if(isRightTriangle(a,b,c))
					count ++;
			}
		}

		if(count > maxCount)
		{
			maxCount = count;
			optPerim = p;
		}
	}

	return optPerim;
}
