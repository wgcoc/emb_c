/*
 * Subject.h
 *
 *  Created on: 2019��5��15��
 *      Author: Administrator
 */

#ifndef SRC_SUBJECT_H_
#define SRC_SUBJECT_H_

#include "List.h"
#include "Observer.h"

typedef struct _Subject Subject;
typedef struct _Subject* SubjectPtr;
struct _Subject
{
	int val;
	struct list_head list;
	void (*add)(SubjectPtr sp, ObserverPtr op);
	void (*remove)(SubjectPtr sp, ObserverPtr op);
	void (*notify)(SubjectPtr sp);
	void (*changeEvent)(SubjectPtr sp, int code);
};

void Subject_Init(SubjectPtr sp);

#endif /* SRC_SUBJECT_H_ */
