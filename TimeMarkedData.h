#ifndef TIMEMARKEDDATA_H
#define TIMEMARKEDDATA_H

typedef TimeMarkedData TimeMarkedData;
struct TimeMarkedData{
    int timeInterval;
    int dataValue;
};

void TimeMarkedData_Init(TimeMarkedData* const me);
void TimeMarkedData_setItsTMDQueue(TimeMarkedData* pTmd,TMDQueue* const me);
void TimeMarkedData_Cleanup(TimeMarkedData* const me);

#endif // TIMEMARKEDDATA_H

