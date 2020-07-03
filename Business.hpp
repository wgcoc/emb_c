#ifndef BUSINESS_H
#define BUSINESS_H
#include <QObject>
#include <QThread>
#include <QDebug>

class Business : public QObject
{
    Q_OBJECT
public:
    explicit Business(QObject * parent = 0);
    ~Business();

    static Business * get_instance(void);

    void start() { _thread.start(); }
    void terminate() { _thread.terminate(); }
    void exit(int c) { _thread.exit(c); }

protected slots:
    void work_thread(void);

private:
    QThread _thread;

    static Business * _instance;
};

#endif // BUSINESS_H
