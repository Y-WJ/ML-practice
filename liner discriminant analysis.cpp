// liner discriminant analysis.cpp : 定义控制台应用程序的入口点。

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
array LDA()
{
	array w = createarray(3, 1);
	array Sw = createarray(3, 3);
	array u0 = createarray(3, 1);
	array u1 = createarray(3, 1);
	array x = createarray(3, 1);
	array E0 = createarray(3, 3);
	array E1 = createarray(3, 3);
	//-------------------------------------------------
	for (int i = 0; i < 8; i++)       
	{
		x.p[1][1] = W[i].density;
		x.p[2][1] = W[i].sugar ;
		x.p[3][1] = 1;
		u0=add(u0, x, 1.0 / 8.0);
	} //给u0赋值
	for (int i = 8; i < 17; i++)      //给u1赋值
	{
		x.p[1][1] = W[i].density;
		x.p[2][1] = W[i].sugar;
		x.p[3][1] = 1;
		u1=add(u1, x, 1.0 / 8.0);
	}
	for (int i = 0; i < 8; i++)       //给E0赋值
	{
		x.p[1][1] = W[i].density;
		x.p[2][1] = W[i].sugar;
		x.p[3][1] = 1;
		E0=add(E0, dot(add(x,u0,-1),transpose(add(x,u0,-1))), 1);
	}
	for (int i = 8; i < 17; i++)      //给E1赋值
	{
		x.p[1][1] = W[i].density;
		x.p[2][1] = W[i].sugar;
		x.p[3][1] = 1;
		E1=add(E1, dot(add(x, u1, -1), transpose(add(x, u1, -1))), 1);
	}
	//---------------------------------------------------------------------
	Sw = add(E0, E1, 1);              //Sw=E0+E1
	w = dot(inverse(Sw), add(u0, u1 ,- 1));//w=Sw^(-1)*(u0-u1);
	return w;
}
int main()
{
	output(LDA());
    return 0;
}

