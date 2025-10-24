#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    btnNums={{Qt::Key_0,ui->btn0},
               {Qt::Key_1,ui->btn1},
               {Qt::Key_2,ui->btn2},
               {Qt::Key_3,ui->btn3},
               {Qt::Key_4,ui->btn4},
               {Qt::Key_5,ui->btn5},
               {Qt::Key_6,ui->btn6},
               {Qt::Key_7,ui->btn7},
               {Qt::Key_8,ui->btn8},
               {Qt::Key_9,ui->btn9},
               };
    foreach(auto btn,btnNums)
        connect(btn,SIGNAL(clicked()),this,SLOT(btnNumClicked()));



    //connect(ui->btnchu,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    // connect(ui->btncheng,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    //connect(ui->btnjia,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    // connect(ui->btnjian,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    // connect(ui->btn1x,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    // connect(ui->btnx2,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    // connect(ui->btnbaifen,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    // connect(ui->btngenhao,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::calculation(bool *ok)
{
    double result=0;
    if(operands.size()==2&& opcodes.size()>0){
        double operand1 = operands.front().toDouble();
        operands.pop_front();
        double operand2 = operands.front().toDouble();
        operands.pop_front();
        QString op = opcodes.front();
        opcodes.pop_front();
        if (op=="+"){
            result = operand1+operand2;
        }else if (op=="2"){
            result = operand1-operand2;
        }else if (op=="*"){
            result = operand1 * operand2;
        }else if (op=="/"){
            result=operand1/operand2;
        }
        operands.push_back(QString::number(result));


        ui->statusbar->showMessage(QString("calculation is in progress: operands is %1,opcode is %2").arg(operands.size()).arg(opcodes.size()));
    }else
        ui->statusbar->showMessage(QString(" operands is %1,opcode is %2").arg(operands.size()).arg(opcodes.size()));

    return QString::number(result);
}

void MainWindow::btnNumClicked()
{
    QString digit=qobject_cast<QPushButton*>(sender())->text();
    if(digit=="0"&&operand=="0")
        digit="";
    if(operand=="0"&&digit!="0")
        operand="";
    operand+=digit;
    ui->display->setText(operand);

}



void MainWindow::on_btnxiaoshudian_clicked()
{

    if(!operand.contains("."))
        operand+= qobject_cast<QPushButton*>(sender())->text();
    ui->display->setText(operand);
}


void MainWindow::on_btnshanchu_clicked()
{

    operand=operand.left(operand.length()-1);
    ui->display->setText(operand);
}


void MainWindow::on_btnC_clicked()
{
    operand.clear();
    ui->display->setText(operand);
}

void MainWindow::btnBinaryOperatorClicked()
{
    QString opcode=qobject_cast<QPushButton*>(sender())->text();

    if(operand!=""){
        operands.push_back(operand);
        operand="";

        opcodes.push_back(opcode);

        QString result=calculation();
        ui->display->setText(result);
    }
}

void MainWindow::btnUnaryOperatorClicked()
{
    if(operand!=""){
        double result =operand.toDouble();
        operand="";
        QString op=qobject_cast<QPushButton*>(sender())->text();
        if(op=="%")
            result/=100.0;
        else if (op=="1/x")
            result = 1/result;
        else if(op=="x^2")
            result*=result;
        else if(op=="")
            result=sqrt(result);
        ui->display->setText(QString::number(result));
    }
}


void MainWindow::on_btndengyv_clicked()
{
    if(operand!=""){
        operands.push_back(operand);
        operand="";
    }
    QString result=calculation();
    ui->display->setText(result);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    foreach(auto btnKey ,btnNums.keys()){
        if(event->key()==btnKey)
            btnNums[btnKey]->animateClick();
    }
    qDebug()<< event ->key();
}
