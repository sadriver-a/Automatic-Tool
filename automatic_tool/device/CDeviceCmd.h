#ifndef CDEVICECMD_H
#define CDEVICECMD_H

#include <stdio.h>

#include <QString>
#include <QByteArray>
#include <QProcess>
#include <QFile>
#include <QDebug>
#include <QList>

class CDeviceCmd
{
private:
    static CDeviceCmd* sm_device_cmd;
    QString m_commandDir;

    CDeviceCmd();
    bool RunCmd(QString cmd_str, QByteArray &ret_content);

public:
    static CDeviceCmd* GetInstance();
    bool SetCmdDir(QString cmd_dir);
    ~CDeviceCmd(){};

    //method
    //info
    bool GetDevices( QList<QString> &devslist);
    bool GetDeviceInfo(QString devName,  QString &devInfo);

    //snap
    bool Snap(QString devName, QByteArray &data);

    //application
    bool OpenApplication(QString devName, QString appName);
    bool GetCurrApplication(QString devName, QString &appName);

    //keyevent
    bool KeyeventHome(QString devName);
    bool KeyeventMenu(QString devName);
    bool KeyeventBack(QString devName);

    //tap
    bool Tap(QString devName, uint32_t x, uint32_t y);
    bool LongTap(QString devName, uint32_t x, uint32_t y, uint32_t time);
    bool Swipe(QString devName, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t time = 0);

    //text
    bool InputText(QString devName, QString txt);
};

#endif // CDEVICECMD_H
