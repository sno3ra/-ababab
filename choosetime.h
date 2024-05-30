#ifndef CHOOSETIME_H
#define CHOOSETIME_H

#include <QDialog>
#include <QDate>
namespace Ui {
class Choosetime;
}

class Choosetime : public QDialog
{
    Q_OBJECT

public:
    explicit Choosetime(QWidget *parent = nullptr);
    ~Choosetime();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void send_date(const QDate s,const QDate e);

private:
    Ui::Choosetime *ui;
};

#endif // CHOOSETIME_H
