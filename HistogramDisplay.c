#include "HistogramDisplay.h"
#include "TMDQueue.h"

static void cleanUpRelation(HistogramDisplay* const me);

/* Constructor and destructor */
void HistogramDisplay_Init(HistogramDisplay* const me){
    me->index = 0;
    me->itsTMDQueue = NULL;
}

void HistogramDisplay_Cleanup(HistogramDisplay* const me){
    cleanUpRelation();
}

/* Operations getValue() */
void HistogramDisplay_getValue(HistogramDisplay* const me){
    TimeMarkedData tmd;
    tmd = TMDQueue_remove(me->itsTMDQueue,me->index);
    printf("Histogram index:%d TimeInterval:%d DataValue:%d\n",
           me->index,tmd.timeInterval,tmd.dataValue);
    me->index = TMDQueue_getNextIndex(me->itsTMDQueue,me->index);
}

void HistogramDisplay_updateHistogram(HistogramDisplay* const me){
    /* put som histogram stuff here... */
}

struct TMDQueue* HistogramDisplay_getItsTMDQueue(const HistogramDisplay* const me);
void HistogramDisplay_setItsTMDQueue(HistogramDisplay* const me,struct TMDQueue* p_TMDQueue);

HistogramDisplay * HistogramDisplay_Create(void);
void HistogramDisplay_Destroy(HistogramDisplay* const me);




