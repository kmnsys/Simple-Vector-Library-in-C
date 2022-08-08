#include "svector.h"
#include <stdlib.h>
#include <string.h>

HVector create_vector(void) {
	return create_vector_with_capacity(DEFAULT_CAPACITY);
}

HVector create_vector_with_capacity(size_t cap) {
	HVector hvec = (HVector)malloc(sizeof(Vector));

	if (!hvec) {
		fprintf(stderr, "bellek yetersiz");
		return hvec;
	}

	hvec->msize = 0;
	hvec->mcap = cap;
	hvec->mp = (DATATYPE*)malloc(cap * sizeof(DATATYPE));
	if (!hvec->mp) {
		free(hvec);
		fprintf(stderr, "bellek yetersiz");
		return NULL;
	}

	return hvec;
}

HVector create_vector_with_array(const DATATYPE* pa, size_t size) {
	HVector hvec = create_vector_with_capacity(size);
	if (!hvec) {
		return hvec;
	}

	hvec->msize = size;
	memmove(hvec->mp, pa,size * sizeof(DATATYPE));

	return hvec;
}

HVector create_filled_vector(DATATYPE val, size_t size) {
	HVector hvec = create_vector_with_capacity(size);

	if (!hvec) {
		return hvec;
	}

	hvec->msize = size;

	while (size--)
	{
		hvec->mp[size] = val;
	}

	return hvec;
}

void destroy_vector(HVector hvec) {
	free(hvec -> mp);
	free(hvec);
}

bool set_capacity(HVector hvec, size_t newcap) {
	if (newcap < hvec->msize)
		return false;
	if (newcap == hvec->mcap)
		return true;
	
	DATATYPE* pbuf = (DATATYPE*)realloc(hvec->mp, newcap * sizeof(DATATYPE));
	if (!pbuf)
		return false;
	hvec->mcap = newcap;
	hvec->mp = pbuf;

	return true;
}

bool push_back(HVector hvec, DATATYPE val) {
	if (hvec->msize == hvec->mcap && !set_capacity(hvec, hvec->mcap * 2)) {
		return false;
	}

	hvec->mp[hvec->msize++] = val;
	return true;
}

bool pop_back(HVector hvec) {
	if (hvec->msize == 0)
		return false;

	--hvec->msize;

	return true;
}

bool insert(HVector hvec, size_t idx, DATATYPE val) {
	if (idx > hvec->msize)
		return false;
	if (hvec->msize == hvec->mcap && !set_capacity(hvec, hvec->mcap * 2)) {
		return false;
	}
	memmove(hvec->mp + idx + 1, hvec->mp + idx, (hvec->msize - idx) * sizeof(DATATYPE));
	hvec->mp[idx] = val;
	++hvec->msize;
	return true;

}

bool erase(HVector hvec, size_t idx) {
	if (idx < 0 || idx >= hvec->msize)
		return false;
	 
	memmove(hvec->mp + idx, hvec->mp + idx + 1, (hvec->msize - idx - 1) * sizeof(DATATYPE));
	--hvec->msize;

	return true;
}

bool erase_val(HVector hvec, DATATYPE val) {
	for (int i = 0; i < hvec->msize; ++i) {
		if ((hvec->mp[i]) == val) {
			erase(hvec, i);
			return true;
		}
	}
	return false;
}

bool erase_val_all(HVector hvec, DATATYPE val) {
	int flag = 0;
	int flag_ret = 0;
	int cnt = 0;

	//while (flag = !flag ? flag_ret : flag, flag_ret = erase_val(hvec, val))
	while (erase_val(hvec, val))
		cnt++;

	return cnt ? true : false;
}

void clear(HVector hvec) {
	hvec->msize = 0;
}

size_t find(HVector hvec, DATATYPE val) {
	for (size_t i = 0; i < hvec->msize; ++i) {
		if (hvec->mp[i] == val)
			return i;
	}
	
	return NOT_FOUND;
}

bool isempty(HVector hvec) {
	return hvec->msize == 0;
}

void shrink(HVector hvec) {
	hvec->mp = (DATATYPE*)realloc(hvec->mp, sizeof(DATATYPE) * hvec->msize);
	hvec->mcap = hvec->msize;
}

void print_vector(HVector hvec) {

	for (size_t i = 0; i < get_size(hvec); ++i) {
		printf("%d ", get_item(hvec, i));
	}
	printf("\n");
}
