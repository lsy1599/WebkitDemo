#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //初始化首页
    this->initMainPage();
    connect(ui->setDifferentAction,SIGNAL(triggered()),this,SLOT(setMainPage()));

    this->progressBar = new QProgressBar;
    ui->statusBar->addWidget(this->progressBar);
    //设置进度条
    connect(ui->webView,SIGNAL(loadProgress(int)),this->progressBar,SLOT(setValue(int)));
    //加载完成后,消除进度条
    connect(ui->webView,SIGNAL(loadFinished(bool)),this,SLOT(deleteProgressBarSlot(bool)));
    connect(ui->webView,SIGNAL(urlChanged(QUrl)),this,SLOT(setUrlSlot(QUrl)));
    connect(ui->webView,SIGNAL(titleChanged(QString)),this,SLOT(browserTitleSlot(QString)));
    connect(ui->urlLineEdit,SIGNAL(returnPressed()),this,SLOT(browserUrlSlot()));

    //显示网页源代码
    connect(ui->viewCodeAction,SIGNAL(triggered()),this,SLOT(sourceCodeSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainPage()
{
    QString filename = "mainpage.conf";
    QFile *file = new QFile;
    file->setFileName(filename);

    bool ok = file->open(QIODevice::ReadOnly);
    if(ok)
    {
        QTextStream in(file);
        QString url=in.readLine().split("=").at(1);
        qDebug() << url;
        ui->webView->load(QUrl(url));

    }
    else
    {
        //QMessageBox::information(this,"MainPage","open failed");
        ui->webView->load(QUrl("http://www.sina.com"));
    }
    file->close();
    delete file;
    file = NULL;

}

void MainWindow::setMainPage()
{
    QString url = ui->urlLineEdit->text();
    if(url.isEmpty())
    {
        url="http://www.baidu.com";
    }
    QString filename = "mainpage.conf";
    QFile *file = new QFile;
    file->setFileName(filename);
    bool ok = file->open(QIODevice::WriteOnly);
    if(ok)
    {
        QTextStream out(file);
        out << "mainpage="+url;
        QMessageBox::information(this,"MainPage","设置主页成功");

    }
    else
    {
        QMessageBox::information(this,"MainPage","设置主页失败");
        file->close();
        delete file;
        file = NULL;
    }
    file->close();
    delete file;
    file = NULL;
}
void MainWindow::setUrlSlot(QUrl url)
{
    ui->urlLineEdit->setText(url.toString());
    //ui->statusBar->addWidget(this->progressBar);
    return ;
}

void MainWindow::browserTitleSlot(QString title)
{
    //ui->urlLineEdit->setText(title);
    this->setWindowTitle(title);
}

void MainWindow::browserUrlSlot()
{
    ui->webView->load(ui->urlLineEdit->text());
}

//加载完成,移除进度条
void MainWindow::deleteProgressBarSlot(bool ok)
{
    if(ok){
        //ui->statusBar->removeWidget(this->progressBar);
        //this->statusBar()->showMessage("加载完成啦,亲",5*1000);
    }
}

void MainWindow::sourceCodeSlot()
{
    //显示网页源代码
    sourceCode = ui->webView->page()->currentFrame()->toHtml();
    SourceView *sourceView = new SourceView;
    sourceView->setSourceView(sourceCode);
    sourceView->show();
}

