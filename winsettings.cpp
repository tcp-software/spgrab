#include "winsettings.h"
#include "ui_winsettings.h"
#include "window.h"
#include "config.h"

#include <QMainWindow>
#include <QSettings>
#include <QWidget>
#include <QKeyEvent>
#include <QChar>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QListWidget>
#include <QUrl>

QString finalHost;
winSettings::winSettings(QWidget *parent) : QMainWindow(parent), ui(new Ui::winSettings){
    finalHost = "";
    ui->setupUi(this);
        ui->txtFtpPassword->setEchoMode(QLineEdit::Password);
        ui->txtFtpPassword->setInputMethodHints(Qt::ImhHiddenText | Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);

        ui->txtStoreFolder->setEnabled(false);
        ui->txtStoreFolder->setReadOnly(true);
        ui->btnBrowseFolder->setEnabled(false);

        ui->cmbImageFormats->addItem("PNG");
        ui->cmbImageFormats->addItem("JPG");

        ui->chkAutoStart->setVisible(false);

#ifdef Q_WS_WIN
        ui->chkAutoStart->setVisible(true);
#endif

    captureInput = false;
    captured = "";
    checkDefaultSettings();

}
winSettings::~winSettings(){
    config::winSettingsVisible = false;
    delete ui;
}
void winSettings::hideEvent(QHideEvent *eve){
    config::winSettingsVisible = false;
    emit canceled();
}

void winSettings::checkDefaultSettings(){
    QSettings settings( config::getWPath() + "/settings.ini", QSettings::IniFormat);

    settings.beginGroup("General");
        QString tmpFirstRun = settings.value("firstrun").toString();
    settings.endGroup();

    if( tmpFirstRun.trimmed().length() == 0 ){

        settings.beginGroup("shortcuts");
            settings.setValue("enablekeys", "true" );
            settings.setValue("enablekeysFS", "true" );
            settings.setValue("enablekeysAS", "true" );
            settings.setValue("enablekeysNL", "true" );
            settings.setValue("enablekeysADS", "true" );
            settings.setValue("enablekeysGW", "true" );
            settings.setValue("fullscreen", "CTRL+SHIFT+F" );
            settings.setValue("areanl", "CTRL+SHIFT+R" );
            settings.setValue("desc", "CTRL+SHIFT+D" );
            settings.setValue("area", "CTRL+SHIFT+L" );
            settings.setValue("grabwindow", "CTRL+SHIFT+A" );
        settings.endGroup();

        settings.beginGroup("Server");
            settings.setValue("uploadto", "2" );
            settings.setValue("uploadimgs", "false" );
        settings.endGroup();

        settings.beginGroup("General");
            settings.setValue("firstTester", "true" );
            settings.setValue("autostart", "false" );
            settings.setValue("storetofolder",  "false" );
            settings.setValue("storingfolder",  "");
            settings.setValue("copyimgtoclipboard", "false" );
            settings.setValue("copyurltoclipboard", "false" );
            settings.setValue("imgformat", "png" );
        settings.endGroup();

        settings.beginGroup("General");
            settings.setValue("firstrun", "false" );
        settings.endGroup();

        ui->label->setVisible(false);
        ui->label_4->setVisible(false);
        ui->optSPGrab->setChecked(true);
        ui->txtHost->setVisible(false);
        ui->txtUploadedURL->setVisible(false);
        ui->txtHost->setText("ftp://spgrab.com");
        ui->txtUploadedURL->setText("http://cdn.spgrab.com/");
        ui->btnShortcutFull->setText("CTRL+SHIFT+F");
        ui->btnShortcutArea->setText( "CTRL+SHIFT+R" );
        ui->btnShortcutDesc->setText( "CTRL+SHIFT+D" );
        ui->btnShortcutAreaLive->setText( "CTRL+SHIFT+L" );
        ui->btnShortcutGrabWindow->setText( "CTRL+SHIFT+A" );
        ui->chkKeyFS->setChecked(true);
        ui->chkKeyAS->setChecked(true);
        ui->chkKeyADS->setChecked(true);
        ui->chkKeyLive->setChecked(true);

    } else {
        on_btnLoad_clicked();
    }
}

