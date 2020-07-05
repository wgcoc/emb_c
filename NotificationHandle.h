#ifndef NOTIFICATIONHANDLE_H
#define NOTIFICATIONHANDLE_H

#include "stdio.h"
#include "ECGPkg.h"

typedef void (*UpdateFuncPtr)(int instanceNum,int value);

typedef struct NotificationHandle NotificationHandle;
struct NotificationHandle{
    UpdateFuncPtr updateAddr;
    struct NotificationHandle* itsNotificationHandle;
};

/* Constructor and destructor */
void NotificationHandle_Init(NotificationHandle* const me);
void NotificationHandle_Cleanup(NotificationHandle* const me);

/* Operations */
struct NotificationHandle* NotificationHandle_getItsNotificationHandle(
        const NotificationHandle* const me);

void NotificationHandle_setItsNotificationHandle(
        NotificationHandle* const me,
        struct NotificationHandle* p_NotificationHandle);

NotificationHandle * NotificationHandle_Create(void);
void NotificationHandle_Destroy(NotificationHandle* const me);

#endif // NOTIFICATIONHANDLE_H