/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickedlabel.h"

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *ErrorTipsLabel;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *UserLabel;
    QLineEdit *UserEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *PasswdLabel;
    QLineEdit *PasswdEdit;
    ClickedLabel *PasswdVisible;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    ClickedLabel *ForgetPasswdLabel;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *RegisterButton;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *LoginButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->setWindowModality(Qt::WindowModality::NonModal);
        Login->resize(300, 500);
        Login->setMinimumSize(QSize(300, 500));
        Login->setMaximumSize(QSize(300, 500));
        Login->setSizeGripEnabled(false);
        verticalLayoutWidget = new QWidget(Login);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 302, 446));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        ErrorTipsLabel = new QLabel(verticalLayoutWidget);
        ErrorTipsLabel->setObjectName("ErrorTipsLabel");
        ErrorTipsLabel->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/resource/ice.png")));
        ErrorTipsLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(ErrorTipsLabel);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        UserLabel = new QLabel(verticalLayoutWidget);
        UserLabel->setObjectName("UserLabel");

        horizontalLayout_2->addWidget(UserLabel);

        UserEdit = new QLineEdit(verticalLayoutWidget);
        UserEdit->setObjectName("UserEdit");

        horizontalLayout_2->addWidget(UserEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        PasswdLabel = new QLabel(verticalLayoutWidget);
        PasswdLabel->setObjectName("PasswdLabel");

        horizontalLayout_3->addWidget(PasswdLabel);

        PasswdEdit = new QLineEdit(verticalLayoutWidget);
        PasswdEdit->setObjectName("PasswdEdit");

        horizontalLayout_3->addWidget(PasswdEdit);

        PasswdVisible = new ClickedLabel(verticalLayoutWidget);
        PasswdVisible->setObjectName("PasswdVisible");
        PasswdVisible->setMinimumSize(QSize(20, 20));
        PasswdVisible->setMaximumSize(QSize(20, 20));

        horizontalLayout_3->addWidget(PasswdVisible);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        ForgetPasswdLabel = new ClickedLabel(verticalLayoutWidget);
        ForgetPasswdLabel->setObjectName("ForgetPasswdLabel");

        horizontalLayout_8->addWidget(ForgetPasswdLabel);


        verticalLayout->addLayout(horizontalLayout_8);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        RegisterButton = new QPushButton(verticalLayoutWidget);
        RegisterButton->setObjectName("RegisterButton");

        horizontalLayout_6->addWidget(RegisterButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        LoginButton = new QPushButton(verticalLayoutWidget);
        LoginButton->setObjectName("LoginButton");

        horizontalLayout_7->addWidget(LoginButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_7);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        ErrorTipsLabel->setText(QString());
        label_2->setText(QCoreApplication::translate("Login", "\351\224\231\350\257\257\346\217\220\347\244\272", nullptr));
        UserLabel->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\357\274\232", nullptr));
        PasswdLabel->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201\357\274\232", nullptr));
        PasswdVisible->setText(QString());
        ForgetPasswdLabel->setText(QCoreApplication::translate("Login", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        RegisterButton->setText(QCoreApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
        LoginButton->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