void winSettings::on_btnLoad_clicked(){

    QSettings settings( config::getWPath() + "/settings.ini", QSettings::IniFormat);

    settings.beginGroup("shortcuts");

        ui->btnShortcutFull->setText( settings.value("fullscreen").toString() );
        ui->btnShortcutAreaLive->setText( settings.value("area").toString() );
        ui->btnShortcutDesc->setText( settings.value("desc").toString() );
        ui->btnShortcutArea->setText( settings.value("areanl").toString() );
        ui->btnShortcutGrabWindow->setText( settings.value("grabwindow").toString() );
        ui->chkDisableSKeys->setChecked( ( settings.value("enablekeys").toString() == "true" ) ? false : true );

        if( !ui->chkDisableSKeys->isChecked() ){
            ui->chkKeyFS->setChecked( ( settings.value("enablekeysFS").toString() == "true" ) ? true : false );
            ui->chkKeyAS->setChecked( ( settings.value("enablekeysNL").toString() == "true" ) ? true : false );
            ui->chkKeyLive->setChecked( ( settings.value("enablekeysAS").toString() == "true" ) ? true : false );
            ui->chkKeyADS->setChecked( ( settings.value("enablekeysADS").toString() == "true" ) ? true : false );
            ui->chkKeyGW->setChecked( ( settings.value("enablekeysGW").toString() == "true" ) ? true : false );
        }else{
            ui->chkKeyFS->setChecked( false );
            ui->chkKeyAS->setChecked( false );
            ui->chkKeyADS->setChecked( false );
            ui->chkKeyLive->setChecked( false );
            ui->chkKeyGW->setChecked( false );
        }

        if( ui->btnShortcutFull->text().trimmed().length() == 0 ) {
            ui->btnShortcutFull->setText("CTRL+SHIFT+F");
        }
        if( ui->btnShortcutArea->text().trimmed().length() == 0 ) {
            ui->btnShortcutArea->setText( "CTRL+SHIFT+R" );
        }
        if( ui->btnShortcutDesc->text().trimmed().length() == 0 ) {
            ui->btnShortcutDesc->setText( "CTRL+SHIFT+D" );
        }
        if( ui->btnShortcutGrabWindow->text().trimmed().length() == 0 ) {
            ui->btnShortcutGrabWindow->setText( "CTRL+SHIFT+A" );
        }
        if( ui->btnShortcutAreaLive->text().trimmed().length() == 0 ) {
            ui->btnShortcutAreaLive->setText( "CTRL+SHIFT+L" );
        }else if( ui->btnShortcutAreaLive->text().trimmed() == "CTRL+SHIFT+R" && ui->btnShortcutArea->text().trimmed() == "CTRL+SHIFT+R" ) {
            ui->btnShortcutAreaLive->setText( "CTRL+SHIFT+L" );
        }

    settings.endGroup();

    settings.beginGroup("Server");
        if( settings.value("uploadto").toString() == "0" ){
            ui->label->setVisible(false);
            ui->label_4->setVisible(false);
            ui->optSPGrab->setChecked(true);
            ui->txtHost->setVisible(false);
            ui->txtUploadedURL->setVisible(false);
            ui->txtHost->setText("ftp://spgrab.com");
            ui->txtUploadedURL->setText("http://cdn.spgrab.com/");

        }else if( settings.value("uploadto").toString() == "1" ){
            ui->label->setVisible(true);
            ui->label_4->setVisible(true);
            ui->optCustomFtp->setChecked(true);
        }else{
            ui->label->setVisible(false);
            ui->label_2->setVisible(false);
            ui->label_3->setVisible(false);
            ui->label_4->setVisible(false);

            ui->optNone->setChecked(true);
            ui->txtHost->setVisible(false);
            ui->txtFtpUsername->setVisible(false);
            ui->txtFtpPassword->setVisible(false);
            ui->txtUploadedURL->setVisible(false);
        }

        ui->txtHost->setText( settings.value("host").toString().replace("ftp://","").replace("\r\n","").replace("\n","") );
        ui->txtFtpUsername->setText( settings.value("username").toString().replace("\r\n","").replace("\n","") );
        ui->txtFtpPassword->setText( settings.value("pass").toString().replace("\r\n","").replace("\n","") );
        ui->txtUploadedURL->setText( settings.value("url").toString().replace("\r\n","").replace("\n","") );

    settings.endGroup();

    settings.beginGroup("General");
        ui->chkAutoStart->setChecked( ( settings.value( "autostart" ).toString() == "true" ) ? true : false );

        if ( settings.value("storetofolder").toString() == "true" ){
            ui->chkToFolder->setChecked( true );
            ui->txtStoreFolder->setText( settings.value("storingfolder").toString() );
        }else{
            ui->chkToFolder->setChecked( false );
            ui->txtStoreFolder->setText( "" );
        }

        ui->chkImgToClipboard->setChecked( ( settings.value( "copyimgtoclipboard" ).toString() == "true" ) ? true : false );

        ui->chkToClipboard->setChecked( ( settings.value( "copyurltoclipboard" ).toString() == "true" ) ? true : false );

        if( settings.value("imgformat").toString().toLower() == "jpg" ){
            ui->cmbImageFormats->setCurrentIndex(1);
        } else {
            ui->cmbImageFormats->setCurrentIndex(0);
        }

        ui->chkOpenInBrowser->setChecked( ( settings.value( "openinbrowser" ).toString() == "true" ) ? true : false );

    settings.endGroup();
}
void winSettings::keyReleaseEvent(QKeyEvent *){
    this->releaseKeyboard();
}

