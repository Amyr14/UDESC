
#include <stdio.h>

int tipo_triangulo(float x, float y, float z);

int main(){
	float x, y, z;
	scanf("%f %f %f", &x, &y, &z);
	printf("%d", tipo_triangulo(x, y, z));
	return 0;
}

int tipo_triangulo(float x, float y, float z){
	if (x + y <= z || x + z <= y || z + y <= x)
		return 0;
	if (x == y && y == z)
		return 1;
	if (x == y && x != z || x == z && x != y || y == z && y != x)
		return 2;
	if (x != y && x != z && y != z)
		return 3;
		
	return -1;
}
