// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "ymath.h"

int main()
{
	char a[100] = "D:\\1_work\\Data\\data.csv";		//1.��дcsv���ݼ�·��
	array A=initdataset(a);							//2.��ʼ������
	output(LG(A));									//3.������
	output(LDA(A));									
    return 0;
}

