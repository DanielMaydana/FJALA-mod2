#include <stdio.h> 

int main() 
{
	int r = 9;
	bool s = (r == 9 ? r = 5 : r += 1);

	printf("%d\n", r);

	return(0);
}