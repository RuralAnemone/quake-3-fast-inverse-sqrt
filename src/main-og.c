#include <math.h>
#include <stdio.h>

float Q_rsqrt(float number);

int main() {
	printf("should be close to 1:\n");
	printf("%f\n", Q_rsqrt(1));

	printf("should be close to 0.5:\n");
	printf("%f\n", Q_rsqrt(4));
	// idk

}

float Q_rsqrt(float number) {
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5;
	y = number;
	i = * (long *) &y;						// evil floating point bit hack
	i = 0x5f3759df - (i >> 1);				// what the fuck?
	y = * (float *) &i;
	y = y * (threehalfs - (x2 * y * y));	// 1st iteration
	// y = y * (threehalfs - (x2 * y * y));	// 2nd iteration, this can be removed

	return y;
}