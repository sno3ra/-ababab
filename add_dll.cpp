#include "add_dll.h"
#include "ui_add_dll.h"
#include <QDate>
Add_dll::Add_dll(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Add_dll)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
}

Add_dll::~Add_dll()
{
    delete ui;
}

void Add_dll::on_pushButton_2_clicked()
{
    delete this;
}


void Add_dll::on_pushButton_clicked()
{
    emit signal_add_ddl(ui->dateEdit->date(), ui->timeEdit->time(), ui->lineEdit->text());
    delete this;
}

