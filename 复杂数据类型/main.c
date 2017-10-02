#include<stdio.h>
#include<stdlib.h>

enum SEX{male,female};

struct Student_Info {
	char no[9];//ѧ��
	char name[20];//����
	enum SEX sex;//�Ա�
	unsigned int age;//����
	unsigned int classno;//�༶
	float grade;//�ɼ�
};
typedef struct Student_Info STUDENT;

STUDENT *GetStuInfo(int i);
void SortSutInfo(STUDENT** pstu, int num);
void FreeMemory(STUDENT** pstu, int num);

void main()
{
	STUDENT** pstu;
	int i, num;
	printf("input the number of the student: ");//����ѧ������
	scanf("%d", &num);
	if (num <= 0)
		return;
	//��̬�����ṹ��ָ��
	pstu = (STUDENT**)malloc(num*sizeof(STUDENT*));
	if (pstu==NULL)
	{
		printf("not enough memory!\n");
		return;
	}
	//����ÿһ��ѧ����Ϣ
	for (int i = 0; i < num; ++i)
	{
		pstu[i] = GetStuInfo(i);
		if (pstu[i] == NULL)
		{
			printf("not enough memory!\n");
			FreeMemory(pstu, i);
			return;
		}
	}
	SortSutInfo(pstu,num);//��ѧ����Ϣ����
	printf("\n================sort result=================\n");
	for (int i = 0; i < num; ++i)
	{
		printf("%12s%20s%9s%5d%8.1f\n", pstu[i]->no, pstu[i]->name,
			(pstu[i]->sex==male)?"man":"women",pstu[i]->age,pstu[i]->classno,pstu[i]->grade);
	}
	FreeMemory(pstu, num);
}

//��ѧ����Ϣ�Ӹߵ�������
void SortSutInfo(STUDENT** pstu, int num)
{
	STUDENT* p;
	int i, j, k;
	for (i = 0; i < num; ++i)
	{
		k = i;
		for (j = i + 1; j < num; ++j)
			if (pstu[i]->grade>pstu[j]->grade)
				k = j;
		if (k != j)
		{
			p = pstu[i];
			pstu[i] = pstu[k];
			pstu[k] = p;
		}
	}
}

//�ͷ��ڴ�
void FreeMemory(STUDENT** pstu, int num)
{
	int i;
	for (i = 0; i < num; ++i)
	{
		free(pstu[i]);
	}
	free(pstu);
}
//����ѧ����Ϣ
STUDENT *GetStuInfo(int i)
{
	STUDENT* p;
	char sex;
	p = (STUDENT*)malloc(sizeof(STUDENT));
	if (p == NULL)
		return NULL;
	printf("\n============intput%dth student`s information==============\n", i + 1);
	printf("no: ");
	scanf("%s", p->no);
	printf("name: ");
	scanf("%s", p->name);
	fflush(stdin);
	while (1)
	{
		printf("sex(M,F): ");
		scanf("%c", &sex);
		if (sex == 'M' || sex == 'F')
			break;
		fflush(stdin);
	}
	p->sex = (sex == 'M') ? male : female;
	printf("age: ");
	scanf("%d", &p->age);
	printf("classno: ");
	scanf("%d", &p->classno);
	printf("grade: ");
	scanf("%f", &p->grade);
	return p;
}