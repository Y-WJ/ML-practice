// logistic regression for watermelon.cpp : 定义控制台应用程序的入口点。
//西瓜数据集的对数几率回归

#include "stdafx.h"
#include "math.h"
#define e 2.7182818284590

float dot(float *x, float *y, int n)//向量积，n指定向量维度
{
	float sum = 0;
	for (int i = 0; i < n; i++)
		sum += x[i] * y[i];
	return sum;
}
struct watermelon
{
	int number;
	float density;
	float sugar;
	int good;
};

struct watermelon W[17]=
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

float logistic(float x)
{
	return (1 / (1 + powf(e, -x)));
}

float *gradient(struct watermelon *W)//愚蠢的西瓜分类器
{
	int temp = 100000;
	int i, j;
	float wb[3] = { 1,1,1 };//随便找个点
	float a = 0.0001;
	float gra[3];//用来存梯度向量
	for (i = 0; i < temp; i++)//步长0.001 先跑100000轮
	{
		for (j = 0; j < 3; j++)
			gra[j] = 0;
		for (j = 0; j < 17; j++)
		{
			gra[0] +=a* (logistic(wb[1] * W[j].density + wb[2] * W[j].sugar + wb[0]) - W[j].good);//对应三个梯度公式
			gra[1] += a*W[j].density*(logistic(wb[1] * W[j].density + wb[2] * W[j].sugar + wb[0]) - W[j].good);
			gra[2] += a*W[j].sugar*(logistic(wb[1] * W[j].density + wb[2] * W[j].sugar + wb[0]) - W[j].good);
		}
		for (j = 0; j < 3; j++)
			wb[j] -=gra[j];//根据梯度更新wb
	}
	return wb;
}

float *linear(struct watermelon *W)//更蠢的西瓜分类器
{
	int temp = 1000000;
	int i, j;
	float wb[3] = { 1,1,1 };//随便找个点
	float a = 0.0001;
	float gra[3];//用来存梯度向量
	for (i = 0; i < temp; i++)//步长0.001 先跑100000轮
	{
		for (j = 0; j < 3; j++)
			gra[j] = 0;
		for (j = 0; j < 17; j++)
		{
			gra[0] += a* (wb[1] * W[j].density + wb[2] * W[j].sugar + wb[0] - W[j].good);//对应三个梯度公式
			gra[1] += a*W[j].density*(wb[1] * W[j].density + wb[2] * W[j].sugar + wb[0] - W[j].good);
			gra[2] += a*W[j].sugar*(wb[1] * W[j].density + wb[2] * W[j].sugar + wb[0] - W[j].good);
		}
		for (j = 0; j < 3; j++)
			wb[j] -= gra[j];//根据梯度更新wb
	}
	return wb;
}

int main()
{
	float *g = gradient(W);
	printf("对数几率回归:\n%f\n%f\n%f\n", g[1], g[2], g[0]);
	float *l = linear(W);
	printf("线性回归(梯度下降):\n%f\n%f\n%f\n", l[1], l[2], l[0]);
    return 0;
}

