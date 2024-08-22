/********************************************************************************
** Form generated from reading UI file 'resetdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETDIALOG_H
#define UI_RESETDIALOG_H

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
#include <clickedlabel.h>
#include "timebtn.h"

QT_BEGIN_NAMESPACE

class Ui_ResetDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QWidget *ErrorTipswidget;
    QLabel *ErrorTipsLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *UserLabel;
    QLineEdit *UserEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *MailLabel;
    QLineEdit *MailEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *Codelabel;
    QLineEdit *CodeEdit;
    TimeBtn *GetCodeButton;
    QHBoxLayout *horizontalLayout_5;
    ClickedLabel *PasswdLabel;
    QLineEdit *PasswdEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ConfirmBtn;
    QPushButton *CancelBtn;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_2;

    void setupUi(QDialog *ResetDialog)
    {
        if (ResetDialog->objectName().isEmpty())
            ResetDialog->setObjectName("ResetDialog");
        ResetDialog->resize(300, 500);
        ResetDialog->setMinimumSize(QSize(300, 500));
        ResetDialog->setMaximumSize(QSize(300, 500));
        horizontalLayout = new QHBoxLayout(ResetDialog);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(ResetDialog);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        ErrorTipswidget = new QWidget(page);
        ErrorTipswidget->setObjectName("ErrorTipswidget");
        ErrorTipswidget->setEnabled(true);
        ErrorTipswidget->setMinimumSize(QSize(300, 25));
        ErrorTipswidget->setMaximumSize(QSize(300, 25));
        ErrorTipsLabel = new QLabel(ErrorTipswidget);
        ErrorTipsLabel->setObjectName("ErrorTipsLabel");
        ErrorTipsLabel->setGeometry(QRect(0, 0, 300, 25));
        ErrorTipsLabel->setMinimumSize(QSize(300, 25));
        ErrorTipsLabel->setMaximumSize(QSize(300, 25));
        ErrorTipsLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(ErrorTipswidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        UserLabel = new QLabel(page);
        UserLabel->setObjectName("UserLabel");
        UserLabel->setMinimumSize(QSize(0, 25));
        UserLabel->setMaximumSize(QSize(16777215, 25));
        UserLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_2->addWidget(UserLabel);

        UserEdit = new QLineEdit(page);
        UserEdit->setObjectName("UserEdit");
        UserEdit->setMinimumSize(QSize(0, 25));
        UserEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(UserEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        MailLabel = new QLabel(page);
        MailLabel->setObjectName("MailLabel");
        MailLabel->setMinimumSize(QSize(0, 25));
        MailLabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(MailLabel);

        MailEdit = new QLineEdit(page);
        MailEdit->setObjectName("MailEdit");
        MailEdit->setMinimumSize(QSize(0, 25));
        MailEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(MailEdit);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        Codelabel = new QLabel(page);
        Codelabel->setObjectName("Codelabel");
        Codelabel->setMinimumSize(QSize(0, 25));
        Codelabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_8->addWidget(Codelabel);

        CodeEdit = new QLineEdit(page);
        CodeEdit->setObjectName("CodeEdit");
        CodeEdit->setMinimumSize(QSize(0, 25));
        CodeEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_8->addWidget(CodeEdit);

        GetCodeButton = new TimeBtn(page);
        GetCodeButton->setObjectName("GetCodeButton");
        GetCodeButton->setMinimumSize(QSize(0, 25));
        GetCodeButton->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_8->addWidget(GetCodeButton);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        PasswdLabel = new ClickedLabel(page);
        PasswdLabel->setObjectName("PasswdLabel");
        PasswdLabel->setMinimumSize(QSize(0, 25));
        PasswdLabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(PasswdLabel);

        PasswdEdit = new QLineEdit(page);
        PasswdEdit->setObjectName("PasswdEdit");
        PasswdEdit->setMinimumSize(QSize(0, 25));
        PasswdEdit->setMaximumSize(QSize(16777215, 25));
        PasswdEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_5->addWidget(PasswdEdit);


        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        ConfirmBtn = new QPushButton(page);
        ConfirmBtn->setObjectName("ConfirmBtn");
        ConfirmBtn->setMinimumSize(QSize(0, 25));
        ConfirmBtn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(ConfirmBtn);

        CancelBtn = new QPushButton(page);
        CancelBtn->setObjectName("CancelBtn");
        CancelBtn->setMinimumSize(QSize(0, 25));
        CancelBtn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(CancelBtn);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(ResetDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ResetDialog);
    } // setupUi

    void retranslateUi(QDialog *ResetDialog)
    {
        ResetDialog->setWindowTitle(QCoreApplication::translate("ResetDialog", "Dialog", nullptr));
        ErrorTipsLabel->setText(QCoreApplication::translate("ResetDialog", "\351\224\231\350\257\257\346\217\220\347\244\272", nullptr));
        UserLabel->setText(QCoreApplication::translate("ResetDialog", "\347\224\250\346\210\267\357\274\232", nullptr));
        MailLabel->setText(QCoreApplication::translate("ResetDialog", "\351\202\256\347\256\261\357\274\232", nullptr));
        Codelabel->setText(QCoreApplication::translate("ResetDialog", "\351\252\214\350\257\201\347\240\201\357\274\232", nullptr));
        GetCodeButton->setText(QCoreApplication::translate("ResetDialog", "\350\216\267\345\217\226\351\252\214\350\257\201\347\240\201", nullptr));
        PasswdLabel->setText(QCoreApplication::translate("ResetDialog", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        ConfirmBtn->setText(QCoreApplication::translate("ResetDialog", "\347\241\256\350\256\244", nullptr));
        CancelBtn->setText(QCoreApplication::translate("ResetDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResetDialog: public Ui_ResetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETDIALOG_H
