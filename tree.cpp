// tree.cpp : Defines the entry point for the console application.
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct tr//�������Ķ���
{
	char data;
	struct tr *lchild;//����
	struct tr *rchild;//�Һ���
};
void creatree(struct tr *&k)//����������
{
	char c1, c2;
	c2 = '/';
	if (c2 != '\n')
	{
		scanf("%c%c", &c1, &c2);
		if (c1 == '*')
		{
			k = NULL;
		}
		else
		{
			k = (struct tr *)malloc(sizeof(struct tr));
			if (k == NULL)
			{
				exit(0);
			}
			k->data = c1;
			creatree(k->lchild);
			creatree(k->rchild);
		}
	}
	return;
}
void pretree(struct tr *k)//�������
{
	if (k == NULL)//����
	{
		return;
	}
	else
	{
		printf("%c ", k->data);//��
		pretree(k->lchild);//��
		pretree(k->rchild);//��
	}
	return;
}
void intree(struct tr *k)//�������
{
	if (k == NULL)//����
	{
		return;
	}
	else
	{
		intree(k->lchild);//��
		printf("%c ", k->data);//��
		intree(k->rchild);//��
	}
	return;
}
void posttree(struct tr *k)//�������
{
	if (k == NULL)//����
	{
		return;
	}
	else
	{
		posttree(k->lchild);//��
		posttree(k->rchild);//��
		printf("%c ", k->data);//��
	}
	return;
}
int treedepth(struct tr *k, int a, int b)//�������
{
	if (k == NULL)
	{
		return -1;
	}
	else
	{
		if (k->lchild != NULL)
		{
			a = treedepth(k->lchild, a, b) + 1;
		}
		if (k->rchild != NULL)
		{
			b = treedepth(k->rchild, a, b) + 1;
		}
		if (a >= b)
		{
			return(a + 1);
		}
		else
		{
			return(b + 1);
		}
	}
}
void leveltree(struct tr *k, int a)//��α���
{
	if (k == NULL || a < 0)
	{
		return;
	}
	if (a == 0)
	{
		printf("%c ", k->data);
	}
	leveltree(k->lchild, a - 1);
	leveltree(k->rchild, a - 1);
	return;
}
int main()
{
	int a = 0, b = 0;
	int depth = 0,i = 0;
	struct tr *k;
	creatree(k);
	pretree(k);
	printf("\n");
	intree(k);
	printf("\n");
	posttree(k);
	printf("\n");
	depth = treedepth(k, a, b);
	if (depth == 0)
		depth++;
	for (i = 0; i < depth; i++)
	{
		leveltree(k, i);
	}
	return 0;
}



