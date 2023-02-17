#ifndef CALDIALOG_H
#define CALDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class CalDialog; }
QT_END_NAMESPACE

class CalDialog : public QDialog
{
    Q_OBJECT

public:
    CalDialog(QWidget *parent = nullptr);
    ~CalDialog();

private:
    Ui::CalDialog *ui;
};
#endif // CALDIALOG_H
