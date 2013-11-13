#ifndef WINHISTORY_H
#define WINHISTORY_H

#include <QMainWindow>
#include <QResizeEvent>
#include <QModelIndex>
#include "shortcut/3rdparty/qxt/include/QxtGui/QxtGlobalShortcut"
namespace Ui {
class winHistory;
}

class winHistory : public QMainWindow{
    Q_OBJECT

    public:
        explicit winHistory(QWidget *parent = 0);
        void hideEvent(QHideEvent *eve);
        ~winHistory();
    protected:
        void resizeEvent(QResizeEvent *);

    private:
        Ui::winHistory *ui;
        int intSearchBy;
        QString strSearchBy;
        QxtGlobalShortcut *m_hotkeyHandle;

    public slots:
        void hotkeyPressed();

    private slots:
        void refreshList();
        void on_txtSearch_textChanged(const QString &arg1);
        void on_tblHistory_cellClicked(int row, int column);
        void on_btnClearAll_clicked();
        void on_tblHistory_activated(const QModelIndex &index);
        void on_btnToClipboard_clicked();
};

#endif // WINHISTORY_H
