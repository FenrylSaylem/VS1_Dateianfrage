#include<stdio.h>
#include<stdlib.h>
#include<string.h>

# define MAX 100
/*
int schwap(int a, int b){
	int tmp=a;
	a=b;
	b=tmp;
};*/

int findePrim(int anzahlWerte){
	int index=0;
	int prim[anzahlWerte];
	for(int i=0;i<MAX;i++){
		
		int j=1;
		do{
			int m=i/j;
			if(m == '1' ){
				prim[index]=i;
				index++;
			}
			j++;
		}while(j<MAX || j == i);
		if(index == anzahlWerte){
			return *prim;
		}			
		}
	}
}

int main(int argc, char **argv)  {
	char ausgabe[MAX];
	int testwert=0;
//	printf("!");
	sscanf(argv[ausgabe+1],"%c",&testwert);
	*ausgabe=findePrim((int) testwert);
//	printf("%d",testwert);

	return *ausgabe;
}

/*
1
2
3
5
7
11
13
17
19
23
29
*/
