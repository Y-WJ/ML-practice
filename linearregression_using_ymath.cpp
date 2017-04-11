// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ymath.h"

int main()
{
	char a[100] = "D:\\1_work\\Data\\data.csv";		//1.填写csv数据集路径
	array A=initdataset(a);							//2.初始化矩阵
	output(LG(A));									//3.输出结果
	output(LDA(A));									
    return 0;
}

