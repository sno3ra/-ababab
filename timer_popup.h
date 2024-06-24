#ifndef TIMER_POPUP_H
#define TIMER_POPUP_H

#include <QDialog>

namespace Ui {
class timer_popup;
}

class timer_popup : public QDialog
{
    Q_OBJECT

public:
    explicit timer_popup(QWidget *parent = nullptr, QString mode = "none");
    ~timer_popup();

private slots:
    void on_pushButton_clicked();

private:
    Ui::timer_popup *ui;
    QString mode;
};

#endif // TIMER_POPUP_H
