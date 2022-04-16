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
	double d[]={-2,-1,0,1,2};
	struct group g1;
	struct group notpare;
	struct group pare;
	struct group *gg1;
	gg1=&g1;
	gg1->count=0;
	notpare.count=0;
	pare.count=0;
	for(n=0;n<5;n++)add_(gg1,d[n]);
	printf("\ngroup : ");
	print(gg1);
	for(n=0;n<gg1->count;n++){
		if(floor(gg1->group_[n]/2)*2==gg1->group_[n]){
			add_(&pare,gg1->group_[n]);
		}else{
			add_(&notpare,gg1->group_[n]);
		}
	}
	printf("\npare : ");
	print(&pare);
	printf("\nnot pare : ");
	print(&notpare);

}
