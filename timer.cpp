#include "timer.h"
#include "ui_timer.h"
#include "timer_popup.h"
#include "mainwindow.h"


QColor default_gray = QColor(240, 240, 240);
QColor light_red = QColor(255, 182, 193);
QColor light_green = QColor(144, 238, 144);
QColor lilac = QColor(237, 200, 255);

int color_gradient_time = 1000;         // milliseconds
int color_gradient_update_time = 30;    // milliseconds
bool accelerate = true;
int ms_in_s = accelerate ?

timer::timer(MainWindow *parent)
    : QWidget(nullptr) // Ensure the timer window is a top-level window
    , ui(new Ui::timer)
    , mainWindow(parent)
    , mode("none")
    , colorTimer(new QTimer(this))
    , duration(0)
    , elapsed(0)
{
    ui->setupUi(this);
    connect(&tomato_timer, SIGNAL(timeout()), this, SLOT(timeout_slot()));
    connect(colorTimer, SIGNAL(timeout()), this, SLOT(updateBackgroundColor()));

    QTimer *currentTimeTimer = new QTimer(this);
    // connect(currentTimeTimer, SIGNAL(timeout()), this, SLOT(updateCurrentTime()));
    currentTimeTimer->start(1000); // Start the timer

    time.setHMS(0, 0, 0, 0);
    ui->showTime->setText("00:00:00");
    ui->pauseLabel->setText("");

    set_customHMS_visibility(false);
}

timer::~timer()
{
    delete ui;
}

void timer::on_pushButton_clicked()
{
    this->hide();
    if (mainWindow) {
        mainWindow->show();
    }
}

void timer::timeout_slot()
{
    qDebug("timer ticked 1 second");
    time = time.addSecs(-1);

    if (time.hour() == 0 && time.minute() == 0 && time.second() == 0) {
        ui->showTime->setText(time.toString("mm:ss"));
        ui->pauseLabel->setText("TIME IS UP! ");
        // timer ended
        tomato_timer.stop();
        setBackgroundColor(default_gray, color_gradient_time);
        timer_popup *popup = new timer_popup(this, mode);
        popup->exec();

        time.setHMS(0, 0, 0, 0);
        updateCurrentTime();
        ui->pauseLabel->setText("");
    }

    if (time.hour() == 0) {
        ui->showTime->setText(time.toString("mm:ss"));
    }
    else {
        ui->showTime->setText(time.toString("hh:mm:ss"));
    }

}

void timer::on_timer_tomato_bt_clicked()
{
    mode = "tomato";
    tomato_timer.stop();
    ui->pauseLabel->setText("");
    set_customHMS_visibility(false);
    // POMODORO: count down from 25 mins
    time.setHMS(0, 25, 0, 0);
    ui->showTime->setText("25:00");

    setBackgroundColor(light_red, color_gradient_time);
}

void timer::on_timer_rest_bt_clicked()
{
    mode = "rest";
    tomato_timer.stop();
    ui->pauseLabel->setText("");
    set_customHMS_visibility(false);
    // REST: count down from 5 mins
    time.setHMS(0, 5, 0, 0);
    ui->showTime->setText("05:00");

    setBackgroundColor(light_green, color_gradient_time);
}

void timer::on_timer_custom_bt_clicked()
{
    mode = "custom";
    tomato_timer.stop();
    ui->pauseLabel->setText("");
    // CUSTOM: count down from what user specifies
    set_customHMS_visibility(true);
    ui->showTime->setText("");

    ui->spinBox_h->setValue(0);
    ui->spinBox_m->setValue(0);
    ui->spinBox_s->setValue(0);

    setBackgroundColor(lilac, color_gradient_time);
}


void timer::on_timer_start_bt_clicked()
{
    if (ui->spinBox_h->isVisible()) {   // is in custom mode
        int hours = ui->spinBox_h->value();
        int minutes = ui->spinBox_m->value();
        int seconds = ui->spinBox_s->value();
        time.setHMS(hours, minutes, seconds, 0);
        set_customHMS_visibility(false);
        if (time.hour() == 0) {
            ui->showTime->setText(time.toString("mm:ss"));
        }
        else {
            ui->showTime->setText(time.toString("hh:mm:ss"));
        }
    }
    tomato_timer.start(1000);
    ui->pauseLabel->setText("");
}


void timer::on_timer_stop_bt_clicked()
{
    tomato_timer.stop();
    ui->pauseLabel->setText("PAUSED");
}


void timer::on_timer_reset_bt_clicked()
{
    tomato_timer.stop();
    ui->pauseLabel->setText("");
    time.setHMS(0, 0, 0, 0);
    ui->showTime->setText("00:00:00");
    setBackgroundColor(default_gray, color_gradient_time);
}

void timer::updateCurrentTime()
{
    QTime currentTime = QTime::currentTime();
    ui->showTime->setText(currentTime.toString("hh:mm:ss"));
    qDebug("show current time");
}

void timer::set_customHMS_visibility(bool visibility)
{
    ui->spinBox_h->setVisible(visibility);
    ui->custom_h_label->setVisible(visibility);
    ui->spinBox_m->setVisible(visibility);
    ui->custom_m_label->setVisible(visibility);
    ui->spinBox_s->setVisible(visibility);
    ui->custom_s_label->setVisible(visibility);
}

void timer::setBackgroundColor(const QColor &color, int millisecs)
{
    if (millisecs == 0) {
        QString styleSheet = QString("background-color: %1;").arg(color.name());
        this->setStyleSheet(styleSheet);
    }
    else {
        QPalette palette = this->palette();
        startColor = palette.color(QPalette::Window);
        qDebug() << "Start color: " << startColor.name();
        endColor = color;
        qDebug() << "End color: " << endColor.name();
        duration = millisecs;
        elapsed = 0;

        colorTimer->start(color_gradient_update_time);
    }
}

void timer::updateBackgroundColor()
{
    qDebug("update background called");
    elapsed += color_gradient_update_time;
    if (elapsed >= duration) {
        colorTimer->stop();
        qDebug("Color Timer stopped");
        QString styleSheet = QString("background-color: %1;").arg(endColor.name());
        this->setStyleSheet(styleSheet);
        return;
    }

    // interpolate color
    float t = static_cast<float>(elapsed) / duration;
    int r = startColor.red() + t * (endColor.red() - startColor.red());
    int g = startColor.green() + t * (endColor.green() - startColor.green());
    int b = startColor.blue() + t * (endColor.blue() - startColor.blue());
    QColor currentColor(r, g, b);
    qDebug() << "Current color: " << currentColor.name();

    // set new background color
    QString styleSheet = QString("background-color: %1;").arg(currentColor.name());
    this->setStyleSheet(styleSheet);
    qDebug("Set current color. ");
}




