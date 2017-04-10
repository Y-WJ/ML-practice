// linear regression.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include "ymath.h"

struct watermelon
{
	int number;
	float density;
	float sugar;
	int good;
};
struct watermelon W[17] =
{
	1,0.697,0.460,1,
	2,0.774,0.376,1,
	3,0.634,0.264,1,
	4,0.608,0.318,1,
	5,0.556,0.215,1,
	6,0.403,0.237,1,
	7,0.481,0.149,1,
	8,0.437,0.211,1,
	9,0.666,0.091,0,
	10,0.243,0.267,0,
	11,0.245,0.057,0,
	12,0.343,0.099,0,
	13,0.639,0.161,0,
	14,0.657,0.198,0,
	15,0.360,0.370,0,
	16,0.593,0.042,0,
	17,0.719,0.103,0
};
array Linear()
{
	array X, y,w;
	X = createarray(17, 3);
	y = createarray(17, 1);
	w = createarray(3, 1);
	for (int i = 0; i < 17; i++)
	{
		X.p[i + 1][1] = W[i].density;
		X.p[i + 1][2] = W[i].sugar;
		X.p[i + 1][3] = 1;
		y.p[i + 1][1] = W[i].good;
	}
	w = dot(dot(inverse(dot(transpose(X), X)), transpose(X)), y);
	return w;
}
int main()
{
	array w;
	w = createarray(3, 1);
	printf("线性回归(最小二乘法)\n");
	output(w = Linear());
    return 0;
}

