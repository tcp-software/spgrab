#include "winhistory.h"
#include "ui_winhistory.h"
#include "window.h"
#include "config.h"

#include <QMainWindow>
#include <QSettings>
#include <QWidget>
#include <QLineEdit>
#include <QDebug>
#include <QMessageBox>
#include <QUrl>
#include <QDesktopServices>
#include <QDebug>
#include <QClipboard>
#include <QFile>

QString cImg;
QUrl url2;
QDesktopServices *dServ2;

winHistory::winHistory(QWidget *parent) : QMainWindow(parent), ui(new Ui::winHistory){
    qDebug() << config::getWPath();
    ui->setupUi(this);
    hide();
    strSearchBy = "title";
    refreshList();

}
void winHistory::hideEvent(QHideEvent *eve){
    config::winHistoryVisible = false;
}
void winHistory::hotkeyPressed(){
    QMessageBox::information(this, "Good", "Hot key triggered", "yes", "no");
}

winHistory::~winHistory(){
    delete ui;
}
void winHistory::resizeEvent(QResizeEvent *){
    ui->centralwidget->resize(this->width(),this->height());
    ui->tblHistory->resize(this->width(),this->height()-100);
}

void winHistory::refreshList(){

    QSettings settings( config::getWPath() + "/history.ini", QSettings::IniFormat);

    settings.beginGroup("history");
        int size = settings.value("itemscount").toInt();
    settings.endGroup();

    ui->tblHistory->clearContents();
    ui->tblHistory->setRowCount(size);

    int i = 0;
    int b = 0;
    bool filtering = true;

    while(filtering){
        QString headd = "uploaded" + QString::number(b);
        b++;

        settings.beginGroup(headd);
            if( ui->txtSearch->text().trimmed().length() == 0 ){
                ui->tblHistory->setItem( i, 0, new QTableWidgetItem( settings.value("title").toString( ) ) );
                ui->tblHistory->setItem( i, 1, new QTableWidgetItem( settings.value("desc").toString() ) );
                ui->tblHistory->setItem( i, 2, new QTableWidgetItem( settings.value("date").toString() ) );
                ui->tblHistory->setItem( i, 3, new QTableWidgetItem( settings.value("url").toString() ) );
                if( b <= size){
                    i++;
                }
            } else {
                if( settings.value(strSearchBy).toString().toLower().indexOf( ui->txtSearch->text().toLower(), 0 ) >= 0 ) {
                    ui->tblHistory->setItem( i, 0, new QTableWidgetItem( settings.value("title").toString( ) ) );
                    ui->tblHistory->setItem( i, 1, new QTableWidgetItem( settings.value("desc").toString() ) );
                    ui->tblHistory->setItem( i, 2, new QTableWidgetItem( settings.value("date").toString() ) );
                    ui->tblHistory->setItem( i, 3, new QTableWidgetItem( settings.value("url").toString() ) );

                    i++;
                }
            }

        settings.endGroup();
        if( b > size){
            filtering = false;
        }

    }
    ui->tblHistory->setRowCount(i);
    i = 0;

}

void winHistory::on_txtSearch_textChanged(const QString &arg1){
    refreshList();
}

void winHistory::on_tblHistory_cellClicked(int row, int column){
    intSearchBy = column;
    ui->txtUrl->setText( ui->tblHistory->item( row, 3 )->text() );
    switch (column) {
    case 0:
        strSearchBy = "title";
        break;
    case 1:
        strSearchBy = "desc";
        break;
    case 2:
        strSearchBy = "date";
        break;
    case 3:
        cImg = ui->tblHistory->item(row,column)->text();
        url2 = QUrl( cImg );
        dServ2->openUrl(url2);
        break;
    default:
        strSearchBy = "title";
        break;
    }
}
void winHistory::on_btnClearAll_clicked(){
    if( QMessageBox::question(this, "Delete all history...","Are You sure?", QMessageBox::Yes | QMessageBox::Abort ) == QMessageBox::Yes ){
        QFile tmp(config::getWPath() + "/history.ini");
        tmp.close();
        tmp.remove();
        refreshList();
    }
}
void winHistory::on_tblHistory_activated(const QModelIndex &index){

}
void winHistory::on_btnToClipboard_clicked(){
    QClipboard *cb = QApplication::clipboard();
    cb->setText( ui->txtUrl->text(),
             QClipboard::Clipboard );
}
