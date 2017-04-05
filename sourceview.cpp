#include "sourceview.h"
#include "ui_sourceview.h"

SourceView::SourceView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SourceView)
{
    ui->setupUi(this);
}

SourceView::~SourceView()
{
    delete ui;
}

void SourceView::setSourceView(QString source)
{
    ui->sourceTextEdit->setPlainText(source);
}
