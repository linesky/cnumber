#include <stdio.h>
#include <stdlib.h>
struct group{
	int group_[1000];
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
		printf("%d",(int)g1->group_[n]);
		if (n!=g1->count-1)printf(" , ");
	}
	printf("\n");
}

int main(){
	int n;
	double d[]={-2,-1,0,1,2};
	struct group g1;
	struct group negative;
	struct group positive;
	struct group *gg1;
	gg1=&g1;
	gg1->count=0;
	for(n=0;n<5;n++)add_(gg1,d[n]);
	printf("\ngroup : ");
	print(gg1);
	for(n=0;n<gg1->count;n++){
		if(gg1->group_[n]< 0){
			add_(&negative,gg1->group_[n]);
		}else{
			add_(&positive,gg1->group_[n]);
		}
	}
	printf("\npositive : ");
	print(&positive);
	printf("\nnegative : ");
	print(&negative);

}
