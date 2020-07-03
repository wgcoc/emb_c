#include "Business.hpp"

Business * Business::_instance = nullptr;

Business::Business(QObject *parent)
    : QObject(parent)
{
    moveToThread(&_thread);
    connect(&_thread,&QThread::started,this,&Business::work_thread);
}

Business::~Business()
{
    _thread.wait();
}

Business * Business::get_instance(void)
{
    if(_instance == nullptr)
        _instance = new Business();
    return _instance;
}

void Business::work_thread(void)
{
    while(1){
        qDebug() << "work_thread";
        QThread::sleep(1);
    }
}

