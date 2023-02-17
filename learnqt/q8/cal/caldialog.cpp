#include "caldialog.h"
#include "ui_caldialog.h"

CalDialog::CalDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CalDialog)
{
    ui->setupUi(this);
}

CalDialog::~CalDialog()
{
    delete ui;
}

