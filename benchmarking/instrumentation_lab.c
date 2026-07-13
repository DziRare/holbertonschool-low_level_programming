#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
	*state = (*state * 1103515245u) + 12345u;
	return *state;
}

static void build_dataset(void)
{
	unsigned int state;
	int i;

	state = SEED_VALUE;

	for (i = 0; i < DATASET_SIZE; i++)
	dataset[i] = (int)(next_value(&state) % 100000);
}

static void process_dataset(void)
{
	int i;
	int v;

	for (i = 0; i < DATASET_SIZE; i++)
	{
		v = dataset[i];
		v = (v * 3) + (v / 7) - (v % 11);
		if (v < 0)
			v = -v;
		dataset[i] = v;
    }
}

static unsigned long reduce_checksum(void)
{
	unsigned long sum;
	int i;

	sum = 0;
	for (i = 0; i < DATASET_SIZE; i++)
		sum = (sum * 131ul) + (unsigned long)dataset[i];

	return sum;
}

int main(void)
{
	unsigned long checksum;
	clock_t total_time;
	clock_t build_time;
	clock_t process_time;
	clock_t reduce_time;

	/* Students must add clock-based timing and print required lines. */
	
	total_time = clock();

	build_time = clock();
	build_dataset();
	build_time = clock() - build_time;

	process_time = clock();
	process_dataset();
	process_time = clock() - process_time;

	reduce_time = clock();
	checksum = reduce_checksum();
	reduce_time = clock() - reduce_time;

	total_time = clock() - total_time;

	if (checksum == 0ul)
		printf("impossible\n");

	/* Required output (exact format, no extra lines):
	* TOTAL seconds: <float>
	* BUILD_DATA seconds: <float>
	* PROCESS seconds: <float>
	* REDUCE seconds: <float>
	*/

	printf("TOTAL seconds: %.6f\n", (float)total_time / CLOCKS_PER_SEC);
	printf("BUILD_DATA seconds: %6.f\n", (float)build_time / CLOCKS_PER_SEC);
	printf("PROCESS seconds: %6.f\n", (float)process_time / CLOCKS_PER_SEC);
	printf("REDUCE seconds: %6.f\n", (float)reduce_time / CLOCKS_PER_SEC);

	return 0;
}

