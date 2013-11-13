#ifndef WINSETTINGS_H
#define WINSETTINGS_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QModelIndex>
#include <QFtp>

namespace Ui {
class winSettings;
}

class winSettings : public QMainWindow{
    Q_OBJECT
    public:
        explicit winSettings(QWidget *parent = 0);

        void keyPressEvent(QKeyEvent*);
        void keyReleaseEvent(QKeyEvent *);
        void checkDefaultSettings();
        void hideEvent(QHideEvent *eve);
        ~winSettings();

    private slots:
        void on_btnLoad_clicked();
        void on_btnSaveData_clicked();
        void on_btnShortcutArea_clicked();
        void on_btnShortcutFull_clicked();
        void connectOrDisconnect();
        void ftpCommandFinished(int, bool error);

        void on_btnShortcutDesc_clicked();

        void on_btnBrowseFolder_clicked();

        void on_btnResetFull_clicked();

        void on_btnResetRegion_clicked();

        void on_btnResetDesc_clicked();

        void on_chkToFolder_toggled(bool checked);

        void on_chkToClipboard_toggled(bool checked);

        void on_chkImgToClipboard_toggled(bool checked);

        void on_optSPGrab_toggled(bool checked);

        void on_optCustomFtp_toggled(bool checked);

        void on_optNone_toggled(bool checked);

        void on_chkDisableSKeys_toggled(bool checked);

        void on_btnTest_clicked();

        void on_optSPGrab_clicked();

        void on_optCustomFtp_clicked();

        void on_btnShortcutAreaLive_clicked();

        void on_btnResetRegionLive_clicked();

        void on_btnShortcutGrabWindow_clicked();

        void on_btnResetGrabWindow_clicked();

private:
        Ui::winSettings *ui;
        bool captureInput;
        QString captured;
        QString beforeNew;
        int captureKeyFor;
        QFtp *ftp;

    signals:
        void dataSaved();
        void canceled();

};

#endif // WINSETTINGS_H
