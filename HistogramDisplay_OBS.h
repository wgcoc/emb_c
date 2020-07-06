#ifndef HISTOGRAMDISPLAY_OBS_H
#define HISTOGRAMDISPLAY_OBS_H
#include "TimeMarkedData.h"
#include "TMDQueue_OBS.h"

/* class HistogramDisplay_OBS */
typedef struct HistogramDisplay_OBS HistogramDisplay_OBS;
struct HistogramDisplay_OBS{
    int index; // 注意：负责维护该类在队列（itsTMDQueue_OBS）中的数据访问位置，不会影响到其他类对同一队列的数据访问
    struct TMDQueue_OBS* itsTMDQueue_OBS;
};


/* Constructor and destructor */
void HistogramDisplay_OBS_Init(HistogramDisplay_OBS* const me);
void HistogramDisplay_OBS_Cleanup(HistogramDisplay_OBS* const me);

/* Operations */
void HistogramDisplay_OBS_update(HistogramDisplay_OBS* const me,const struct TimeMarkedData tmd);
void HistogramDisplay_OBS_updateHistogram(HistogramDisplay_OBS* const me);

struct TMDQueue_OBS* HistogramDisplay_OBS_getItsTMDQueue_OBS(const HistogramDisplay_OBS* const me);
void HistogramDisplay_OBS_setItsTMDQueue_OBS(HistogramDisplay_OBS* const me,struct TMDQueue_OBS* p_TMDQueue_OBS);

HistogramDisplay_OBS * HistogramDisplay_OBS_Create(void);
void HistogramDisplay_OBS_Destroy(HistogramDisplay_OBS* const me);



#endif // HISTOGRAMDISPLAY_OBS_H
