#ifndef SOURCEVIEW_H
#define SOURCEVIEW_H

#include <QDialog>

namespace Ui {
class SourceView;
}

class SourceView : public QDialog
{
    Q_OBJECT

public:
    explicit SourceView(QWidget *parent = 0);
    ~SourceView();

    void setSourceView(QString);

private:
    Ui::SourceView *ui;
};

#endif // SOURCEVIEW_H
