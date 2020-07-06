// 具备观察者模式的时间戳队列
#ifndef TMDQUEUE_OBS_H
#define TMDQUEUE_OBS_H

#include <stdio.h>
#include "ECGPkg.h"
#include "TimeMarkedData.h"

struct NotificationHandle;

typedef struct TMDQueue_OBS TMDQueue_OBS;
/*
This queue is meant to operate as a "leaky渗透" queue. In this queue,data are never removed perse,
but are instead overwritten when the buffer pointer wraps around.This allows for many
client to read the same from queue.
*/
struct TMDQueue_OBS{
    int head;
    int nSubcribers; // 订阅者
    int size;
    struct TimeMarkedData buffer[QUEUE_SIZE];
    struct NotificationHandle* itsNotificationHandle;
};

/* Constructor and destructor */
void TMDQueue_OBS_Init(TMDQueue_OBS* const me);
void TMDQueue_OBS_Cleanup(TMDQueue_OBS* const me);

/* Operations */
int TMDQueue_OBS_getNextIndex(TMDQueue_OBS* const me,int index);
void TMDQueue_OBS_insert(TMDQueue_OBS* const me,const struct TimeMarkedData tmd);
boolean TMDQueue_OBS_isEmpty(TMDQueue_OBS* const me);
void TMDQueue_OBS_notify(TMDQueue_OBS* const me,const struct TimeMarkedData tmd);
struct TimeMarkedData TMDQueue_OBS_remove(TMDQueue_OBS* const me,int index);

/* The NotificationHandle is managed as a linked list,
 *  with insertions coming at the end.
*/
int TMDQueue_OBS_subscribe(TMDQueue_OBS* const me,const UpdateFuncPtr updateFuncAddr);
int TMDQueue_OBS_unsubscribe(TMDQueue_OBS* const me,const UpdateFuncPtr updateFuncAddr);

int TMDQueue_OBS_getBuffer(TMDQueue_OBS* const me);

struct NotificationHandle* TMDQueue_OBS_getItsNotificationHandle(TMDQueue_OBS* const me);

void TMDQueue_OBS_setItsNotificationHandle(
       TMDQueue_OBS* const me,struct NotificationHandle* p_NotificationHandle);

TMDQueue_OBS * TMDQueue_OBS_Create(void);
void TMDQueue_OBS_Destroy(TMDQueue_OBS* const me);

#endif // TMDQUEUE_OBS_H
