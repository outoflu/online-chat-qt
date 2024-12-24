/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickedlabel.h"
#include "timebtn.h"

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_9;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QLabel *ErrorTipsLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *UserLabel;
    QLineEdit *UserEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *MailLabel;
    QLineEdit *MailEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *PasswdLabel;
    QLineEdit *PasswdEdit;
    ClickedLabel *PasswdVisible;
    QHBoxLayout *horizontalLayout_7;
    QLabel *ConfirmPasswdLabel;
    QLineEdit *ConfirmPasswdEdit;
    ClickedLabel *ConfirmPasswdVisible;
    QHBoxLayout *horizontalLayout_8;
    QLabel *Codelabel;
    QLineEdit *CodeEdit;
    TimeBtn *GetCodeButton;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ConfirmBtn;
    QPushButton *CancelBtn;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_5;
    QLabel *tip_lb;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *return_btn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName("Register");
        Register->resize(300, 500);
        Register->setMinimumSize(QSize(300, 500));
        Register->setMaximumSize(QSize(300, 500));
        horizontalLayout = new QHBoxLayout(Register);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        stackedWidget = new QStackedWidget(Register);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        layoutWidget = new QWidget(page);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(-4, -4, 291, 491));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_4->addItem(verticalSpacer);

        ErrorTipsLabel = new QLabel(layoutWidget);
        ErrorTipsLabel->setObjectName("ErrorTipsLabel");
        ErrorTipsLabel->setMinimumSize(QSize(0, 25));
        ErrorTipsLabel->setMaximumSize(QSize(400, 25));
        ErrorTipsLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(ErrorTipsLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        UserLabel = new QLabel(layoutWidget);
        UserLabel->setObjectName("UserLabel");
        UserLabel->setMinimumSize(QSize(0, 25));
        UserLabel->setMaximumSize(QSize(16777215, 25));
        UserLabel->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);

        horizontalLayout_2->addWidget(UserLabel);

        UserEdit = new QLineEdit(layoutWidget);
        UserEdit->setObjectName("UserEdit");
        UserEdit->setMinimumSize(QSize(0, 25));
        UserEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(UserEdit);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        MailLabel = new QLabel(layoutWidget);
        MailLabel->setObjectName("MailLabel");
        MailLabel->setMinimumSize(QSize(0, 25));
        MailLabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(MailLabel);

        MailEdit = new QLineEdit(layoutWidget);
        MailEdit->setObjectName("MailEdit");
        MailEdit->setMinimumSize(QSize(0, 25));
        MailEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(MailEdit);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        PasswdLabel = new QLabel(layoutWidget);
        PasswdLabel->setObjectName("PasswdLabel");
        PasswdLabel->setMinimumSize(QSize(0, 25));
        PasswdLabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(PasswdLabel);

        PasswdEdit = new QLineEdit(layoutWidget);
        PasswdEdit->setObjectName("PasswdEdit");
        PasswdEdit->setMinimumSize(QSize(0, 25));
        PasswdEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(PasswdEdit);

        PasswdVisible = new ClickedLabel(layoutWidget);
        PasswdVisible->setObjectName("PasswdVisible");
        PasswdVisible->setMinimumSize(QSize(20, 20));
        PasswdVisible->setMaximumSize(QSize(20, 20));

        horizontalLayout_5->addWidget(PasswdVisible);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        ConfirmPasswdLabel = new QLabel(layoutWidget);
        ConfirmPasswdLabel->setObjectName("ConfirmPasswdLabel");
        ConfirmPasswdLabel->setMinimumSize(QSize(0, 25));
        ConfirmPasswdLabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_7->addWidget(ConfirmPasswdLabel);

        ConfirmPasswdEdit = new QLineEdit(layoutWidget);
        ConfirmPasswdEdit->setObjectName("ConfirmPasswdEdit");
        ConfirmPasswdEdit->setMinimumSize(QSize(0, 25));
        ConfirmPasswdEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_7->addWidget(ConfirmPasswdEdit);

        ConfirmPasswdVisible = new ClickedLabel(layoutWidget);
        ConfirmPasswdVisible->setObjectName("ConfirmPasswdVisible");
        ConfirmPasswdVisible->setMinimumSize(QSize(20, 20));
        ConfirmPasswdVisible->setMaximumSize(QSize(20, 20));

        horizontalLayout_7->addWidget(ConfirmPasswdVisible);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        Codelabel = new QLabel(layoutWidget);
        Codelabel->setObjectName("Codelabel");
        Codelabel->setMinimumSize(QSize(0, 25));
        Codelabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_8->addWidget(Codelabel);

        CodeEdit = new QLineEdit(layoutWidget);
        CodeEdit->setObjectName("CodeEdit");
        CodeEdit->setMinimumSize(QSize(0, 25));
        CodeEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_8->addWidget(CodeEdit);

        GetCodeButton = new TimeBtn(layoutWidget);
        GetCodeButton->setObjectName("GetCodeButton");
        GetCodeButton->setMinimumSize(QSize(0, 25));
        GetCodeButton->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_8->addWidget(GetCodeButton);


        verticalLayout_4->addLayout(horizontalLayout_8);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_4->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        ConfirmBtn = new QPushButton(layoutWidget);
        ConfirmBtn->setObjectName("ConfirmBtn");
        ConfirmBtn->setMinimumSize(QSize(0, 25));
        ConfirmBtn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(ConfirmBtn);

        CancelBtn = new QPushButton(layoutWidget);
        CancelBtn->setObjectName("CancelBtn");
        CancelBtn->setMinimumSize(QSize(0, 25));
        CancelBtn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(CancelBtn);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_4->addItem(verticalSpacer_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayoutWidget = new QWidget(page_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 281, 481));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer_5);

        tip_lb = new QLabel(verticalLayoutWidget);
        tip_lb->setObjectName("tip_lb");
        tip_lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(tip_lb);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        return_btn = new QPushButton(verticalLayoutWidget);
        return_btn->setObjectName("return_btn");

        horizontalLayout_6->addWidget(return_btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer_6);

        stackedWidget->addWidget(page_2);

        horizontalLayout_9->addWidget(stackedWidget);


        horizontalLayout->addLayout(horizontalLayout_9);


        retranslateUi(Register);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Dialog", nullptr));
        ErrorTipsLabel->setText(QCoreApplication::translate("Register", "\351\224\231\350\257\257\346\217\220\347\244\272", nullptr));
        UserLabel->setText(QCoreApplication::translate("Register", "\347\224\250\346\210\267\357\274\232", nullptr));
        MailLabel->setText(QCoreApplication::translate("Register", "\351\202\256\347\256\261\357\274\232", nullptr));
        PasswdLabel->setText(QCoreApplication::translate("Register", "\345\257\206\347\240\201\357\274\232", nullptr));
        PasswdVisible->setText(QString());
        ConfirmPasswdLabel->setText(QCoreApplication::translate("Register", "\347\241\256\350\256\244\357\274\232", nullptr));
        ConfirmPasswdVisible->setText(QString());
        Codelabel->setText(QCoreApplication::translate("Register", "\351\252\214\350\257\201\347\240\201\357\274\232", nullptr));
        GetCodeButton->setText(QCoreApplication::translate("Register", "\350\216\267\345\217\226\351\252\214\350\257\201\347\240\201", nullptr));
        ConfirmBtn->setText(QCoreApplication::translate("Register", "\347\241\256\350\256\244", nullptr));
        CancelBtn->setText(QCoreApplication::translate("Register", "\345\217\226\346\266\210", nullptr));
        tip_lb->setText(QCoreApplication::translate("Register", "\346\263\250\345\206\214\346\210\220\345\212\237, 5s\345\220\216\350\277\224\345\233\236\347\231\273\345\275\225", nullptr));
        label_2->setText(QCoreApplication::translate("Register", "\345\217\257\347\202\271\345\207\273\344\270\213\346\226\271\346\214\211\351\222\256\347\233\264\346\216\245\350\277\224\345\233\236\347\231\273\345\275\225", nullptr));
        return_btn->setText(QCoreApplication::translate("Register", "\350\277\224\345\233\236\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
