#include "log_page.h"
#include "ui_log_page.h"
#include "mainwindow.h"
#include "log_page.h"
#include "register_page.h"
#include "start_use.h"
#include "register_page.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
Log_page::Log_page(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Log_page)
{
    ui->setupUi(this);
}

Log_page::~Log_page()
{
    delete ui;
}

void Log_page::on_finish_button_clicked()
{
    QString username = ui->account_edit->text();
    QString password = ui->password_edit->text();
    if(Log_page::isUserExist(username, password)){ //登录成功
        QMessageBox::information(this,"提示","登录成功");
        emit complete_log(username);
    }
    else{
        QMessageBox::critical(this,"错误","账号或密码错误，请重试");
    }
}

bool Log_page:: isUserExist(const QString& username, const QString& password)
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection")){
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else{
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("database.db");
    }

    if (!db.open()) {
        qDebug() << "Error: Unable to open database";
        return false;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM Users WHERE Username = :username AND Password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.exec();

    return query.next();
}

