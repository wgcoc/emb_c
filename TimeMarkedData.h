#ifndef TIMEMARKEDDATA_H
#define TIMEMARKEDDATA_H
//#include "includes.h"

struct TMDQueue;

typedef struct TimeMarkedData TimeMarkedData;
struct TimeMarkedData{
    int timeInterval;
    int dataValue;
};

/* Constructor and destructor */
void TimeMarkedData_Init(TimeMarkedData* const me);

void TimeMarkedData_Cleanup(TimeMarkedData* const me);

/* Operations */
void TimeMarkedData_setItsTMDQueue(TimeMarkedData* me, struct TMDQueue* p_TMDQueue);

TimeMarkedData * TimeMarkedData_Create(void);
void TimeMarkedData_Destroy(TimeMarkedData* const me);

#endif // TIMEMARKEDDATA_H

