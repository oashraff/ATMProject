#include "transaction.h"
#include "ui_transaction.h"
#include "login.h"
Transaction::Transaction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transaction)
{
    ui->setupUi(this);
}

void Transaction::setinfo(QString name, QString acc)
{
    ui -> welcome_namelabel -> setText(name);
    ui -> account_output_label -> setText(acc);
}

Transaction::~Transaction()
{
    delete ui;
}


void Transaction::on_clear_button_clicked()
{
    ui -> amount_Output_label -> setText("");
}


void Transaction::on_deposit_button_clicked()
{
    amount = ui -> amount_Output_label -> text().toDouble();
    balance += amount;
    ui -> current_output_label -> setText(QString::number(balance));
    history += "+" + ui -> amount_Output_label -> text() +"\n";
}


void Transaction::on_withdraw_button_clicked()
{
    amount = ui -> amount_Output_label -> text().toDouble();

    if (balance<amount)
    {
      ui -> status_output_label -> setText("Not Enough Funds");
    }
    else
    {
        balance = balance - amount;
        ui -> current_output_label -> setText(QString::number(balance));
        ui -> status_output_label -> setText("Withdraw Completed");
        history += "-" + ui -> amount_Output_label -> text() +"\n";
      }


}


void Transaction::on_show_button_clicked()
{
    ui -> history_label -> setText(history);
}


void Transaction::on_hide_button_clicked()
{
    ui -> history_label -> setText("");

}



void Transaction::on_back_button_clicked()
{
    loginwindow = new Login();
    loginwindow -> show();
    this -> close();
}

