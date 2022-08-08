#ifndef SVECTOR_H
#define SVECTOR_H

#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

#define	DEFAULT_CAPACITY	12
#define	NOT_FOUND			((size_t)(-1))

typedef int DATATYPE;

typedef struct tagVector
{
	DATATYPE* mp;
	size_t msize;
	size_t mcap;
}Vector, *HVector;


HVector create_vector(void);
HVector create_vector_with_capacity(size_t cap);
HVector create_vector_with_array(const DATATYPE *pa, size_t size);
HVector create_filled_vector(DATATYPE val, size_t size);
void destroy_vector(HVector);

bool set_capacity(HVector, size_t newcap);
bool push_back(HVector, DATATYPE val);
bool pop_back(HVector);
bool insert(HVector, size_t idx, DATATYPE val);
bool erase(HVector, size_t idx);
bool erase_val(HVector, DATATYPE val);
bool erase_val_all(HVector, DATATYPE val);
void clear(HVector);
size_t find(HVector, DATATYPE val);
bool isempty(HVector hvec);
void shrink(HVector);
void print_vector(HVector);

//functional macros
#define	get_size(hvec)			((hvec)->msize)
#define	get_cap(hvec)			((hvec)->mcap)  
#define	get_item(hvec, idx)		((hvec)->mp[idx])  

#endif