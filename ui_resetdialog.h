/********************************************************************************
** Form generated from reading UI file 'resetdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
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
#include "clickedlabel.h"
#include "timebtn.h"

QT_BEGIN_NAMESPACE

class Ui_ResetDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_2;
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
    QLabel *PasswdLabel;
    QLineEdit *PasswdEdit;
    ClickedLabel *PasswdVisible;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ConfirmBtn;
    QPushButton *CancelBtn;
    QSpacerItem *verticalSpacer;
    QWidget *page_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *ReturnTipLabel;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer;
    QPushButton *ReturnBtn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QDialog *ResetDialog)
    {
        if (ResetDialog->objectName().isEmpty())
            ResetDialog->setObjectName("ResetDialog");
        ResetDialog->resize(300, 500);
        ResetDialog->setMinimumSize(QSize(300, 500));
        ResetDialog->setMaximumSize(QSize(300, 500));
        horizontalLayout = new QHBoxLayout(ResetDialog);
        horizontalLayout->setObjectName("horizontalLayout");
        stackedWidget = new QStackedWidget(ResetDialog);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_6->addItem(verticalSpacer_2);

        ErrorTipsLabel = new QLabel(page);
        ErrorTipsLabel->setObjectName("ErrorTipsLabel");
        ErrorTipsLabel->setMinimumSize(QSize(0, 25));
        ErrorTipsLabel->setMaximumSize(QSize(300, 25));
        ErrorTipsLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(ErrorTipsLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        UserLabel = new QLabel(page);
        UserLabel->setObjectName("UserLabel");
        UserLabel->setMinimumSize(QSize(0, 25));
        UserLabel->setMaximumSize(QSize(16777215, 25));
        UserLabel->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);

        horizontalLayout_2->addWidget(UserLabel);

        UserEdit = new QLineEdit(page);
        UserEdit->setObjectName("UserEdit");
        UserEdit->setMinimumSize(QSize(0, 25));
        UserEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(UserEdit);


        verticalLayout_6->addLayout(horizontalLayout_2);

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


        verticalLayout_6->addLayout(horizontalLayout_4);

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


        verticalLayout_6->addLayout(horizontalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        PasswdLabel = new QLabel(page);
        PasswdLabel->setObjectName("PasswdLabel");
        PasswdLabel->setMinimumSize(QSize(0, 25));
        PasswdLabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(PasswdLabel);

        PasswdEdit = new QLineEdit(page);
        PasswdEdit->setObjectName("PasswdEdit");
        PasswdEdit->setMinimumSize(QSize(0, 25));
        PasswdEdit->setMaximumSize(QSize(16777215, 25));
        PasswdEdit->setEchoMode(QLineEdit::EchoMode::Normal);

        horizontalLayout_5->addWidget(PasswdEdit);

        PasswdVisible = new ClickedLabel(page);
        PasswdVisible->setObjectName("PasswdVisible");
        PasswdVisible->setMinimumSize(QSize(20, 20));
        PasswdVisible->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_5->addWidget(PasswdVisible);


        verticalLayout_6->addLayout(horizontalLayout_5);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_6->addItem(verticalSpacer_7);

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


        verticalLayout_6->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_6->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout_6);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayoutWidget = new QWidget(page_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 281, 481));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer_4);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        ReturnTipLabel = new QLabel(verticalLayoutWidget);
        ReturnTipLabel->setObjectName("ReturnTipLabel");
        ReturnTipLabel->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        ReturnTipLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_10->addWidget(ReturnTipLabel);


        verticalLayout_3->addLayout(horizontalLayout_10);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        ReturnBtn = new QPushButton(verticalLayoutWidget);
        ReturnBtn->setObjectName("ReturnBtn");

        horizontalLayout_9->addWidget(ReturnBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_9);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer_5);

        stackedWidget->addWidget(page_2);

        horizontalLayout->addWidget(stackedWidget);


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
        PasswdVisible->setText(QString());
        ConfirmBtn->setText(QCoreApplication::translate("ResetDialog", "\347\241\256\350\256\244", nullptr));
        CancelBtn->setText(QCoreApplication::translate("ResetDialog", "\345\217\226\346\266\210", nullptr));
        ReturnTipLabel->setText(QCoreApplication::translate("ResetDialog", "\351\207\215\347\275\256\346\210\220\345\212\237\357\274\2145s\345\220\216\350\207\252\345\212\250\350\277\224\345\233\236\347\231\273\345\275\225\351\241\265", nullptr));
        label_2->setText(QCoreApplication::translate("ResetDialog", "\345\217\257\347\202\271\345\207\273\344\270\213\346\226\271\346\214\211\351\222\256\347\233\264\346\216\245\350\277\224\345\233\236\347\231\273\345\275\225", nullptr));
        ReturnBtn->setText(QCoreApplication::translate("ResetDialog", "\350\277\224\345\233\236\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResetDialog: public Ui_ResetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETDIALOG_H
