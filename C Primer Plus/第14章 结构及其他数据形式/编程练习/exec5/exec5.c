//  [12/4/2014 Happy]
#include <stdio.h>
#define MAX 10
#define CSIZE 4
#define LEN 3
typedef struct names {
	char first[MAX];
	char last[MAX];
} Name;

typedef struct students {
	Name name;
	int grade[3];
	double average;
} Students;

void input(Students s[], int len);
double calculateAverage(Students s[], int len);
void print(Students s[], int len);
int main(void)
{
	//声明一个长度为4的Students的数组，随意初始化名字部分
	Students s[CSIZE] = {
		{
			{"Jim","Green"}
		},
		{
			{"Lei","Li"}
		},
		{
			{"Meimei","Han"}
		},
		{
			{"Bob","Green"}
		},
	};
	input(s,CSIZE);
	calculateAverage(s,CSIZE);
	print(s,CSIZE);
	return 0;
}

/*
 * @function    : input
 * @author   	: ZhangLe
 * @date     	: 2014/12/4 21:37
 * @version  	: ver 1.0
 * @inparam  	: void
 * @outparam    : void
 * @description : 输入数据
 */
void input(Students s[], int len)
{
	int i,j;	//循环标记
	for (i = 0; i < len; i++)
	{
		printf ("Please enter scores for %s %s:\n",s[i].name.first, s[i].name.last);
		for (j = 0; j < LEN; j++)
		{
			scanf("%d", &(s[i].grade[j]));
		}
	}
}
/*
 * @function    : calculateAverage
 * @author   	: ZhangLe
 * @date     	: 2014/12/4 21:37
 * @version  	: ver 1.0
 * @inparam  	: void
 * @outparam    : void
 * @description : 计算平均分
 */
double calculateAverage(Students s[], int len)
{
	int i, j;	//循环标记
	double total;	//每个人的总分
	double avg;
	puts("Claculate Average...");
	for (i=0; i<len; ++i)
	{
		//求出总分
		total = 0;
		for (j=0; j<LEN; ++j)	
		{
			total += s[i].grade[j];
		}
		//求出平均分
		avg = total / (LEN * 1.0);
		//把平均分赋值给对应的人
		s[i].average = avg;
	}
}
/*
 * @function    : print
 * @author   	: ZhangLe
 * @date     	: 2014/12/4 21:41
 * @version  	: ver 1.0
 * @inparam  	: void
 * @outparam    : void
 * @description : 输出每个结构的信息
 */
void print(Students s[], int len)
{
	int i, j;	//循环标记
	puts("Output info...");
	for (i=0; i<len; ++i)
	{
		//输出姓名
		printf("%s %s : ",s[i].name.last,s[i].name.first);
		//输出分数
		for (j=0; j<LEN; ++j)	
		{
			printf("%d ",s[i].grade[j]);
		}
		//输出平均分
		printf("%f \n",s[i].average);
	}
}