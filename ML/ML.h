#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ML.h"

class ML : public QMainWindow
{
	Q_OBJECT

public:
	ML(QWidget *parent = Q_NULLPTR);

private:
	Ui::MLClass ui;
};
