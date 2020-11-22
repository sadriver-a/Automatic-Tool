#include "AutomaticToolWidget.h"
#include "ui_AutomaticToolWidget.h"

AutomaticToolWidget::AutomaticToolWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AutomaticToolWidget)
{
    ui->setupUi(this);
    SetBackground();

    InitDevicesTableList();
    InitSysTasksTableList();
    InitAppTasksTableList();
    InitInitialAppTasksTableList();
    InitModuleTasksTableList();
    InitActionTasksTableList();


    previewTask = new PreviewThread(false);
    if (previewTask == NULL)
    {
        exit(1);
    }
    connect(previewTask, SIGNAL(SendPreview(QByteArray)), this, SLOT(DispalyPreview(QByteArray)),Qt::QueuedConnection);
    connect(this, SIGNAL(SetPreviewDevice(QString)), previewTask, SLOT(SetDeviceObject(QString)),Qt::QueuedConnection);
    connect(this, SIGNAL(SetPreviewSwitch(bool)), previewTask, SLOT(SetPreviceSwitch(bool)),Qt::QueuedConnection);
    previewTask->start();

    connect(ui->previewBtn, SIGNAL(pressed()), this, SLOT(PreviewStatusChange()));

/*
    QList<QString> devslist;
    CDeviceCmd::GetInstance()->GetDevices(devslist);
    emit SetPreviewDevice(devslist[0]);
*/

}


AutomaticToolWidget::~AutomaticToolWidget()
{
    delete ui;
}

//background
void AutomaticToolWidget::SetBackground()
{
     QPalette palette;
     QPixmap pixmap(":/Resource/sheep_bg.jpg");
     if (!pixmap.isNull())
     {
         QPixmap temp(pixmap.size());
          temp.fill(Qt::transparent);

          QPainter p1(&temp);
          p1.setCompositionMode(QPainter::CompositionMode_Source);
          p1.drawPixmap(0, 0, pixmap);
          p1.setCompositionMode(QPainter::CompositionMode_ColorDodge);
          p1.fillRect(temp.rect(), QColor(255, 255, 255, 200));
          p1.end();
         pixmap = temp;

         palette.setBrush(QPalette::Window, QBrush(pixmap));
         this->setPalette(palette);
     }
     else
         setStyleSheet("background-color:white");
}


//preview
void AutomaticToolWidget::PreviewStatusChange()
{
    static bool sw = false;
    sw = !sw;
    QIcon btn_icon;
    btn_icon.addFile(sw?":/Resource/switch_on.png":":/Resource/switch_off.png");
    ui->previewBtn->setIcon(btn_icon);
    emit SetPreviewSwitch(sw);

    //test
    ResizeDevicesTableList();
    ResizeSysTasksTableList();
    ResizeAppTasksTableList();
    ResizeModuleTasksTableList();
    ResizeInitialAppTasksTableList();
    ResizeActionTasksTableList();
}

void AutomaticToolWidget::DispalyPreview(QByteArray imgData)
{
    QImage img;
    img.loadFromData(imgData);
    QImage fitPixmap = img.scaled(ui->previewLb->width(), ui->previewLb->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->previewLb->setPixmap(QPixmap::fromImage(fitPixmap));
}


