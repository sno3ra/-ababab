#include "AnimatedWidget.h"
#include <QStyle>

AnimatedWidget::AnimatedWidget(QWidget *parent)
    : QWidget(parent), m_color(Qt::white)
{
    m_animation = new QPropertyAnimation(this, "color");
    m_animation->setDuration(2000); // 2 seconds duration
}

QColor AnimatedWidget::color() const
{
    return m_color;
}

void AnimatedWidget::setColor(const QColor &color)
{
    m_color = color;
    setStyleSheet(QString("background-color: rgb(%1, %2, %3);").arg(color.red()).arg(color.green()).arg(color.blue()));
}

void AnimatedWidget::animateColorChange(const QColor &newColor)
{
    m_animation->setStartValue(m_color);
    m_animation->setEndValue(newColor);
    m_animation->start();
}
