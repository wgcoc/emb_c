#include "NotificationHandle.h"

static void cleanUpRelations(NotificationHandle* const me);

/* Constructor and destructor */
void NotificationHandle_Init(NotificationHandle* const me){
    me->itsNotificationHandle = NULL;
}
void NotificationHandle_Cleanup(NotificationHandle* const me){
    cleanUpRelations(me);
}

/* Operations */
struct NotificationHandle* NotificationHandle_getItsNotificationHandle(
        const NotificationHandle* const me){
    return (struct NotificationHandle*)me->itsNotificationHandle;
}

void NotificationHandle_setItsNotificationHandle(
        NotificationHandle* const me,
        struct NotificationHandle* p_NotificationHandle){
    me->itsNotificationHandle = p_NotificationHandle;
}

NotificationHandle * NotificationHandle_Create(void){

}

void NotificationHandle_Destroy(NotificationHandle* const me){

}

static void cleanUpRelations(NotificationHandle* const me){
    if(me->itsNotificationHandle != NULL){
        me->itsNotificationHandle = NULL;
    }
}
