#include "start_use.h"
#include "ui_start_use.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
Start_use::Start_use(QWidget *parent)
    : QDialog(parent)
    , log(new Log_page(this)), regi(new register_page(this)), ui(new Ui::Start_use), mainw(new MainWindow(this))
{
    ui->setupUi(this);
    connect(regi, SIGNAL(complete_register(QString)), this, SLOT(execute_main(QString)));
    connect(log, SIGNAL(complete_log(QString)), this, SLOT(execute_main(QString)));
}

Start_use::~Start_use()
{
    delete ui;
    delete regi;
    delete log;
}

void Start_use::on_register_button_clicked()
{
    regi->setModal(true);
    regi->show();
}


void Start_use::on_log_button_clicked()
{
    log->setModal(true);
    log->show();
}

void Start_use::execute_main(const QString& username){
    regi->close();
    log->close();
    this->close();
    mainw->username = username;
    mainw->show();
}
