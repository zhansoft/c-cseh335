#include "bitops.h"

/*
 * Return and of x and y
 * Points: 5
 */
int and_op(int x, int y) {
  return x&y;
}

/* 
 * Return or of x and y
 * Points: 5
 */
int or_op(int x, int y) {
  return x|y;
}

/*
 * Return xor of x and y
 * Points: 5
 */
int xor_op(int x, int y) {
  return x^y;
}


/*
 * Extract `b`th byte of x
 * Points: 10
 */
int masking_and(int x, int b) {
	if(x < 0){
		return 0;
	}
	int size = sizeof(x);
	//00ff0000 inverse = ff00ffff inverses it
  	unsigned int mask = ~(0xff << 8*(32-b));
  	return x&mask;
}

/*
 * Set `b`th byte of x
 * Points: 10
 */
int masking_or(int x, int b) {
	int size = sizeof(x);
	unsigned int mask = (0xff << 8*(32-b));
	return x|mask;
}

/*
 * Toggle `b`th byte of x
 * Points: 10
 */
int masking_xor(int x, int b) {
	int size = sizeof(x);
	unsigned int mask = (0xff << 8*(size-b));
	return x^mask;
}

/*
 * Shift x to the left by `sc` # of bits
 * Points: 5
 */
int shifting_left_op(int x, int sc) {
  	unsigned int c = (x << sc) | (x >> (32 -sc));
	return c;
}

/*
 * Shift x to the right by `sc` # of bits
 * Points: 5
 */
int shifting_right_op(int x, int sc) {
 	unsigned int c = (x >> sc) | (x << (32 - sc));
	return x >> sc;
}


/*
 * Return logical not of x
 * Points: 5
 */
int bang(int x) {
  return !x;
}

/*
 * Print binary string representation for x
 * Points: 40
 */
void bit_conversion(int x) {
	int i;
	int a[10];
	for(i = 0; x > 0; i++){
		a[i] = x % 2;
		x = x / 2;
	}
	for(i = i - 1; i >= 0; i--){
		printf("%d", a[i]);
	}
}
