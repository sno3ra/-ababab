#ifndef ANIMATEDWIDGET_H
#define ANIMATEDWIDGET_H

#include <QWidget>
#include <QColor>
#include <QPropertyAnimation>

class AnimatedWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor)

public:
    explicit AnimatedWidget(QWidget *parent = nullptr);

    QColor color() const;
    void setColor(const QColor &color);

    void animateColorChange(const QColor &newColor);

private:
    QColor m_color;
    QPropertyAnimation *m_animation;
};

#endif // ANIMATEDWIDGET_H
