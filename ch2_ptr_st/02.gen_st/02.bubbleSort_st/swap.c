#include <stdlib.h>
#include <string.h>

int swap(void *dest, void *src, int size)
{
	void * t;

	if((t = malloc(size)) == NULL) return -1;
	memcpy(t, dest, size);
	memcpy(dest, src, size);
	memcpy(src, t, size);
	free(t);
}
