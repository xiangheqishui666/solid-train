/********************************************************************************
** Form generated from reading UI file 'lyb.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LYB_H
#define UI_LYB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lyb
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *lyb)
    {
        if (lyb->objectName().isEmpty())
            lyb->setObjectName("lyb");
        lyb->resize(400, 300);
        label = new QLabel(lyb);
        label->setObjectName("label");
        label->setGeometry(QRect(98, 78, 151, 101));
        pushButton = new QPushButton(lyb);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(250, 240, 93, 28));

        retranslateUi(lyb);
        QObject::connect(pushButton, &QPushButton::clicked, lyb, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(lyb);
    } // setupUi

    void retranslateUi(QWidget *lyb)
    {
        lyb->setWindowTitle(QCoreApplication::translate("lyb", "Form", nullptr));
        label->setText(QCoreApplication::translate("lyb", "\346\235\216\345\240\260\345\206\260\n"
"2023414290113", nullptr));
        pushButton->setText(QCoreApplication::translate("lyb", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lyb: public Ui_lyb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LYB_H
