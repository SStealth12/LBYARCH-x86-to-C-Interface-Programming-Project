#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define ARRAY_SIZE 32768 // Vector Size
#define SDOT_SIZE 2
#define ITERATIONS 30

extern double dotProduct(double* X, double* Y, int size);

double dotProductC(double* X, double* Y, int size) {
	int i;
	double sdot = 0.0;

	for (i = 0; i < size; i++) {
		sdot += X[i] * Y[i];
	}

	return sdot;
}

int main() {
	int i;
	double C_avg = 0.0, ASM_avg= 0.0;
	srand(time(0));
	for (i = 0; i < ITERATIONS; i++) {
		double X[ARRAY_SIZE]; // Vector X
		double Y[ARRAY_SIZE]; // Vector Y
		double sdot[SDOT_SIZE] = { 0.0,0.0 }; // Dot Product. Index 0 contains C output; Index 1 contains ASM output
		int j;

		// Random Variable Initialization for X and Y
		for (j = 0; j < ARRAY_SIZE; j++) {
			X[j] = (double)rand() / RAND_MAX * 10000000000000000000;
			Y[j] = (double)rand() / RAND_MAX * 10000000000000000000;
		}

		LARGE_INTEGER frequency;        // ticks per second
		LARGE_INTEGER t1, t2;           // ticks
		double elapsedTime;

		// get ticks per second
		QueryPerformanceFrequency(&frequency);

		// start timer
		QueryPerformanceCounter(&t1);
		sdot[0] = dotProductC(X, Y, ARRAY_SIZE);
		// stop timer
		QueryPerformanceCounter(&t2);

		// compute and print the elapsed time in 
		elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
		printf("Iteration %d\n", i+1);
		printf("[C Output] Dot Product = %f\n", sdot[0]);
		printf("[C Output] Running Time = %f ms\n\n", elapsedTime);

		C_avg += elapsedTime;

		// start timer
		QueryPerformanceCounter(&t1);
		sdot[1] = dotProduct(X, Y, ARRAY_SIZE);
		// stop timer
		QueryPerformanceCounter(&t2);

		// compute and print the elapsed time in millisec
		elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
		printf("[ASM Output] Dot Product = %f\n", sdot[1]);
		printf("[ASM Output] Running Time = %f ms\n\n", elapsedTime);

		ASM_avg += elapsedTime;

	}
	C_avg /= ITERATIONS;
	ASM_avg /= ITERATIONS;

	printf("\n\n");
	printf("[C] Average Running Time: %f ms\n", C_avg);
	printf("[ASM] Average Running Time: %f ms\n", ASM_avg);
	

	return 0;
}