#include "login.h"
#include "ui_login.h"
#include "transaction.h"
Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_clicked()
{
    transactionwindow = new Transaction();
    transactionwindow -> show();
    this -> close();
    transactionwindow -> setinfo(ui -> name_output -> text(), ui -> acc_output -> text() );
}

