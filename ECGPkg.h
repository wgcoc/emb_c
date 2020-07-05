// 心电图
#ifndef ECGPKG_H
#define ECGPKG_H

#include <stdio.h>

typedef void (*UpdateFuncPtr)(int instanceNum,int value);

/* forward declarations */
struct ArrythmiaDetector; // 心律失常检测器
struct ECG_Module;
struct HistogramDisplay; // 直方图显示
struct QRSDetector; // QRS检测器
struct TMDQueue; // 时间戳数据队列
struct TestBuilder; // 测试构建器
struct TimeMarkedData; // 时间戳数据
struct WaveformDisplay; // 波形显示

typedef unsigned char boolean;
#define QUEUE_SIZE (20000)

#endif // ECGPKG_H

