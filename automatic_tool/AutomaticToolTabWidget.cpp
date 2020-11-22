#include "AutomaticToolWidget.h"
#include "ui_AutomaticToolWidget.h"

bool AutomaticToolWidget::GenerateNewButton(QTableWidget *widget)
{
    return false;
}

void AutomaticToolWidget::InitDevicesTableList()
{
    ui->devsInfoTbView->setColumnCount(3);
    ui->devsInfoTbView->horizontalHeader()->setVisible(true);
    ui->devsInfoTbView->verticalHeader()->setVisible(false);

    QStringList header;
    header<< tr("手机") << tr("任务") << tr("运行");
    ui->devsInfoTbView->setHorizontalHeaderLabels(header);

    ui->devsInfoTbView->setSelectionBehavior(QTableWidget::SelectRows);

    //表头固定

}

void AutomaticToolWidget::ResizeDevicesTableList()
{
    int width = ui->devsInfoTbView->width();
    ui->devsInfoTbView->setColumnWidth(0, width*0.5);
    ui->devsInfoTbView->setColumnWidth(1, width*0.3);
    ui->devsInfoTbView->setColumnWidth(2, width - width*0.5-width*0.3 -2);
}

void AutomaticToolWidget::InitSysTasksTableList()
{
    ui->sysTasksTbView->setColumnCount(5);
    ui->sysTasksTbView->horizontalHeader()->setVisible(true);
    ui->sysTasksTbView->verticalHeader()->setVisible(false);

    QStringList header;
    header<< tr("ID") << tr("描述") << tr("策略") << tr("内容") << tr("运行");
    ui->sysTasksTbView->setHorizontalHeaderLabels(header);

    ui->sysTasksTbView->insertRow(0);
    ui->sysTasksTbView->setSpan(0, 0, 1, 5);
}

void AutomaticToolWidget::ResizeSysTasksTableList()
{
    int width = ui->sysTasksTbView->width();
    ui->sysTasksTbView->setColumnWidth(0, width*0.10);
    ui->sysTasksTbView->setColumnWidth(1, width*0.30);
    ui->sysTasksTbView->setColumnWidth(2, width*0.30);
    ui->sysTasksTbView->setColumnWidth(3, width*0.20-2);
    ui->sysTasksTbView->setColumnWidth(4, width*0.10);
}



void AutomaticToolWidget::InitAppTasksTableList()
{
    ui->appTasksTbView->setColumnCount(5);
    ui->appTasksTbView->horizontalHeader()->setVisible(true);
    ui->appTasksTbView->verticalHeader()->setVisible(false);

    QStringList header;
    header<< tr("ID") << tr("描述") << tr("策略") << tr("内容") << tr("运行");
    ui->appTasksTbView->setHorizontalHeaderLabels(header);

    ui->appTasksTbView->insertRow(0);
    ui->appTasksTbView->setSpan(0, 0, 1, 5);

    //add button
    QPushButton *pBtn = new QPushButton();
    connect(pBtn, SIGNAL(clicked()), this, SLOT(OnBtnClicked()));
    ui->appTasksTbView->setCellWidget(0,0,pBtn);
}

void AutomaticToolWidget::ResizeAppTasksTableList()
{
    int width = ui->appTasksTbView->width();
    ui->appTasksTbView->setColumnWidth(0, width*0.10);
    ui->appTasksTbView->setColumnWidth(1, width*0.30);
    ui->appTasksTbView->setColumnWidth(2, width*0.30);
    ui->appTasksTbView->setColumnWidth(3, width*0.20-2);
    ui->appTasksTbView->setColumnWidth(4, width*0.10);
}


void AutomaticToolWidget::InitModuleTasksTableList()
{
    ui->moduleTasksTbView->setColumnCount(5);
    ui->moduleTasksTbView->horizontalHeader()->setVisible(true);
     ui->moduleTasksTbView->verticalHeader()->setVisible(false);

    QStringList header;
    header<< tr("ID") << tr("描述") << tr("策略") << tr("内容") << tr("运行");
    ui->moduleTasksTbView->setHorizontalHeaderLabels(header);

    ui->moduleTasksTbView->insertRow(0);
    ui->moduleTasksTbView->setSpan(0, 0, 1, 5);
}


void AutomaticToolWidget::ResizeModuleTasksTableList()
{
    int width = ui->moduleTasksTbView->width();
    ui->moduleTasksTbView->setColumnWidth(0, width*0.10);
    ui->moduleTasksTbView->setColumnWidth(1, width*0.30);
    ui->moduleTasksTbView->setColumnWidth(2, width*0.30);
    ui->moduleTasksTbView->setColumnWidth(3, width*0.20-2);
    ui->moduleTasksTbView->setColumnWidth(4, width*0.10);
}




void AutomaticToolWidget::InitInitialAppTasksTableList()
{
    ui->initTasksTbView->setColumnCount(4);
    ui->initTasksTbView->horizontalHeader()->setVisible(true);
    ui->initTasksTbView->verticalHeader()->setVisible(false);

    QStringList header;
    header<< tr("ID") << tr("描述")  << tr("内容") << tr("运行");
    ui->initTasksTbView->setHorizontalHeaderLabels(header);

    ui->initTasksTbView->insertRow(0);
    ui->initTasksTbView->setSpan(0, 0, 1, 4);
}

void AutomaticToolWidget::ResizeInitialAppTasksTableList()
{
    int width = ui->initTasksTbView->width();
    ui->initTasksTbView->setColumnWidth(0, width*0.10);
    ui->initTasksTbView->setColumnWidth(1, width*0.40);
    ui->initTasksTbView->setColumnWidth(2, width*0.40);
    ui->initTasksTbView->setColumnWidth(3, width*0.10-2);
}



void AutomaticToolWidget::InitActionTasksTableList()
{
    ui->actionTasksTbView->setColumnCount(4);
    ui->actionTasksTbView->horizontalHeader()->setVisible(true);
    ui->actionTasksTbView->verticalHeader()->setVisible(false);
    QStringList header;
    header<< tr("ID") << tr("描述")  << tr("前提") << tr("过程结果");
    ui->actionTasksTbView->setHorizontalHeaderLabels(header);

    ui->actionTasksTbView->insertRow(0);
    ui->actionTasksTbView->setSpan(0, 0, 1, 4);
}

void AutomaticToolWidget::ResizeActionTasksTableList()
{
    int width = ui->actionTasksTbView->width();
    ui->actionTasksTbView->setColumnWidth(0, width*0.10);
    ui->actionTasksTbView->setColumnWidth(1, width*0.30);
    ui->actionTasksTbView->setColumnWidth(2, width*0.30);
    ui->actionTasksTbView->setColumnWidth(3, width*0.30-2);
}
