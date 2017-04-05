#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <QtWebKit>
#include <QtWebKit/QtWebKit>
#include <QProgressBar>
#include <QWebFrame>
#include "sourceview.h"
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString sourceCode;
    void initMainPage();


private:
    Ui::MainWindow *ui;
    QProgressBar *progressBar;
private slots:
    void setUrlSlot(QUrl url);
    void browserTitleSlot(QString);
    void browserUrlSlot();
    void deleteProgressBarSlot(bool);
    void sourceCodeSlot();
    void setMainPage();
   // void setProgressBar(int);
};

#endif // MAINWINDOW_H
