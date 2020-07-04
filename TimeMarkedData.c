#include "TimeMarkedData.h"
#include "TMDQueue.h"

/* Constructor and destructor */
void TimeMarkedData_Init(TimeMarkedData* const me){
    me->timeInterval = 0;
    me->dataValue = 0;
}

void TimeMarkedData_Cleanup(TimeMarkedData* const me){

}

/* Operations */
void TimeMarkedData_setItsTMDQueue(TimeMarkedData* me,struct TMDQueue* p_TMDQueue){
}

TimeMarkedData * TimeMarkedData_Create(void){

}
void TimeMarkedData_Destroy(TimeMarkedData* const me){

}

