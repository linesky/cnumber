#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct group{
	double group_[1000];
	int count;
};

char add_(struct group *g1,double f){
	if(g1->count<999){
		g1->group_[g1->count]=f;
		g1->count++;
	}
}
void print(struct group *g1){
	int n;
	for (n=0;n<g1->count;n++){
		printf("%f",g1->group_[n]);
		if (n!=g1->count-1)printf(" , ");
	}
	printf("\n");
}
double max(struct group *g1){
	double d;
	double dd;
	int n;
	d=g1->group_[0];
	for (n=0;n<g1->count;n++){
		if(g1->group_[n]>d)d=g1->group_[n];
	}
	return d;
}
double min(struct group *g1){
	double d;
	double dd;
	int n;
	d=g1->group_[0];
	for (n=0;n<g1->count;n++){
		if(g1->group_[n]<d)d=g1->group_[n];
	}
	return d;
}
double med(struct group *g1){
	double d;
	double dd;
	int n;
	d=0;
	for (n=0;n<g1->count;n++){
		d=d+g1->group_[n];
	}
	if (g1->count> 0)d=d/g1->count;
	return d;
}

int main(){
	int n;
	double ff;
	double d[]={-1,-18.8D,17.9,8,8.2};
	struct group g1;
	struct group *gg1;
	gg1=&g1;
	gg1->count=0;
	for(n=0;n<5;n++)add_(gg1,d[n]);
	printf("\ngroup : ");
	print(gg1);
	printf("max : %f\n",max(gg1));
	printf("min : %f\n",min(gg1));
	printf("med : %f\n",med(gg1));
}
