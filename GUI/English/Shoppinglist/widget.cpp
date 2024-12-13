#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_calculate_clicked()
{
    const double bananaPrice = 3.99;
    const double applePrice = 2.99;
    const double breadPrice = 0.49;
    const double milkPrice = 1.09;
    const double tax = 0.07;

    short bananaCount = ui->bananaCount->value();
    short appleCount = ui->appleCount->value();
    short breadCount = ui->breadCount->value();
    short milkCount = ui->milkCount->value();

    double totalCost = (bananaCount * bananaPrice) +
                       (appleCount * applePrice) + (breadCount * breadPrice) +
                       (milkCount * milkPrice);

    ui->totalCost->setValue(totalCost);

    double taxAmount = totalCost * tax;
    ui->taxAmount->setValue(taxAmount);
}

