#include "ui_connectdialog.h"
#include "connectdialog.h"

#include <QMessageBox>

ConnectDialog::ConnectDialog(MainWindow *window,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDialog),
    window(window)

{

    ui->setupUi(this);
}

ConnectDialog::~ConnectDialog()
{
    delete ui;
}

void ConnectDialog::on_pushButtonConnect_clicked()
{
    window->connectButtonPushed(ui->textEditIP->toPlainText(),quint16(ui->textEditPort->toPlainText().toInt()));
}

