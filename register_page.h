#ifndef REGISTER_PAGE_H
#define REGISTER_PAGE_H

#include <QDialog>

namespace Ui {
class register_page;
}

class register_page : public QDialog
{
    Q_OBJECT

public:
    explicit register_page(QWidget *parent = nullptr);
    ~register_page();
    bool isUserExist(const QString& username, const QString& password);
    void registerUser(const QString& username, const QString& password);

signals:
    void complete_register(const QString& username);

private slots:
    void on_finish_button_clicked();

private:
    Ui::register_page *ui;
};

#endif // REGISTER_PAGE_H
