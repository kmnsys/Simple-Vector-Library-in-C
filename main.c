#include <stdio.h>
#include "svector.h"

void print_array(const int* pa, size_t size) {
	while (size--)
	{
		printf("%d ", *pa++);
	}
	printf("\n");
}

int main() {

	/*****************************************************************/
	printf("Test 1 - create_vector_with_capacity \n");

	HVector handle1 = create_vector_with_capacity(64);
	printf("Size: %zu\n", handle1->msize);
	printf("Capacity: %zu\n", handle1->mcap);


	/*****************************************************************/
	printf("\nTest 2 - create_vector \n");

	HVector handle2 = create_vector();
	printf("Size: %zu\n", handle2->msize);
	printf("Capacity: %zu\n", handle2->mcap);


	/*****************************************************************/
	printf("\nTest 3 - create_vector_with_array \n");

	const int a[10] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

	HVector handle3 = create_vector_with_array(a, 10);
	printf("Size: %zu\n", handle3->msize);
	printf("Capacity: %zu\n", handle3->mcap);
	print_array(a, 10);
	print_vector(handle3);
	printf("******************************************\n\n");


	/*****************************************************************/
	printf("\nTest 4 - create_filled_vector \n");

	HVector handle4 = create_filled_vector(5, 10);
	printf("Size: %zu\n", handle4->msize);
	printf("Capacity: %zu\n", handle4->mcap);
	print_vector(handle4);
	printf("******************************************\n\n");

	/*****************************************************************/
	printf("\nTest 5 - set_capacity \n");

	HVector handle5 = handle3;
	printf("Before Size: %zu\n", handle5->msize);
	printf("Before Capacity: %zu\n", handle5->mcap);
	print_vector(handle5);
	printf("******************************************\n\n");

	set_capacity(handle5, 11);
	printf("After Size: %zu\n", handle5->msize);
	printf("After Capacity: %zu\n", handle5->mcap);
	print_vector(handle5);
	printf("******************************************\n\n");

	/*****************************************************************/
	printf("\n------------Test 6 - push back------------\n");
	HVector handle6 = handle5;

	printf("Size before push: %zu\n", handle6->msize);
	printf("Capacity before push: %zu\n", handle6->mcap);
	printf("Array: ");
	print_vector(handle6);
	printf("******************************************\n\n");

	push_back(handle6, -1);
	printf("Size after first push: %zu\n", handle6->msize);
	printf("Capacity after first push: %zu\n", handle6->mcap);
	printf("Array: ");
	print_vector(handle6);
	printf("******************************************\n\n");

	push_back(handle6, -2);
	printf("Size after second push: %zu\n", handle6->msize);
	printf("Capacity after second push: %zu\n", handle6->mcap);
	printf("Array: ");
	print_vector(handle6);
	printf("******************************************\n\n");


	/*****************************************************************/
	printf("\n------------Test 7 - pop back------------\n");
	HVector handle7 = handle6;

	printf("Size before pop: %zu\n", handle7->msize);
	printf("Capacity before pop: %zu\n", handle7->mcap);
	printf("Array: ");
	print_vector(handle7);
	printf("******************************************\n\n");

	pop_back(handle7);
	printf("Size after first pop: %zu\n", handle7->msize);
	printf("Capacity after pop: %zu\n", handle7->mcap);
	printf("Array: ");
	print_vector(handle7);
	printf("******************************************\n\n");


	/*****************************************************************/
	printf("\n------------Test 8 - insert------------\n");
	HVector handle8 = handle7;

	printf("Size before insert: %zu\n", handle8->msize);
	printf("Capacity before insert: %zu\n", handle8->mcap);
	printf("Array: ");
	print_vector(handle8);
	printf("******************************************\n\n");

	if (insert(handle8, 3, -1)) {
		printf("Size after insert: %zu\n", handle8->msize);
		printf("Capacity after insert: %zu\n", handle8->mcap);
		printf("Array: ");
		print_vector(handle8);
		printf("******************************************\n\n");
	}
	else
		printf("FAILED!\n");

	/*****************************************************************/
	printf("\n------------Test 9 - erase idx------------\n");
	HVector handle9 = handle8;

	printf("Size before erase idx: %zu\n", handle9->msize);
	printf("Capacity before erase idx: %zu\n", handle9->mcap);
	printf("Array: ");
	print_vector(handle9);
	printf("******************************************\n\n");

	if (erase(handle9, 3)) {
		printf("Size after erase idx: %zu\n", handle9->msize);
		printf("Capacity after erase idx: %zu\n", handle9->mcap);
		printf("Array: ");
		print_vector(handle9);
		printf("******************************************\n\n");
	}
	else
		printf("FAILED!\n");


	/*****************************************************************/
	printf("\n------------Test 10 - erase val------------\n");
	HVector handle10 = handle9;

	printf("Size before erase val: %zu\n", handle10->msize);
	printf("Capacity before erase val: %zu\n", handle10->mcap);
	printf("Array: ");
	print_vector(handle10);
	printf("******************************************\n\n");

	if (erase_val(handle10, -1)) {
		printf("Size after erase val: %zu\n", handle10->msize);
		printf("Capacity after erase val: %zu\n", handle10->mcap);
		printf("Array: ");
		print_vector(handle10);
		printf("******************************************\n\n");
	}
	else
		printf("FAILED!\n");



	/*****************************************************************/
	printf("\n------------Test 11 - erase val all------------\n");
	HVector handle11 = handle10;

	printf("Size before erase val all: %zu\n", handle11->msize);
	printf("Capacity before erase val all: %zu\n", handle11->mcap);
	printf("Array: ");
	print_vector(handle11);
	printf("******************************************\n\n");

	if (erase_val_all(handle11, 1)) {
		printf("Size after erase val all: %zu\n", handle11->msize);
		printf("Capacity after erase val all: %zu\n", handle11->mcap);
		printf("Array: ");
		print_vector(handle11);
		printf("******************************************\n\n");
	}
	else
		printf("FAILED!\n");


	/*****************************************************************/
	printf("\n------------Test 12 - find ------------\n");
	HVector handle12 = handle11;

	printf("Size before find: %zu\n", handle12->msize);
	printf("Capacity before find: %zu\n", handle12->mcap);
	printf("Array: ");
	print_vector(handle12);
	printf("******************************************\n\n");

	int find_val = 55;
	size_t find_ret = find(handle12, find_val);
	if (find_ret  != NOT_FOUND) {
		printf("Size after find: %zu\n", handle12->msize);
		printf("Capacity after find: %zu\n", handle12->mcap);
		printf("%d FOUND! Index: %zu\n", find_val, find_ret);
		printf("Array: ");
		print_vector(handle12);
		printf("******************************************\n\n");
	}
	else
		printf("NOT FOUND!\n");


	/*****************************************************************/
	printf("\n------------Test 13 - shrink ------------\n");
	HVector handle13 = handle12;

	printf("Size before shrink: %zu\n", handle12->msize);
	printf("Capacity before find shrink: %zu\n", handle12->mcap);
	printf("******************************************\n\n");
	shrink(handle13);
	printf("Size after find: %zu\n", handle12->msize);
	printf("Capacity after find: %zu\n", handle12->mcap);


	
}