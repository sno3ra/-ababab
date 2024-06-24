#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <QTimer>
#include <QTime>

namespace Ui {
class timer;
}

class MainWindow;

class timer : public QWidget
{
    Q_OBJECT

public:
    explicit timer(MainWindow *parent = nullptr);
    ~timer();


private slots:
    void on_pushButton_clicked();

    void timeout_slot();

    void updateBackgroundColor();

    void on_timer_tomato_bt_clicked();

    void on_timer_rest_bt_clicked();

    void on_timer_custom_bt_clicked();

    void on_timer_start_bt_clicked();

    void on_timer_stop_bt_clicked();

    void on_timer_reset_bt_clicked();


private:
    Ui::timer *ui;
    MainWindow *mainWindow;

    QTimer tomato_timer;
    QTime time;
    QString mode;    // tomato, rest, custom

    QTimer *colorTimer;
    QColor startColor;
    QColor endColor;
    int duration;
    int elapsed;

    void set_customHMS_visibility(bool visibility);
    void setBackgroundColor(const QColor &color, int millisecs);
    void updateCurrentTime();
};

#endif // TIMER_H
