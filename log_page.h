#ifndef LOG_PAGE_H
#define LOG_PAGE_H

#include <QDialog>

namespace Ui {
class Log_page;
}

class Log_page : public QDialog
{
    Q_OBJECT

public:
    explicit Log_page(QWidget *parent = nullptr);
    ~Log_page();
    bool isUserExist(const QString& username, const QString& password);

signals:
    void complete_log(const QString& username);

private slots:
    void on_finish_button_clicked();

private:
    Ui::Log_page *ui;
};

#endif // LOG_PAGE_H