void winSettings::keyPressEvent(QKeyEvent *eve){
    QString tmp;
    QString forMsg;

    if ( captureInput == true ){
        this->grabKeyboard();

        if (eve->key() == Qt::Key_Control){
            if( !captured.contains("CTRL") ){
                captured = "CTRL+" + captured;
            }
        } else if (eve->key() == Qt::Key_Shift){
            if( !captured.contains("SHIFT") ){
                captured = captured + "SHIFT+";
            }
        } else if (eve->key() == Qt::Key_Alt){
            if( !captured.contains("ALT") ){
                captured = captured + "ALT+";
            }
        } else if (eve->key() == Qt::Key_AltGr){
            if( !captured.contains("ALTGR") ){
                captured = captured + "ALTGR+";
            }
        } else if (eve->key() == Qt::Key_Space){
            if( !captured.contains("SPACE") ){
                captured = captured + "SPACE+";
            }
        } else {
            tmp.resize(1);
            tmp[0] = QChar( eve->key() );
            if( !captured.endsWith("+" + tmp[0]) ){
                captured = captured + tmp[0];
                //this->releaseKeyboard();
            }
        }

        if( !captured.endsWith('+') ){
            captureInput = false;
            this->releaseKeyboard();
        }

        switch (captureKeyFor) {
            case 0:
                if( captured.length() > 3 && ui->btnShortcutArea->text() != captured && ui->btnShortcutDesc->text() != captured && ui->btnShortcutAreaLive->text() != captured ){
                    ui->btnShortcutFull->setText(captured);
                } else {
                    ui->btnShortcutFull->setText( beforeNew );
                    if( captured.length() <= 3  ){
                        forMsg = "and press some more keys like CTRL, ALT, SHIFT,\n not just " + tmp[0];
                    }else{
                        forMsg = ", because the schortcut key combination You have pressed is already in use.";
                    }
                }
                break;
            case 1:
                if( captured.length() > 3 && ui->btnShortcutFull->text() != captured && ui->btnShortcutDesc->text() != captured && ui->btnShortcutAreaLive->text() != captured ){
                    ui->btnShortcutArea->setText(captured);
                } else {
                    ui->btnShortcutArea->setText( beforeNew );
                    if( captured.length() <= 3  ){
                        forMsg = "and press some more keys like CTRL, ALT, SHIFT,\n not just " + tmp[0];
                    }else{
                        forMsg = ", because the schortcut key combination You have pressed is already in use.";
                    }
                }
                break;
            case 2:
                if( captured.length() > 3  && ui->btnShortcutArea->text() != captured && ui->btnShortcutFull->text() != captured && ui->btnShortcutAreaLive->text() != captured ){
                    ui->btnShortcutDesc->setText(captured);
                } else {
                    ui->btnShortcutDesc->setText( beforeNew );
                    if( captured.length() <= 3  ){
                        forMsg = "and press some more keys like CTRL, ALT, SHIFT,\n not just " + tmp[0];
                    }else{
                        forMsg = ", because the schortcut key combination You have pressed is already in use.";
                    }
                }
                break;
            case 3:
                if( captured.length() > 3  && ui->btnShortcutArea->text() != captured && ui->btnShortcutDesc->text() != captured && ui->btnShortcutFull->text() != captured ){
                    ui->btnShortcutAreaLive->setText(captured);
                } else {
                    ui->btnShortcutAreaLive->setText( beforeNew );
                    if( captured.length() <= 3  ){
                        forMsg = "and press some more keys like CTRL, ALT, SHIFT,\n not just " + tmp[0];
                    }else{
                        forMsg = ", because the schortcut key combination You have pressed is already in use.";
                    }
                }
                break;
            default:
                break;
        }
        if( forMsg.length() > 0 ){
            QMessageBox msgBox;
            msgBox.setText("Your new shortcut is not valid,\n please click again " + forMsg );
            msgBox.exec();
        }
    }
}
void winSettings::ftpCommandFinished(int, bool error){
    if (ftp->currentCommand() == QFtp::ConnectToHost) {
        if ( error ) {
            QMessageBox msgBox;
            msgBox.setText("Host error:\n" + ftp->errorString() );
            msgBox.exec();
            return;
        }
        return;
    }else if( ftp->currentCommand() == QFtp::Login ){
        if ( error ){
            QMessageBox msgBox;
            msgBox.setText("Wrong username / password:\n" + ftp->errorString() );
            msgBox.exec();
            return;
        }
    }else{
        if( error ){
            QMessageBox msgBox;
            msgBox.setText( ftp->errorString() );
            msgBox.exec();
        }
    }
    QMessageBox msgBox;
    msgBox.setText( "Connected Successfully." );
    msgBox.exec();
}
void winSettings::connectOrDisconnect(){
    ftp = new QFtp(this);
    connect( ftp, SIGNAL( commandFinished(int,bool) ),
            this, SLOT( ftpCommandFinished(int,bool) ) );
    finalHost = "ftp://" + ui->txtHost->text().replace("\r\n","").replace("\n","");
    QUrl url( finalHost );

    url.setUserName( ui->txtFtpUsername->text().replace("\r\n","").replace("\n","") );
    url.setPassword( ui->txtFtpPassword->text().replace("\r\n","").replace("\n","") );

    ftp->connectToHost( url.host(), url.port( 21 ) );

    if ( !url.userName().isEmpty() ){
        ftp->login( QUrl::fromPercentEncoding( url.userName().toLatin1() ), url.password() );
    }else{
        ftp->login();
    }
}
void winSettings::on_btnSaveData_clicked(){
    QSettings settings( config::getWPath() + "/settings.ini", QSettings::IniFormat);

    settings.beginGroup("shortcuts");
        settings.setValue("fullscreen", ui->btnShortcutFull->text() );
        settings.setValue("area", ui->btnShortcutAreaLive->text() );
        settings.setValue("areanl", ui->btnShortcutArea->text() );
        settings.setValue("desc", ui->btnShortcutDesc->text() );
        settings.setValue("grabwindow", ui->btnShortcutGrabWindow->text() );
        settings.setValue("enablekeys", ( ui->chkDisableSKeys->isChecked() == true ) ? "false" : "true"  );
        settings.setValue("enablekeysFS", ( ui->chkKeyFS->isChecked() == true ) ? "true" : "false"  );
        settings.setValue("enablekeysNL", ( ui->chkKeyAS->isChecked() == true ) ? "true" : "false"  );
        settings.setValue("enablekeysADS", ( ui->chkKeyADS->isChecked() == true ) ? "true" : "false"  );
        settings.setValue("enablekeysAS", ( ui->chkKeyLive->isChecked() == true ) ? "true" : "false"  );
        settings.setValue("enablekeysGW", ( ui->chkKeyGW->isChecked() == true ) ? "true" : "false"  );
    settings.endGroup();

    settings.beginGroup("Server");

        if( ui->optSPGrab->isChecked() ){
            settings.setValue("uploadto", "0" );
            settings.setValue("uploadimgs", "true" );
            ui->txtHost->setText("ftp://spgrab.com");
            ui->txtUploadedURL->setText("http://cdn.spgrab.com/");
        }
        if( ui->optCustomFtp->isChecked() ) {
            settings.setValue("uploadto", "1" );
            settings.setValue("uploadimgs", "true" );
        }
        if( ui->optNone->isChecked() ) {
            settings.setValue("uploadto", "2" );
            settings.setValue("uploadimgs", "false" );
        }

        settings.setValue("host", "ftp://" + ui->txtHost->text().replace("ftp://", "").replace("\r\n","").replace("\n","") );
        settings.setValue("username",  ui->txtFtpUsername->text().replace("\r\n","").replace("\n","") );
        settings.setValue("pass", ui->txtFtpPassword->text().replace("\r\n","").replace("\n","") );
        settings.setValue("url", ui->txtUploadedURL->text().replace("\r\n","").replace("\n","") );

        if( ui->txtFtpUsername->text().trimmed().length() < 3 ||
            ui->txtFtpPassword->text().trimmed().length() < 3 ||
            ui->txtHost->text().trimmed().length() < 3 ){
                settings.setValue("uploadto", "2" );
                settings.setValue("uploadimgs", "false" );
        }

    settings.endGroup();

    settings.beginGroup("General");

    settings.setValue("autostart", ( ui->chkAutoStart->isChecked() ) ? "true" : "false" );
        #ifdef Q_WS_WIN
            QSettings settings1( "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat );
            if ( ui->chkAutoStart->isChecked() ) {
                settings1.setValue( "SPGrab", QCoreApplication::applicationFilePath().replace( '/','\\' ) );
            } else {
                settings1.remove("SPGrab");
            }
        #endif

        settings.setValue("storetofolder",  ( ui->chkToFolder->isChecked() ) ? "true" : "false" );
        if( !ui->chkToFolder->isChecked() ){
            settings.setValue("storingfolder",  "");
        }else{
            settings.setValue("storingfolder",  ui->txtStoreFolder->text() );
        }
        settings.setValue("copyimgtoclipboard", ( ui->chkImgToClipboard->isChecked() ) ? "true" : "false" );
        settings.setValue("copyurltoclipboard", ( ui->chkToClipboard->isChecked() ) ? "true" : "false" );
        settings.setValue("openinbrowser", ( ui->chkOpenInBrowser->isChecked() ) ? "true" : "false" );

        settings.setValue("imgformat", ui->cmbImageFormats->currentText().toLower() );
    settings.endGroup();

    emit dataSaved();
    delete this;
}

void winSettings::on_btnShortcutArea_clicked(){
    this->releaseKeyboard();
    this->setFocus();
    beforeNew = ui->btnShortcutArea->text();
    captured = "";
    captureInput = true;
    captureKeyFor = 1;
}

void winSettings::on_btnShortcutFull_clicked(){
    this->releaseKeyboard();
    this->setFocus();
    beforeNew = ui->btnShortcutFull->text();
    captured = "";
    captureInput = true;
    captureKeyFor = 0;
}

void winSettings::on_btnShortcutDesc_clicked(){
    this->releaseKeyboard();
    this->setFocus();
    beforeNew = ui->btnShortcutDesc->text();
    captured = "";
    captureInput = true;
    captureKeyFor = 2;
}

void winSettings::on_btnShortcutGrabWindow_clicked()
{
    this->releaseKeyboard();
    this->setFocus();
    captured = "";
    captureInput = true;
    captureKeyFor = 4;
}

void winSettings::on_btnResetGrabWindow_clicked()
{
    ui->btnShortcutGrabWindow->setText( "CTRL+SHIFT+A" );

}

void winSettings::on_btnShortcutAreaLive_clicked(){
    this->releaseKeyboard();
    this->setFocus();
    captured = "";
    captureInput = true;
    captureKeyFor = 3;
}

void winSettings::on_btnResetRegionLive_clicked(){
    ui->btnShortcutAreaLive->setText( "CTRL+SHIFT+L" );
}


void winSettings::on_btnBrowseFolder_clicked(){
    QString s = QFileDialog::getExistingDirectory(this, tr("Select folder where You want to store images"),
                                                  "/home",
                                                  QFileDialog::ShowDirsOnly
                                                  | QFileDialog::DontResolveSymlinks);
    ui->txtStoreFolder->setText(s);

}
void winSettings::on_btnResetFull_clicked(){
    ui->btnShortcutFull->setText( "CTRL+SHIFT+F" );
}

void winSettings::on_btnResetRegion_clicked(){
    ui->btnShortcutArea->setText( "CTRL+SHIFT+R" );
}

void winSettings::on_btnResetDesc_clicked(){
    ui->btnShortcutDesc->setText( "CTRL+SHIFT+D" );
}
void winSettings::on_chkToFolder_toggled(bool checked){
    ui->txtStoreFolder->setEnabled(checked);
    ui->btnBrowseFolder->setEnabled(checked);
}

void winSettings::on_chkToClipboard_toggled(bool checked){
    if( checked ){
        ui->chkImgToClipboard->setChecked( !checked );
    }
}

void winSettings::on_chkImgToClipboard_toggled(bool checked){
    if( checked ){
        ui->chkToClipboard->setChecked( !checked );
    }
}

void winSettings::on_optSPGrab_toggled(bool checked){
    ui->label->setVisible(false);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->label_4->setVisible(false);

    ui->txtHost->setText("spgrab.com");
    ui->txtUploadedURL->setText("http://cdn.spgrab.com/");

    ui->txtHost->setVisible(false);
    ui->txtUploadedURL->setVisible(false);
    ui->txtFtpUsername->setVisible(true);
    ui->txtFtpPassword->setVisible(true);
    ui->btnTest->setVisible(true);
}

void winSettings::on_optCustomFtp_toggled(bool checked){
    ui->label->setVisible(true);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->label_4->setVisible(true);
    ui->txtHost->setVisible(true);

    ui->txtHost->setText("");
    ui->txtUploadedURL->setText("");

    ui->txtFtpUsername->setVisible(true);
    ui->txtFtpPassword->setVisible(true);
    ui->txtUploadedURL->setVisible(true);
    ui->btnTest->setVisible(true);
}

void winSettings::on_optNone_toggled(bool checked){
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);

    ui->txtHost->setText("");
    ui->txtUploadedURL->setText("");

    ui->txtHost->setVisible(false);
    ui->txtFtpUsername->setVisible(false);
    ui->txtFtpPassword->setVisible(false);
    ui->txtUploadedURL->setVisible(false);
    ui->btnTest->setVisible(false);
}

