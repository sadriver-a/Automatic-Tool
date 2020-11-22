#include "CDeviceCmd.h"

#include <stdio.h>

CDeviceCmd* CDeviceCmd::sm_device_cmd = NULL;
CDeviceCmd* CDeviceCmd::GetInstance()
{
    if (sm_device_cmd == NULL)
    {
        sm_device_cmd = new CDeviceCmd();
    }
    return sm_device_cmd;
}



CDeviceCmd::CDeviceCmd()
{

}

inline bool CDeviceCmd::RunCmd(QString cmd_str, QByteArray &ret_content)
{
    QProcess process(0);
    process.start(cmd_str);
    process.waitForStarted();
    process.waitForFinished();

    if (process.readAllStandardError() != "")
        return false;

    ret_content = process.readAllStandardOutput();
    return true;
}


bool CDeviceCmd::SetCmdDir(QString cmd_dir)
{
    m_commandDir = cmd_dir;
    return true;
}


bool CDeviceCmd::GetDevices( QList<QString> &devslist)
{
    QString t_cmd;
    t_cmd += m_commandDir + "adb devices ";
     QByteArray t_data;
    if (!RunCmd(t_cmd, t_data))
        return false;
    QList<QByteArray> line = t_data.split('\n');
    if (line.size() < 1)
        return false;
    for (int i = 0; i<line.size(); ++i)
    {
        QByteArray dev_str = line[i].left(line[i].indexOf('\t'));
        if (!dev_str.isEmpty())
            devslist.append(dev_str);
    }
    return true;
}

bool CDeviceCmd::GetDeviceInfo(QString devName,  QString &devInfo)
{
    QString t_cmd;
    t_cmd += m_commandDir + "adb -s " + devName + " getprop ro.product.model";
     QByteArray t_data;
    if (!RunCmd(t_cmd, t_data))
        return false;
    devInfo = t_data;
    return true;
}




bool CDeviceCmd::Snap(QString devName, QByteArray &img_data)
{
    QString t_cmd;
    t_cmd += m_commandDir + "adb -s " + devName + " shell screencap -p";

    if (!RunCmd(t_cmd, img_data))
        return false;

    //delete \r
    img_data.replace("\r\n", "\n" ); //adb shell screencap -p | sed 's/\r$//' > screen.png

    return true;
}


bool CDeviceCmd::KeyeventHome(QString devName)
{
    QString t_cmd;
    t_cmd += m_commandDir + "adb -s " + devName + " shell input keyevent 3";
    QByteArray tmp;
    if (!RunCmd(t_cmd, tmp))
        return false;

    return true;
}

bool CDeviceCmd::KeyeventMenu(QString devName)
{
    QString t_cmd;
    t_cmd += m_commandDir + "adb -s " + devName + " shell input keyevent 1";
    QByteArray tmp;
    if (!RunCmd(t_cmd, tmp))
        return false;

    return true;
}

bool CDeviceCmd::KeyeventBack(QString devName)
{
    QString t_cmd;
    t_cmd += m_commandDir + "adb -s " + devName + " shell input keyevent 4";
    QByteArray tmp;
    if (!RunCmd(t_cmd, tmp))
        return false;

    return true;
}

bool CDeviceCmd::GetCurrApplication(QString devName, QString &appName)
{
    QString t_cmd;
    t_cmd += m_commandDir + "adb -s " + devName + " shell \"dumpsys window w | grep name= | grep  /\" ";

    QByteArray tmp;
    if (!RunCmd(t_cmd, tmp))
        return false;

    QString str = QString(tmp);
    appName = str.mid(str.indexOf("name=")+5, str.indexOf("/")-str.indexOf("name=")-5);
    return true;

}

//打开app有问题，动态权限
bool CDeviceCmd::OpenApplication(QString devName, QString appName)
{
    QString t_cmd;
    t_cmd += m_commandDir + "adb -s " + devName + " am start -n " + appName;
    QByteArray tmp;
    if (!RunCmd(t_cmd, tmp))
        return false;

     return true;
}


bool CDeviceCmd::Tap(QString devName, uint32_t x, uint32_t y)
{
    QString t_cmd;
    t_cmd += m_commandDir + "adb -s " + devName + " input tap "
              + QString::number(x) + " " + QString::number(y);
    QByteArray tmp;
    if (!RunCmd(t_cmd, tmp))
        return false;

     return true;
}


bool CDeviceCmd::LongTap(QString devName, uint32_t x, uint32_t y, uint32_t time)
{
    QString t_cmd;
    t_cmd += m_commandDir + "adb -s " + devName + " input swipe  "
              + QString::number(x) + " " + QString::number(y) + " "
             + QString::number(x) + " " + QString::number(y) + " " + QString::number(time);
    QByteArray tmp;
    if (!RunCmd(t_cmd, tmp))
        return false;

     return true;
}


bool CDeviceCmd::Swipe(QString devName, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t time)
{
    if (time == 0)
        time = 1000;
    QString t_cmd;
    t_cmd += m_commandDir + "adb -s " + devName + " input swipe  "
              + QString::number(x1) + " " + QString::number(y1) + " "
             + QString::number(x2) + " " + QString::number(y2) + " " + QString::number(time);
    QByteArray tmp;
    if (!RunCmd(t_cmd, tmp))
        return false;

     return true;
}


bool  CDeviceCmd::InputText(QString devName, QString txt)
{

    return true;
}
