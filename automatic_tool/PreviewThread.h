#ifndef PREVIEWTHREAD_H
#define PREVIEWTHREAD_H

#include <QWidget>
#include <QThread>
#include "device/CDeviceCmd.h"
#include <QImage>

class PreviewThread : public QThread
{
    Q_OBJECT
public:
    PreviewThread(bool status);

private:
    bool m_previewStatus;
    QString m_devName;

private:
    virtual void run();

public:

signals:
    void SendPreview(QByteArray);

public slots:
    void SetDeviceObject(QString devName);
    void SetPreviceSwitch(bool status);


};

#endif // PREVIEWTHREAD_H
