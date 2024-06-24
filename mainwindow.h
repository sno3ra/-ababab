#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <set_class.h>
#include "timer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void add_class(QString t_date, int w_class, QString prev_n, QString un);
    ~MainWindow();
    void expand_class(const QDate start,const QDate end);
    void ad_ddl(QDate date, QTime time, QString thing);
    void create_ddl_table();
    bool is_exsit_ddl_table();
    void update_ddl();
    QString username;
    QList<QLabel*>days;
    QList<QPushButton*>mon_class;
    QList<QPushButton*>tue_class;
    QList<QPushButton*>wedn_class;
    QList<QPushButton*>thur_class;
    QList<QPushButton*>fri_class;
    QList<QPushButton*>sat_class;
    QList<QPushButton*>sun_class;
    QList<QPushButton*>ddls;
    QList<QList<QPushButton*>>day_class;
    set_class* set = nullptr;
signals:
    void set_class_clicked(QString& dt, int wh_cl);

private slots:

    void on_go2date_clicked();


    void on_mon_bt1_clicked();

    void on_mon_bt2_clicked();

    void on_mon_bt3_clicked();

    void on_mon_bt4_clicked();

    void on_mon_bt5_clicked();

    void on_mon_bt6_clicked();

    void on_mon_bt7_clicked();

    void on_mon_bt8_clicked();

    void on_mon_bt9_clicked();

    void on_mon_bt10_clicked();

    void on_mon_bt11_clicked();

    void on_mon_bt12_clicked();

    void on_tue_bt1_clicked();

    void on_tue_bt2_clicked();

    void on_tue_bt3_clicked();

    void on_tue_bt4_clicked();

    void on_tue_bt5_clicked();

    void on_tue_bt6_clicked();

    void on_tue_bt7_clicked();

    void on_tue_bt8_clicked();

    void on_tue_bt9_clicked();

    void on_tue_bt10_clicked();

    void on_tue_bt11_clicked();

    void on_tue_bt12_clicked();

    void on_wedn_bt1_clicked();

    void on_wedn_bt2_clicked();

    void on_wedn_bt3_clicked();

    void on_wedn_bt4_clicked();

    void on_wedn_bt5_clicked();

    void on_wedn_bt6_clicked();

    void on_wedn_bt7_clicked();

    void on_wedn_bt8_clicked();

    void on_wedn_bt9_clicked();

    void on_wedn_bt10_clicked();

    void on_wedn_bt11_clicked();

    void on_wedn_bt12_clicked();

    void on_thur_bt1_clicked();

    void on_thur_bt2_clicked();

    void on_thur_bt3_clicked();

    void on_thur_bt4_clicked();

    void on_thur_bt5_clicked();

    void on_thur_bt6_clicked();

    void on_thur_bt7_clicked();

    void on_thur_bt8_clicked();

    void on_thur_bt9_clicked();

    void on_thur_bt10_clicked();

    void on_thur_bt11_clicked();

    void on_thur_bt12_clicked();

    void on_fri_bt1_clicked();

    void on_fri_bt2_clicked();

    void on_fri_bt3_clicked();

    void on_fri_bt4_clicked();

    void on_fri_bt5_clicked();

    void on_fri_bt6_clicked();

    void on_fri_bt7_clicked();

    void on_fri_bt8_clicked();

    void on_fri_bt9_clicked();

    void on_fri_bt10_clicked();

    void on_fri_bt11_clicked();

    void on_fri_bt12_clicked();

    void on_sat_bt1_clicked();

    void on_sat_bt2_clicked();

    void on_sat_bt3_clicked();

    void on_sat_bt4_clicked();

    void on_sat_bt5_clicked();

    void on_sat_bt6_clicked();

    void on_sat_bt7_clicked();

    void on_sat_bt8_clicked();

    void on_sat_bt9_clicked();

    void on_sat_bt10_clicked();

    void on_sat_bt11_clicked();

    void on_sat_bt12_clicked();

    void on_sun_bt1_clicked();

    void on_sun_bt2_clicked();

    void on_sun_bt3_clicked();

    void on_sun_bt4_clicked();

    void on_sun_bt5_clicked();

    void on_sun_bt6_clicked();

    void on_sun_bt7_clicked();

    void on_sun_bt8_clicked();

    void on_sun_bt9_clicked();

    void on_sun_bt10_clicked();

    void on_sun_bt11_clicked();

    void on_sun_bt12_clicked();

    void on_expand_button_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_set_ddl_clicked();

    void on_exit_button_clicked();

    void on_ddl_1_clicked();

    void on_ddl_2_clicked();

    void on_ddl_3_clicked();

    void on_ddl_4_clicked();

    void on_ddl_5_clicked();

    void on_ddl_6_clicked();

    void on_ddl_7_clicked();

    void on_pushButton_2_clicked();

public slots:
    void update_name(QString name, int which_day, int which_class);
private:
    Ui::MainWindow *ui;
    timer* mytimer;
};
#endif // MAINWINDOW_H
