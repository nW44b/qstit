#ifndef FADERWIDGET_H
#define FADERWIDGET_H

#include <QWidget>

class QTimer;

class FaderWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor fadeColor READ fadeColor WRITE setFadeColor)
    Q_PROPERTY(int fadeDuration READ fadeDuration WRITE setFadeDuration)
public:

    FaderWidget(QWidget *parent);

    QColor fadeColor() const { return startColor; }
    void setFadeColor(const QColor &newColor) { startColor = newColor; }

    int fadeDuration() const { return duration; }
    void setFadeDuration(int milliseconds) { duration = milliseconds; }

    void start();

protected:
    void paintEvent(QPaintEvent *event);

private:
    QTimer *timer;
    QColor startColor;
    int currentAlpha;
    int duration;
};

#endif
