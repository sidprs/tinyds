
#include<stdio.h>
#include<stdlib.h>



// Pre-allocate large chunk
typedef struct {
    char pool[1000000];
    size_t offset;
} MemoryPool;

void* pool_alloc(MemoryPool *p, size_t size) {
    if (p->offset + size > sizeof(p->pool))
        return NULL;
    void *ptr = p->pool + p->offset;
    p->offset += size;
    return ptr;
}

// Fast, no fragmentation, but can't free individual allocations


int main(){
  
  printf("hello");
  MemoryPool* p = malloc(sizeof(MemoryPool) * 5);


  return 0;
}
