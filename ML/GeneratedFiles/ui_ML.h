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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
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
    QWidget *wChoose;
    QSplitter *splitter_2;
    QLabel *lblMerge;
    QComboBox *cbCommon;
    QCheckBox *cbxFilter;
    QSplitter *splitter;
    QPushButton *btnData;
    QPushButton *btnTrain;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MLClass)
    {
        if (MLClass->objectName().isEmpty())
            MLClass->setObjectName(QString::fromUtf8("MLClass"));
        MLClass->resize(780, 561);
        centralWidget = new QWidget(MLClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tblData = new QTableWidget(centralWidget);
        tblData->setObjectName(QString::fromUtf8("tblData"));
        tblData->setEnabled(false);
        tblData->setGeometry(QRect(20, 80, 741, 451));
        wChoose = new QWidget(centralWidget);
        wChoose->setObjectName(QString::fromUtf8("wChoose"));
        wChoose->setGeometry(QRect(160, 0, 161, 66));
        splitter_2 = new QSplitter(wChoose);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(0, 10, 148, 51));
        splitter_2->setOrientation(Qt::Vertical);
        lblMerge = new QLabel(splitter_2);
        lblMerge->setObjectName(QString::fromUtf8("lblMerge"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        lblMerge->setFont(font);
        splitter_2->addWidget(lblMerge);
        cbCommon = new QComboBox(splitter_2);
        cbCommon->addItem(QString());
        cbCommon->setObjectName(QString::fromUtf8("cbCommon"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbCommon->sizePolicy().hasHeightForWidth());
        cbCommon->setSizePolicy(sizePolicy);
        splitter_2->addWidget(cbCommon);
        cbxFilter = new QCheckBox(centralWidget);
        cbxFilter->setObjectName(QString::fromUtf8("cbxFilter"));
        cbxFilter->setEnabled(false);
        cbxFilter->setGeometry(QRect(650, 10, 111, 31));
        QFont font1;
        font1.setPointSize(9);
        cbxFilter->setFont(font1);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(20, 10, 93, 56));
        splitter->setOrientation(Qt::Vertical);
        btnData = new QPushButton(splitter);
        btnData->setObjectName(QString::fromUtf8("btnData"));
        splitter->addWidget(btnData);
        btnTrain = new QPushButton(splitter);
        btnTrain->setObjectName(QString::fromUtf8("btnTrain"));
        btnTrain->setEnabled(false);
        splitter->addWidget(btnTrain);
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
        lblMerge->setText(QApplication::translate("MLClass", "Choose column to merge:", nullptr));
        cbCommon->setItemText(0, QApplication::translate("MLClass", "--Not Selected--", nullptr));

        cbxFilter->setText(QApplication::translate("MLClass", "Filter rows\n"
"with null values", nullptr));
        btnData->setText(QApplication::translate("MLClass", "Import Data", nullptr));
        btnTrain->setText(QApplication::translate("MLClass", "Train", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MLClass: public Ui_MLClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ML_H