void winSettings::on_chkDisableSKeys_toggled(bool checked){
    if( checked ){
        ui->chkKeyADS->setChecked(false);
        ui->chkKeyFS->setChecked(false);
        ui->chkKeyAS->setChecked(false);
        ui->chkKeyLive->setChecked(false);
        ui->chkKeyGW->setChecked(false);

        ui->btnShortcutArea->setEnabled(false);
        ui->btnShortcutDesc->setEnabled(false);
        ui->btnShortcutFull->setEnabled(false);
        ui->btnShortcutAreaLive->setEnabled(false);
        ui->btnShortcutGrabWindow->setEnabled(false);

        ui->btnResetDesc->setEnabled(false);
        ui->btnResetRegion->setEnabled(false);
        ui->btnResetFull->setEnabled(false);
        ui->btnResetRegionLive->setEnabled(false);
        ui->btnResetGrabWindow->setEnabled(false);

    }else{
        ui->chkKeyAS->setEnabled(true);
        ui->chkKeyFS->setEnabled(true);
        ui->chkKeyADS->setEnabled(true);
        ui->chkKeyLive->setEnabled(true);
        ui->chkKeyGW->setChecked(true);

        ui->btnShortcutArea->setEnabled(true);
        ui->btnShortcutDesc->setEnabled(true);
        ui->btnShortcutFull->setEnabled(true);
        ui->btnShortcutAreaLive->setEnabled(true);
        ui->btnShortcutGrabWindow->setEnabled(true);

        ui->btnResetDesc->setEnabled(true);
        ui->btnResetRegion->setEnabled(true);
        ui->btnResetFull->setEnabled(true);
        ui->btnResetRegionLive->setEnabled(true);
        ui->btnResetGrabWindow->setEnabled(true);

        QSettings settings( config::getWPath() + "/settings.ini", QSettings::IniFormat);
        settings.beginGroup("shortcuts");
            ui->chkKeyADS->setChecked( ( settings.value("enablekeysADS").toString() == "true" ) ? true : false );
            ui->chkKeyFS->setChecked( ( settings.value("enablekeysFS").toString() == "true" ) ? true : false );
            ui->chkKeyLive->setChecked( ( settings.value("enablekeysAS").toString() == "true" ) ? true : false );
            ui->chkKeyAS->setChecked( ( settings.value("enablekeysNL").toString() == "true" ) ? true : false );
            ui->chkKeyGW->setChecked( ( settings.value("enablekeysGW").toString() == "true" ) ? true : false );
        settings.endGroup();
    }

}
void winSettings::on_btnTest_clicked()
{
    connectOrDisconnect();
}

void winSettings::on_optSPGrab_clicked(){
    ui->txtHost->setText("spgrab.com");
    ui->txtUploadedURL->setText("http://cdn.spgrab.com/");
}

void winSettings::on_optCustomFtp_clicked(){
    ui->txtHost->setText("");
    ui->txtUploadedURL->setText("");
}

