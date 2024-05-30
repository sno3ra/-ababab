#include "register_page.h"
#include "ui_register_page.h"
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
register_page::register_page(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::register_page)
{
    ui->setupUi(this);
}

register_page::~register_page()
{
    delete ui;
}

void register_page::on_finish_button_clicked()
{
    QString username = ui->account_edit->text();
    QString password = ui->password_edit->text();
    if(register_page::isUserExist(username, password)){ // 如果已经存在此用户，提示请您重新设置
        QMessageBox::critical(this, "提示", "账号名重复，请重新设置");
    }
    else{ // 创建新用户
        registerUser(username, password);
        QMessageBox::information(this, "提示", "账号创建成功");
        emit complete_register(username);
    }
}

void register_page::registerUser(const QString& username, const QString& password)
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection")){  //已经存在数据库
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else{   //不存在数据库
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("database.db");
    }
    if (!db.open()) {
        qDebug() << "Error: Unable to open database";
        return;
    }
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS Users (Username TEXT PRIMARY KEY, Password TEXT)")) {
        qDebug() << "Error: Failed to create table - " << query.lastError();
        return;
    }
    query.prepare("INSERT INTO Users (Username, Password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.exec();
    QString createTableSql = QString(
                                 "CREATE TABLE %1 ("
                                 "date TEXT PRIMARY KEY, "
                                 "class1 TEXT, "
                                 "class2 TEXT, "
                                 "class3 TEXT, "
                                 "class4 TEXT, "
                                 "class5 TEXT, "
                                 "class6 TEXT, "
                                 "class7 TEXT, "
                                 "class8 TEXT, "
                                 "class9 TEXT, "
                                 "class10 TEXT, "
                                 "class11 TEXT, "
                                 "class12 TEXT"
                                 ")"
                                 ).arg(username);
    query.exec(createTableSql);
    QString create = QString(
                         "CREATE TABLE %1_ddl ("
                         "date TEXT, "
                         "time TEXT, "
                         "thing TEXT"
                         ")"
                         ).arg(username);
    if(!query.exec(create)){
        qDebug() << "创建DDL表失败！";
    }
}

bool register_page:: isUserExist(const QString& username, const QString& password)
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
    if(!query.exec()){
        qDebug() << "未成功创建数据表！";
    }

    return query.next();
}


