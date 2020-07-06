// 心电图
#ifndef ECGPKG_H
#define ECGPKG_H

#include <stdio.h>

#define DEBUG_LINE() printf("[%s:%s] line=%d\r\n",__FILE__, __func__, __LINE__)
#define DEBUG_ERR(fmt, args...) printf("\033[46;31m[%s:%d]\033[0m "#fmt" errno=%d, %m\r\n", __func__, __LINE__, ##args, errno, errno)
#define DEBUG_INFO(fmt, args...) printf("\033[33m[%s:%d]\033[0m "#fmt"\r\n", __func__, __LINE__, ##args)

//#define DEBUG_LINE()
//#define DEBUG_ERR(fmt,...)
//#define DEBUG_INFO(fmt,...)

/* forward declarations */
struct ArrythmiaDetector; // 心律失常检测器
struct ECG_Module;
struct HistogramDisplay; // 直方图显示
struct HistogramDisplay_OBS; // 直方图显示
struct QRSDetector; // QRS检测器
struct TMDQueue; // 时间戳数据队列
struct TestBuilder; // 测试构建器
struct TimeMarkedData; // 时间戳数据
struct WaveformDisplay; // 波形显示

typedef void (*UpdateFuncPtr)(void* const me,const struct TimeMarkedData tmd);

typedef unsigned char boolean;
#define QUEUE_SIZE (20000)

#endif // ECGPKG_H

