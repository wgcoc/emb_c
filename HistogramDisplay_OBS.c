#include "HistogramDisplay_OBS.h"

static void cleanUpRelatins(HistogramDisplay_OBS* const me);

void HistogramDisplay_OBS_Init(HistogramDisplay_OBS* const me){
    me->itsTMDQueue_OBS = NULL;
    /* call subscribe to connect to the server */
    TMDQueue_OBS_subscribe(me->itsTMDQueue_OBS,
                           HistogramDisplay_OBS_update);
}

void HistogramDisplay_OBS_Cleanup(HistogramDisplay_OBS* const me){
    /* remove yourself from server subscribe list */
    TMDQueue_OBS_unsubscribe(me->itsTMDQueue_OBS,
                             HistogramDisplay_OBS_update);
}


void HistogramDisplay_OBS_update(HistogramDisplay_OBS* const me,const struct TimeMarkedData tmd){
    printf(" Histogram -> TimeInterval: %d DataValue: %d\n",tmd.timeInterval,tmd.dataValue);
}

void HistogramDisplay_OBS_updateHistogram(HistogramDisplay_OBS* const me){

}

struct TMDQueue_OBS* HistogramDisplay_OBS_getItsTMDQueue_OBS(const HistogramDisplay_OBS* const me){
    return (struct TMDQueue_OBS*)me->itsTMDQueue_OBS;
}

void HistogramDisplay_OBS_setItsTMDQueue_OBS(HistogramDisplay_OBS* const me,struct TMDQueue_OBS* p_TMDQueue_OBS){
    me->itsTMDQueue_OBS = p_TMDQueue_OBS;
}

HistogramDisplay_OBS * HistogramDisplay_OBS_Create(void){

}

void HistogramDisplay_OBS_Destroy(HistogramDisplay_OBS* const me){

}

static void cleanUpRelatins(HistogramDisplay_OBS* const me){
    if(me->itsTMDQueue_OBS != NULL){
        me->itsTMDQueue_OBS = NULL;
    }
}




