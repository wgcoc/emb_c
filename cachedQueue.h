#ifndef CACHEDQUEUE_H_
#define CACHEDQUEUE_H_

#include "queue.h"

typedef struct CachedQueue CachedQueue;
struct CachedQueue{
    Queue *queue; /* base class */
    /* new attributes */
    char filename[80];

    int numberElmentsOnDisk;
    /* aggregation in subclass */
    Queue *outputQueue;

    /* inherited virtual function */
    int (*isFull)(CachedQueue* const me);
    int (*isEmpty)(CachedQueue* const me);
    int (*getSize)(CachedQueue* const me);
    void (*insert)(CachedQueue* const me);
    int (*remove)(CachedQueue* const me);
    /* new virtual functions */
    void (*flush)(CachedQueue* const me);
    void (*load)(CachedQueue* const me);
};

/* Constructor and destructor */
void CachedQueue_Init( CachedQueue* const me,char *fname,
                      int (*isFullFunction)(CachedQueue* const me),
                      int (*isEmptyFunction)(CachedQueue* const me),
                      int (*getSizeFunction)(CachedQueue* const me),
                      void (*insertFunction)(CachedQueue* const me,int k),
                      int (*removeFunction)(CachedQueue* const me),
                      void (*flushFunction)(CachedQueue* const me),
                      void (*loadFunction)(CachedQueue* const me) );

void CachedQueue_Cleanup(CachedQueue* const me);

/* Operations */
int CachedQueue_isFull(CachedQueue* const me);
int CachedQueue_isEmpty(CachedQueue* const me);
int CachedQueue_getSize(CachedQueue* const me);
void CachedQueue_insert(CachedQueue* const me,int k);
int CachedQueue_remove(CachedQueue* const me);
void CachedQueue_flush(CachedQueue* const me);
void CachedQueue_load(CachedQueue* const me);

CachedQueue *  CachedQueue_Create(void);
void  CachedQueue_Destroy(CachedQueue* const me);
#endif // CACHEDQUEUE_H_

