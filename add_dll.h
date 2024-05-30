#ifndef ADD_DLL_H
#define ADD_DLL_H

#include <QDialog>
#include <QTime>
#include <QDate>
namespace Ui {
class Add_dll;
}

class Add_dll : public QDialog
{
    Q_OBJECT

public:
    explicit Add_dll(QWidget *parent = nullptr);
    ~Add_dll();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

signals:
    void signal_add_ddl(QDate date, QTime time, QString thing);

private:
    Ui::Add_dll *ui;
};

#endif // ADD_DLL_H
