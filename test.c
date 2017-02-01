# include <stdlib.h>
# include <stdio.h>

void	perlin(int *p);

int main(void)
{
	int *i;
	i = (int *)malloc(sizeof(int) * 1000);
	perlin(i);
	free(i);
	return (0);
}
