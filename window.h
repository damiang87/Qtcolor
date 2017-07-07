#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QColor>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>

namespace Ui {
class window;
}

class window : public QWidget
{
    Q_OBJECT
    QColor BColor;
    QColor BColor2;

public:
    explicit window(QWidget *parent = 0);
    ~window();

public slots:
    void update_label(void);
    void update_label2(void);
    void wczytaj();
    void zapisz(void);

private:
    Ui::window *ui;
    int r,g,b;
    int h,s,v;
    QString filepath;
    QString fn;
};

#endif // WINDOW_H
