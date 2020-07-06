/*
 * Observer.h
 *
 *  Created on: 2019��5��15��
 *      Author: Administrator
 */

#ifndef SRC_OBSERVER_H_
#define SRC_OBSERVER_H_

#include <stdlib.h>
#include "List.h"

typedef void(*update_fun_ptr)(int val);

typedef struct
{
	update_fun_ptr update;
	struct list_head node;
}Observer, *ObserverPtr;

typedef struct
{
	Observer obs;
	/*
	 * �����Ǳ����������
	 */
}SheetObserver, *SheetObserverPtr;

typedef struct
{
    Observer obs;
	/*
	 * �����Ǳ����������
	 */
}ChartObserver, *ChartObserverPtr;

typedef struct
{
    Observer obs;
	/*
	 * �����Ǳ����������
	 */
}ScaleObserver, *ScaleObserverPtr;

void update_sheet(int val);
void update_chart(int val);
void update_scale(int val);
void Observer_Init(ObserverPtr op, update_fun_ptr fptr);

#endif /* SRC_OBSERVER_H_ */
