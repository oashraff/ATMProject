#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDialog>

namespace Ui {
class Transaction;
}

class Login;
class Transaction : public QDialog
{
    Q_OBJECT

public:
    explicit Transaction(QWidget *parent = nullptr);
    void setinfo(QString name, QString acc);

    ~Transaction();


private slots:

    void on_clear_button_clicked();

    void on_deposit_button_clicked();

    void on_withdraw_button_clicked();

    void on_show_button_clicked();

    void on_hide_button_clicked();

    void on_back_button_clicked();

private:
    Ui::Transaction *ui;
    Login* loginwindow;
    QString history = "Transaction History: \n";
    double balance = 0.0;
    double amount;

};

#endif // TRANSACTION_H
