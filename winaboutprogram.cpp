#include "winaboutprogram.h"
#include "ui_winaboutprogram.h"
#include "config.h"
#include <QDebug>

winAboutProgram::winAboutProgram(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::winAboutProgram)
{
    ui->setupUi(this);
}

winAboutProgram::~winAboutProgram()
{
    config::winAboutVisible = false;
    delete ui;
}

void winAboutProgram::hideEvent(QHideEvent *eve){
    config::winAboutVisible = false;
}
