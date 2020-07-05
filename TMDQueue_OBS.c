#include "TMDQueue_OBS.h"
#include "NotificationHandle.h"

static void initRelations(TMDQueue_OBS* const me);
static void cleanUpRelations(TMDQueue_OBS* const me);

void TMDQueue_OBS_Init(TMDQueue_OBS* const me){
    me->head = 0;
    me->nSubcribers = 0;
    me->size = 0;
    me->itsNotificationHandle = NULL;
    initRelations(me);
}

void TMDQueue_OBS_Cleanup(TMDQueue_OBS* const me){
    cleanUpRelations(me);
}

int TMDQueue_OBS_getNextIndex(TMDQueue_OBS* const me,int index){
    /* this operation computes th next index from the
     * first using moduo arithmetic
    */
    return (index + 1) % QUEUE_SIZE;
}

void TMDQueue_OBS_insert(TMDQueue_OBS* const me,const struct TimeMarkedData tmd){
    /* note that because we never 'remove' data from this
     * leaky queue. size only increases to the queue size and
     * then stops increasing. Insertion always takes place at the end.
    */
    printf("Indenting at:%d Data#:%d",me->head,tmd.timeInterval);
    me->buffer[me->head] = tmd;
    me->head = TMDQueue_OBS_getNextIndex(me,me->head);
    if(me->size < QUEUE_SIZE) ++me->size;
    printf("Storing data value:%d\n",tmd.dataValue);
    TMDQueue_OBS_notify(me,tmd);
}

boolean TMDQueue_OBS_isEmpty(TMDQueue_OBS* const me){
    return (boolean)(me->size == 0);
}

void TMDQueue_OBS_notify(TMDQueue_OBS* const me,const struct TimeMarkedData tmd){
    NotificationHandle* pNH;
    pNH = me->itsNotificationHandle;
    while(pNH){
        printf("----->> calling updateAddr on pNH %d\n",pNH);
        pNH->updateAddr(NULL,tmd); // 执行该通知句柄对应的通知函数
        pNH = pNH->itsNotificationHandle; // 指向下一个通知句柄
    };
}

struct TimeMarkedData TMDQueue_OBS_remove(TMDQueue_OBS* const me,int index){
    TimeMarkedData tmd;
    tmd.timeInterval = -1; /* sentinel values */
    tmd.dataValue = -9999;

    if(!TMDQueue_OBS_isEmpty(me) && \
            (index >= 0) && \
            (index < QUEUE_SIZE) && \
            (index < me->size)){
        tmd = me->buffer[index];
    }
    return tmd;
}

int TMDQueue_OBS_subscribe(TMDQueue_OBS* const me,const UpdateFuncPtr updateFuncAddr){
    struct NotificationHandle *pNH;
    pNH = me->itsNotificationHandle;

    if(!pNH){ /* enmpty list? */
        /* create a new Notification Handle, initialize, and point to it */
        printf("----->Added to a new list\n");
        me->itsNotificationHandle = NotificationHandle_Create();
        printf("----->Called NH_Create()\n");
        pNH = me->itsNotificationHandle;
    }else{
        /* search list to find end */
        printf("----->Adding to an exiting list\n");
        while(pNH->itsNotificationHandle != NULL){
            printf("Getting ready to augment ptr %d\n",pNH,pNH->itsNotificationHandle);
            pNH = pNH->itsNotificationHandle; /* get next element in list */
            printf("----->augmenting ptr\n");
        }; /* end while */
        printf("----->calling NH_Create()\n");
        me->itsNotificationHandle = NotificationHandle_Create();
        pNH = me->itsNotificationHandle; /* pt to the new instance */
        printf("----->called NH_Create()\n");
    } /* end if */

    /* pNH now ponits to an constructed Notificaton Handle */
    pNH->updateAddr = updateFuncAddr; /* set callback address */
    ++me->nSubcribers;
    printf("----->wrote updateAddr \n");
    if(pNH->itsNotificationHandle)
        pritnf("xxxxxxx> next Ptr not null!\n\n");
    else
        printf("-----> next ptr null\n\n");
}

int TMDQueue_OBS_unsubscribe(TMDQueue_OBS* const me,const UpdateFuncPtr updateFuncAddr){
    struct NotificationHandle *pNH, *pBack;
    pNH = pBack = me->itsNotificationHandle;

    if(pNH == NULL){ /* empty list? */
        return 0; /* can't delete it from an empty list */
    }else{ /* it is the first one? */
        if(pNH->updateAddr == updateFuncAddr){
            me->itsNotificationHandle = pNH->itsNotificationHandle;
            free(pNH);
            printf(">>>>>> Removing the first element\n");
            --me->nSubcribers;
            return 1;
        }else{ /* search list to find element */
            printf(">>>>>> Searching...\n");
            while(pNH != NULL){
                if(pNH->updateAddr == updateFuncAddr){
                    pBack->itsNotificationHandle = pNH->itsNotificationHandle;
                    free(pNH);
                    printf(">>>>>> Removing subcriber in list\n");
                    --me->nSubcribers;
                    return 1;
                }; /* end if found */

                pBack = pNH; /* points to the list element before pNH */
                pNH = pNH->itsNotificationHandle; /* get next element in list */
            }; /* end while */
        }; /* end else */
        printf(">>>>>> Didn't remove any subscribers\n");
        return 0;
    }; /* non-empty list */
}

int TMDQueue_OBS_getBuffer(TMDQueue_OBS* const me){
    int iter = 0;
    return iter;
}

struct NotificationHandle* TMDQueue_OBS_getItsNotificationHandle(TMDQueue_OBS* const me){

}

void TMDQueue_OBS_getItsNotificationHandle(
       MDQueue_OBS* const me,struct NotificationHandle* p_NotificationHandle){

}

TMDQueue * TMDQueue_OBS_Create(void);
void TMDQueue_OBS_Destroy(TMDQueue_OBS* const me);

