#ifndef HISTOGRAMDISPLAY_H
#define HISTOGRAMDISPLAY_H
#include <stdio.h>
#include "ECGPkg.h"
struct TMDQueue;

/* class HistogramDisplay */
typedef struct HistogramDisplay HistogramDisplay;
struct HistogramDisplay{
    int index; // 注意：负责维护该类在队列（itsTMDQueue）中的数据访问位置，不会影响到其他类对同一队列的数据访问
    struct TMDQueue* itsTMDQueue;
};


/* Constructor and destructor */
void HistogramDisplay_Init(HistogramDisplay* const me);
void HistogramDisplay_Cleanup(HistogramDisplay* const me);

/* Operations */
void HistogramDisplay_getValue(HistogramDisplay* const me);
void HistogramDisplay_updateHistogram(HistogramDisplay* const me);

struct TMDQueue* HistogramDisplay_getItsTMDQueue(const HistogramDisplay* const me);
void HistogramDisplay_setItsTMDQueue(HistogramDisplay* const me,struct TMDQueue* p_TMDQueue);

HistogramDisplay * HistogramDisplay_Create(void);
void HistogramDisplay_Destroy(HistogramDisplay* const me);

#endif // HISTOGRAMDISPLAY_H
