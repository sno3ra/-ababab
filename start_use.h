#ifndef START_USE_H
#define START_USE_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "log_page.h"
#include "register_page.h"
#include "register_page.h"
#include <QDialog>

namespace Ui {
class Start_use;
}

class Start_use : public QDialog
{
    Q_OBJECT

public:
    explicit Start_use(QWidget *parent = nullptr);
    ~Start_use();
    Log_page* log;
    register_page* regi;
    MainWindow* mainw = nullptr;

public slots:
    void execute_main(const QString& username);

private slots:
    void on_register_button_clicked();

    void on_log_button_clicked();

private:
    Ui::Start_use *ui;
};

#endif // START_USE_H
