#include <stdio.h>

int main(){
	int i;
	i=0;
	char c;
	
	printf("%d\n", ++i);
	printf("%d\n", i);
	c=getch();
	//c='A';
	printf("%c\n", tolower(c));
	
	getchar();
	return 0;	
}
