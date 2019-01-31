/********************************************************************************
** Form generated from reading UI file 'ML.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ML_H
#define UI_ML_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MLClass
{
public:
    QWidget *centralWidget;
    QTableWidget *tblData;
    QWidget *wColFilter;
    QLabel *lblColFil;
    QWidget *wTools;
    QHBoxLayout *horizontalLayout;
    QWidget *w1;
    QSplitter *splitter;
    QPushButton *btnData;
    QPushButton *btnTrain;
    QSpacerItem *horizontalSpacer;
    QWidget *wChoose;
    QSplitter *splitter_2;
    QLabel *lblMerge;
    QComboBox *cbCommon;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *cbxFilter;
    QSpacerItem *horizontalSpacer_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MLClass)
    {
        if (MLClass->objectName().isEmpty())
            MLClass->setObjectName(QString::fromUtf8("MLClass"));
        MLClass->resize(580, 617);
        centralWidget = new QWidget(MLClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tblData = new QTableWidget(centralWidget);
        tblData->setObjectName(QString::fromUtf8("tblData"));
        tblData->setEnabled(false);
        tblData->setGeometry(QRect(10, 110, 471, 471));
        wColFilter = new QWidget(centralWidget);
        wColFilter->setObjectName(QString::fromUtf8("wColFilter"));
        wColFilter->setGeometry(QRect(890, 20, 91, 51));
        lblColFil = new QLabel(wColFilter);
        lblColFil->setObjectName(QString::fromUtf8("lblColFil"));
        lblColFil->setGeometry(QRect(0, 0, 111, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        lblColFil->setFont(font);
        lblColFil->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        wTools = new QWidget(centralWidget);
        wTools->setObjectName(QString::fromUtf8("wTools"));
        wTools->setGeometry(QRect(10, 10, 471, 81));
        wTools->setMinimumSize(QSize(431, 81));
        horizontalLayout = new QHBoxLayout(wTools);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        w1 = new QWidget(wTools);
        w1->setObjectName(QString::fromUtf8("w1"));
        w1->setMinimumSize(QSize(108, 79));
        splitter = new QSplitter(w1);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(10, 10, 93, 56));
        splitter->setOrientation(Qt::Vertical);
        btnData = new QPushButton(splitter);
        btnData->setObjectName(QString::fromUtf8("btnData"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        btnData->setFont(font1);
        splitter->addWidget(btnData);
        btnTrain = new QPushButton(splitter);
        btnTrain->setObjectName(QString::fromUtf8("btnTrain"));
        btnTrain->setEnabled(false);
        btnTrain->setFont(font1);
        splitter->addWidget(btnTrain);

        horizontalLayout->addWidget(w1);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        wChoose = new QWidget(wTools);
        wChoose->setObjectName(QString::fromUtf8("wChoose"));
        wChoose->setMinimumSize(QSize(157, 79));
        splitter_2 = new QSplitter(wChoose);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(0, 10, 148, 51));
        splitter_2->setOrientation(Qt::Vertical);
        lblMerge = new QLabel(splitter_2);
        lblMerge->setObjectName(QString::fromUtf8("lblMerge"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(9);
        lblMerge->setFont(font2);
        splitter_2->addWidget(lblMerge);
        cbCommon = new QComboBox(splitter_2);
        cbCommon->addItem(QString());
        cbCommon->setObjectName(QString::fromUtf8("cbCommon"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbCommon->sizePolicy().hasHeightForWidth());
        cbCommon->setSizePolicy(sizePolicy);
        cbCommon->setFont(font1);
        splitter_2->addWidget(cbCommon);

        horizontalLayout->addWidget(wChoose);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        cbxFilter = new QCheckBox(wTools);
        cbxFilter->setObjectName(QString::fromUtf8("cbxFilter"));
        cbxFilter->setEnabled(false);
        cbxFilter->setFont(font2);
        cbxFilter->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout->addWidget(cbxFilter);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(2, 4);
        horizontalLayout->setStretch(4, 1);
        MLClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MLClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MLClass->setStatusBar(statusBar);

        retranslateUi(MLClass);

        QMetaObject::connectSlotsByName(MLClass);
    } // setupUi

    void retranslateUi(QMainWindow *MLClass)
    {
        MLClass->setWindowTitle(QApplication::translate("MLClass", "ML", nullptr));
        lblColFil->setText(QApplication::translate("MLClass", "Columns Filter:", nullptr));
        btnData->setText(QApplication::translate("MLClass", "Import Data", nullptr));
        btnTrain->setText(QApplication::translate("MLClass", "Train", nullptr));
        lblMerge->setText(QApplication::translate("MLClass", "Choose column to merge:", nullptr));
        cbCommon->setItemText(0, QApplication::translate("MLClass", "--Not Selected--", nullptr));

        cbxFilter->setText(QApplication::translate("MLClass", "Filter rows\n"
"with null values", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MLClass: public Ui_MLClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ML_H
