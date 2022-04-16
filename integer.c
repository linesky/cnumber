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

int main(){
	int n;
	double ff;
	double d[]={-2.20D,-1.00D,0.00D,1.10D,2.00D};
	struct group g1;
	struct group notInteger;
	struct group Integers;
	struct group *gg1;
	gg1=&g1;
	gg1->count=0;
	notInteger.count=0;
	Integers.count=0;
	for(n=0;n<5;n++)add_(gg1,d[n]);
	printf("\ngroup : ");
	print(gg1);
	for(n=0;n<gg1->count;n++){
		ff=floor(gg1->group_[n]);
		if(ff==gg1->group_[n]){
			add_(&Integers,gg1->group_[n]);
		}else{
			add_(&notInteger,gg1->group_[n]);
		}
	}
	printf("\nInteger : ");
	print(&Integers);
	printf("\nnot Integer : ");
	print(&notInteger);

}
