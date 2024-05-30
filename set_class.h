#ifndef SET_CLASS_H
#define SET_CLASS_H

#include <QDialog>

namespace Ui {
class set_class;
}

class set_class : public QDialog
{
    Q_OBJECT

public:
    explicit set_class(QString p_name, QWidget *parent = nullptr);
    ~set_class();
    int which_class;
    QString the_date;
    QString prev_name;
    QString username;
    int which_day;
    void set_lineedit();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void update_class(QString name, int which_day, int which_class);
private:
    Ui::set_class *ui;
};

#endif // SET_CLASS_H
