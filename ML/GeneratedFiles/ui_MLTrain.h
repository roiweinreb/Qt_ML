/********************************************************************************
** Form generated from reading UI file 'MLTrain.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MLTRAIN_H
#define UI_MLTRAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *wScatter;
    QPushButton *btnCancel;
    QPushButton *btnOk;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *lblResponse;
    QComboBox *cbResponse;
    QLabel *lblRate;
    QComboBox *cbRate;
    QLabel *lblIter;
    QComboBox *cbIter;
    QWidget *wPredict;
    QFrame *frame;
    QSplitter *splitter_4;
    QSplitter *splitter_2;
    QLabel *lblPred;
    QLabel *lblPred_2;
    QSplitter *splitter_3;
    QComboBox *cbPreds;
    QDoubleSpinBox *dsbPreds;
    QSplitter *splitter_5;
    QPushButton *btnSet;
    QPushButton *btnPredict;
    QCheckBox *cbClamp;
    QWidget *wMssg;
    QLabel *lblMssg;
    QWidget *wClamp;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *lblClampMin;
    QLabel *lblClampMax;
    QDoubleSpinBox *cbMin;
    QDoubleSpinBox *cbMax;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(1193, 692);
        wScatter = new QWidget(Dialog);
        wScatter->setObjectName(QString::fromUtf8("wScatter"));
        wScatter->setGeometry(QRect(10, 190, 1151, 481));
        btnCancel = new QPushButton(Dialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(180, 70, 93, 22));
        btnOk = new QPushButton(Dialog);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        btnOk->setEnabled(true);
        btnOk->setGeometry(QRect(180, 40, 93, 22));
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 161, 161));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(layoutWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(11, 0, 14, 2);
        lblResponse = new QLabel(verticalLayoutWidget);
        lblResponse->setObjectName(QString::fromUtf8("lblResponse"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        lblResponse->setFont(font);

        verticalLayout->addWidget(lblResponse);

        cbResponse = new QComboBox(verticalLayoutWidget);
        cbResponse->setObjectName(QString::fromUtf8("cbResponse"));

        verticalLayout->addWidget(cbResponse);

        lblRate = new QLabel(verticalLayoutWidget);
        lblRate->setObjectName(QString::fromUtf8("lblRate"));
        lblRate->setFont(font);

        verticalLayout->addWidget(lblRate);

        cbRate = new QComboBox(verticalLayoutWidget);
        cbRate->addItem(QString());
        cbRate->addItem(QString());
        cbRate->addItem(QString());
        cbRate->addItem(QString());
        cbRate->addItem(QString());
        cbRate->setObjectName(QString::fromUtf8("cbRate"));

        verticalLayout->addWidget(cbRate);

        lblIter = new QLabel(verticalLayoutWidget);
        lblIter->setObjectName(QString::fromUtf8("lblIter"));
        lblIter->setFont(font);

        verticalLayout->addWidget(lblIter);

        cbIter = new QComboBox(verticalLayoutWidget);
        cbIter->addItem(QString());
        cbIter->addItem(QString());
        cbIter->addItem(QString());
        cbIter->addItem(QString());
        cbIter->addItem(QString());
        cbIter->setObjectName(QString::fromUtf8("cbIter"));

        verticalLayout->addWidget(cbIter);

        splitter->addWidget(verticalLayoutWidget);

        verticalLayout_3->addWidget(splitter);

        wPredict = new QWidget(Dialog);
        wPredict->setObjectName(QString::fromUtf8("wPredict"));
        wPredict->setGeometry(QRect(890, 10, 271, 161));
        frame = new QFrame(wPredict);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 260, 141));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(6);
        splitter_4 = new QSplitter(frame);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setGeometry(QRect(14, 10, 218, 51));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter_4->sizePolicy().hasHeightForWidth());
        splitter_4->setSizePolicy(sizePolicy);
        splitter_4->setOrientation(Qt::Horizontal);
        splitter_2 = new QSplitter(splitter_4);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        lblPred = new QLabel(splitter_2);
        lblPred->setObjectName(QString::fromUtf8("lblPred"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        lblPred->setFont(font1);
        splitter_2->addWidget(lblPred);
        lblPred_2 = new QLabel(splitter_2);
        lblPred_2->setObjectName(QString::fromUtf8("lblPred_2"));
        lblPred_2->setFont(font1);
        splitter_2->addWidget(lblPred_2);
        splitter_4->addWidget(splitter_2);
        splitter_3 = new QSplitter(splitter_4);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        cbPreds = new QComboBox(splitter_3);
        cbPreds->setObjectName(QString::fromUtf8("cbPreds"));
        splitter_3->addWidget(cbPreds);
        dsbPreds = new QDoubleSpinBox(splitter_3);
        dsbPreds->setObjectName(QString::fromUtf8("dsbPreds"));
        dsbPreds->setMaximum(10000.000000000000000);
        splitter_3->addWidget(dsbPreds);
        splitter_4->addWidget(splitter_3);
        splitter_5 = new QSplitter(frame);
        splitter_5->setObjectName(QString::fromUtf8("splitter_5"));
        splitter_5->setGeometry(QRect(40, 100, 188, 28));
        splitter_5->setOrientation(Qt::Horizontal);
        btnSet = new QPushButton(splitter_5);
        btnSet->setObjectName(QString::fromUtf8("btnSet"));
        splitter_5->addWidget(btnSet);
        btnPredict = new QPushButton(splitter_5);
        btnPredict->setObjectName(QString::fromUtf8("btnPredict"));
        btnPredict->setEnabled(false);
        splitter_5->addWidget(btnPredict);
        cbClamp = new QCheckBox(frame);
        cbClamp->setObjectName(QString::fromUtf8("cbClamp"));
        cbClamp->setGeometry(QRect(80, 70, 151, 28));
        cbClamp->setLayoutDirection(Qt::RightToLeft);
        wMssg = new QWidget(Dialog);
        wMssg->setObjectName(QString::fromUtf8("wMssg"));
        wMssg->setGeometry(QRect(290, 20, 581, 151));
        lblMssg = new QLabel(wMssg);
        lblMssg->setObjectName(QString::fromUtf8("lblMssg"));
        lblMssg->setGeometry(QRect(0, 0, 571, 141));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        lblMssg->setFont(font2);
        lblMssg->setFrameShape(QFrame::NoFrame);
        lblMssg->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        wClamp = new QWidget(Dialog);
        wClamp->setObjectName(QString::fromUtf8("wClamp"));
        wClamp->setGeometry(QRect(970, 200, 191, 81));
        formLayoutWidget = new QWidget(wClamp);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 0, 161, 71));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        lblClampMin = new QLabel(formLayoutWidget);
        lblClampMin->setObjectName(QString::fromUtf8("lblClampMin"));
        lblClampMin->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, lblClampMin);

        lblClampMax = new QLabel(formLayoutWidget);
        lblClampMax->setObjectName(QString::fromUtf8("lblClampMax"));
        lblClampMax->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, lblClampMax);

        cbMin = new QDoubleSpinBox(formLayoutWidget);
        cbMin->setObjectName(QString::fromUtf8("cbMin"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cbMin);

        cbMax = new QDoubleSpinBox(formLayoutWidget);
        cbMax->setObjectName(QString::fromUtf8("cbMax"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cbMax);

        wMssg->raise();
        wScatter->raise();
        btnCancel->raise();
        btnOk->raise();
        layoutWidget->raise();
        wPredict->raise();
        wClamp->raise();

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        btnCancel->setText(QApplication::translate("Dialog", "Cancel", nullptr));
        btnOk->setText(QApplication::translate("Dialog", "OK", nullptr));
        lblResponse->setText(QApplication::translate("Dialog", "Response:", nullptr));
        lblRate->setText(QApplication::translate("Dialog", "Learning Rate:", nullptr));
        cbRate->setItemText(0, QApplication::translate("Dialog", "5", nullptr));
        cbRate->setItemText(1, QApplication::translate("Dialog", "1", nullptr));
        cbRate->setItemText(2, QApplication::translate("Dialog", "0.1", nullptr));
        cbRate->setItemText(3, QApplication::translate("Dialog", "0.01", nullptr));
        cbRate->setItemText(4, QApplication::translate("Dialog", "0.001", nullptr));

        lblIter->setText(QApplication::translate("Dialog", "Max Iterations:", nullptr));
        cbIter->setItemText(0, QApplication::translate("Dialog", "3000", nullptr));
        cbIter->setItemText(1, QApplication::translate("Dialog", "2500", nullptr));
        cbIter->setItemText(2, QApplication::translate("Dialog", "2000", nullptr));
        cbIter->setItemText(3, QApplication::translate("Dialog", "1500", nullptr));
        cbIter->setItemText(4, QApplication::translate("Dialog", "1000", nullptr));

        lblPred->setText(QApplication::translate("Dialog", "Select predictor", nullptr));
        lblPred_2->setText(QApplication::translate("Dialog", "Set value", nullptr));
        btnSet->setText(QApplication::translate("Dialog", "Set", nullptr));
        btnPredict->setText(QApplication::translate("Dialog", "Predict", nullptr));
        cbClamp->setText(QApplication::translate("Dialog", "Clamp predictions", nullptr));
        lblMssg->setText(QApplication::translate("Dialog", "Building a linear regression model...", nullptr));
        lblClampMin->setText(QApplication::translate("Dialog", "Min:", nullptr));
        lblClampMax->setText(QApplication::translate("Dialog", "Max:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MLTRAIN_H
