#include <stdio.h> 

int main() 
{
	int r = 4;
	bool s = (r == 9 ? r = 5 : r += 1);

	printf("%d\n", s);

	return(0);
}