#include<stdio.h>
#include<stdlib.h>

struct polyNode{
	int coef;
	int exp;
	struct polyNode* next;
}