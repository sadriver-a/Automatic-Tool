#ifndef AUTOMATIC_TOOL_WIDGET_H
#define AUTOMATIC_TOOL_WIDGET_H

#include <QWidget>
#include <QImage>
#include <QLabel>
#include <QDebug>
#include <QTimer>
#include <QStandardItemModel>
#include <QMouseEvent>
#include <QPainter>
#include <QTableWidget>

#include "PreviewThread.h"
#include "device/CDeviceCmd.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AutomaticToolWidget; }
QT_END_NAMESPACE

class PreviewThread;
class AutomaticToolWidget : public QWidget
{
    Q_OBJECT

public:
    AutomaticToolWidget(QWidget *parent = nullptr);
    ~AutomaticToolWidget();

private:
    Ui::AutomaticToolWidget *ui;
    PreviewThread *previewTask;

private:
    void SetBackground();

    void InitDevicesTableList();
    void InitSysTasksTableList();
    void InitAppTasksTableList();
    void InitInitialAppTasksTableList();
    void InitModuleTasksTableList();
    void InitActionTasksTableList();

    void ResizeDevicesTableList();
    void ResizeSysTasksTableList();
    void ResizeAppTasksTableList();
    void ResizeModuleTasksTableList();
    void ResizeInitialAppTasksTableList();
    void ResizeActionTasksTableList();

    bool GenerateNewButton(QTableWidget *widget);

signals:
    void SetPreviewDevice(QString);
    void SetPreviewSwitch(bool);

private slots:
    void DispalyPreview(QByteArray img_data);
    void PreviewStatusChange();
};
#endif // AUTOMATIC_TOOL_WIDGET_H
