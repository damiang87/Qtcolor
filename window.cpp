#include "window.h"
#include "ui_window.h"
#include <iostream>

window::window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window)
{
    ui->setupUi(this);
    this->setFixedSize(660,448);
    connect(ui->verticalSlider,SIGNAL(valueChanged(int)),ui->lcdNumber,SLOT(display(int)));
    connect(ui->verticalSlider_2,SIGNAL(valueChanged(int)),ui->lcdNumber_2,SLOT(display(int)));
    connect(ui->verticalSlider_3,SIGNAL(valueChanged(int)),ui->lcdNumber_3,SLOT(display(int)));

    connect(ui->verticalSlider_4,SIGNAL(valueChanged(int)),ui->lcdNumber_4,SLOT(display(int)));
    connect(ui->verticalSlider_5,SIGNAL(valueChanged(int)),ui->lcdNumber_5,SLOT(display(int)));
    connect(ui->verticalSlider_6,SIGNAL(valueChanged(int)),ui->lcdNumber_6,SLOT(display(int)));

    connect(ui->verticalSlider,SIGNAL(valueChanged(int)),this,SLOT(update_label()));
    connect(ui->verticalSlider_2,SIGNAL(valueChanged(int)),this,SLOT(update_label()));
    connect(ui->verticalSlider_3,SIGNAL(valueChanged(int)),this,SLOT(update_label()));

    connect(ui->verticalSlider_4,SIGNAL(valueChanged(int)),this,SLOT(update_label2()));
    connect(ui->verticalSlider_5,SIGNAL(valueChanged(int)),this,SLOT(update_label2()));
    connect(ui->verticalSlider_6,SIGNAL(valueChanged(int)),this,SLOT(update_label2()));

    connect(ui->button_wczytaj,SIGNAL(clicked()),this,SLOT(wczytaj()));
    connect(ui->button_zapisz,SIGNAL(clicked()),this,SLOT(zapisz()));
    filepath = QDir::currentPath();
}

void window::zapisz(void)
{
    fn = QFileDialog::getSaveFileName(this, tr("Zapis projektu") ,filepath, tr("plik_kolor_changer.txt"));
    if (QFile::exists (fn))	//Jeli jest ju plik o tej nazwie
    {
    QMessageBox*mbox=new QMessageBox ("Continue",  "The same file exist.\n Continue?",
                    QMessageBox::Critical,
                    QMessageBox::Ok | QMessageBox::Default,
                    QMessageBox::Cancel | QMessageBox::Escape,
                    0);
     mbox->show();
     if(mbox->exec() == QMessageBox::Ok )
        {

        }
    }
}

void window::wczytaj()
{

}

void window::update_label2(void)
{
    ui->label_5->setText("");
    QString qss2 = QString("background-color: %1").arg(BColor2.name());
    ui->label_5->setStyleSheet(qss2);
    h = ui->verticalSlider_4->value();
    s = ui->verticalSlider_5->value();
    v = ui->verticalSlider_6->value();
    BColor2.setHsv(h,s,v);
}


void window::update_label(void)
{
    ui->label->setText("");
    QString qss = QString("background-color: %1").arg(BColor.name());
    ui->label->setStyleSheet(qss);
    r = ui->verticalSlider->value();
    g = ui->verticalSlider_2->value();
    b = ui->verticalSlider_3->value();
    BColor.setRgb(r,g,b);
}

window::~window()
{
    delete ui;
}
