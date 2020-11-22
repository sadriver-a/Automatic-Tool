#include "PreviewThread.h"

PreviewThread::PreviewThread(bool status)
{
    m_previewStatus = status;
    m_devName = "";
}


void PreviewThread::run()
{
    while(true)
    {
        if (m_previewStatus  && !m_devName.isEmpty())
        {
            QByteArray img_data;
            //CDeviceCmd::GetInstance()->Snap("12b089c1", img_data);
           CDeviceCmd::GetInstance()->Snap(m_devName.toUtf8().data(), img_data);
            emit SendPreview(img_data);
        }
        QThread::usleep(300);
    }
}

void PreviewThread::SetDeviceObject(QString devName)
{
    m_devName = devName;
}

void PreviewThread::SetPreviceSwitch(bool status)
{
    m_previewStatus = status;
}
