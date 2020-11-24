/********************************************************************************
** Form generated from reading UI file 'estacion_interface.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESTACION_INTERFACE_H
#define UI_ESTACION_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Estacion_interface
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QSplitter *splitter_7;
    QLabel *label_7;
    QLineEdit *txt_longitud;
    QSplitter *splitter_6;
    QLabel *label_6;
    QLineEdit *txt_latitud;
    QSplitter *splitter;
    QLabel *label;
    QLineEdit *txt_Altura;
    QLabel *label_9;
    QGroupBox *groupBox_2;
    QSplitter *splitter_2;
    QLabel *label_2;
    QLineEdit *txt_temperatura;
    QSplitter *splitter_3;
    QLabel *label_3;
    QLineEdit *txt_humedad;
    QSplitter *splitter_4;
    QLabel *label_4;
    QLineEdit *txt_vel_viento;
    QSplitter *splitter_5;
    QLabel *label_5;
    QLineEdit *txt_dir_viento;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_8;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_17;
    QLineEdit *txt_dia;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Estacion_interface)
    {
        if (Estacion_interface->objectName().isEmpty())
            Estacion_interface->setObjectName(QStringLiteral("Estacion_interface"));
        Estacion_interface->resize(322, 379);
        Estacion_interface->setMinimumSize(QSize(322, 379));
        Estacion_interface->setMaximumSize(QSize(322, 379));
        Estacion_interface->setStyleSheet(QLatin1String("background-color: rgb(114, 159, 207);\n"
"gridline-color: rgb(204, 0, 0);"));
        centralWidget = new QWidget(Estacion_interface);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(9, 19, 301, 121));
        groupBox->setStyleSheet(QLatin1String("background-color: rgb(211, 215, 207);\n"
"border-top-color: rgb(136, 138, 133);"));
        splitter_7 = new QSplitter(groupBox);
        splitter_7->setObjectName(QStringLiteral("splitter_7"));
        splitter_7->setGeometry(QRect(10, 60, 209, 25));
        splitter_7->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(splitter_7);
        label_7->setObjectName(QStringLiteral("label_7"));
        splitter_7->addWidget(label_7);
        txt_longitud = new QLineEdit(splitter_7);
        txt_longitud->setObjectName(QStringLiteral("txt_longitud"));
        txt_longitud->setStyleSheet(QStringLiteral("background-color: rgb(238, 238, 236);"));
        txt_longitud->setInputMethodHints(Qt::ImhDigitsOnly);
        txt_longitud->setReadOnly(true);
        splitter_7->addWidget(txt_longitud);
        splitter_6 = new QSplitter(groupBox);
        splitter_6->setObjectName(QStringLiteral("splitter_6"));
        splitter_6->setGeometry(QRect(10, 30, 209, 25));
        splitter_6->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(splitter_6);
        label_6->setObjectName(QStringLiteral("label_6"));
        splitter_6->addWidget(label_6);
        txt_latitud = new QLineEdit(splitter_6);
        txt_latitud->setObjectName(QStringLiteral("txt_latitud"));
        txt_latitud->setCursor(QCursor(Qt::IBeamCursor));
        txt_latitud->setAutoFillBackground(false);
        txt_latitud->setStyleSheet(QStringLiteral("background-color: rgb(238, 238, 236);"));
        txt_latitud->setInputMethodHints(Qt::ImhDigitsOnly);
        txt_latitud->setReadOnly(true);
        splitter_6->addWidget(txt_latitud);
        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(10, 90, 209, 25));
        splitter->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter);
        label->setObjectName(QStringLiteral("label"));
        splitter->addWidget(label);
        txt_Altura = new QLineEdit(splitter);
        txt_Altura->setObjectName(QStringLiteral("txt_Altura"));
        txt_Altura->setStyleSheet(QStringLiteral("background-color: rgb(238, 238, 236);"));
        txt_Altura->setInputMethodHints(Qt::ImhDigitsOnly);
        txt_Altura->setReadOnly(true);
        splitter->addWidget(txt_Altura);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(230, 90, 67, 17));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(9, 149, 301, 151));
        groupBox_2->setAutoFillBackground(false);
        groupBox_2->setStyleSheet(QStringLiteral("background-color: rgb(211, 215, 207);"));
        splitter_2 = new QSplitter(groupBox_2);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(10, 30, 209, 25));
        splitter_2->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        splitter_2->addWidget(label_2);
        txt_temperatura = new QLineEdit(splitter_2);
        txt_temperatura->setObjectName(QStringLiteral("txt_temperatura"));
        txt_temperatura->setStyleSheet(QStringLiteral("background-color: rgb(238, 238, 236);"));
        txt_temperatura->setInputMethodHints(Qt::ImhDigitsOnly);
        txt_temperatura->setReadOnly(true);
        splitter_2->addWidget(txt_temperatura);
        splitter_3 = new QSplitter(groupBox_2);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(10, 60, 209, 25));
        splitter_3->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        splitter_3->addWidget(label_3);
        txt_humedad = new QLineEdit(splitter_3);
        txt_humedad->setObjectName(QStringLiteral("txt_humedad"));
        txt_humedad->setStyleSheet(QStringLiteral("background-color: rgb(238, 238, 236);"));
        txt_humedad->setInputMethodHints(Qt::ImhDigitsOnly);
        txt_humedad->setReadOnly(true);
        splitter_3->addWidget(txt_humedad);
        splitter_4 = new QSplitter(groupBox_2);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setGeometry(QRect(10, 90, 209, 25));
        splitter_4->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(splitter_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        splitter_4->addWidget(label_4);
        txt_vel_viento = new QLineEdit(splitter_4);
        txt_vel_viento->setObjectName(QStringLiteral("txt_vel_viento"));
        txt_vel_viento->setStyleSheet(QStringLiteral("background-color: rgb(238, 238, 236);"));
        txt_vel_viento->setInputMethodHints(Qt::ImhDigitsOnly);
        txt_vel_viento->setReadOnly(true);
        splitter_4->addWidget(txt_vel_viento);
        splitter_5 = new QSplitter(groupBox_2);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setGeometry(QRect(10, 120, 209, 25));
        splitter_5->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(splitter_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        splitter_5->addWidget(label_5);
        txt_dir_viento = new QLineEdit(splitter_5);
        txt_dir_viento->setObjectName(QStringLiteral("txt_dir_viento"));
        txt_dir_viento->setStyleSheet(QStringLiteral("background-color: rgb(238, 238, 236);"));
        txt_dir_viento->setInputMethodHints(Qt::ImhDigitsOnly);
        txt_dir_viento->setReadOnly(true);
        splitter_5->addWidget(txt_dir_viento);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(230, 30, 67, 17));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(230, 60, 67, 17));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(230, 90, 67, 17));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(230, 120, 67, 17));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(100, 0, 130, 17));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 310, 191, 21));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(widget);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout->addWidget(label_17);

        txt_dia = new QLineEdit(widget);
        txt_dia->setObjectName(QStringLiteral("txt_dia"));
        txt_dia->setInputMethodHints(Qt::ImhDigitsOnly);
        txt_dia->setReadOnly(true);

        horizontalLayout->addWidget(txt_dia);

        Estacion_interface->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Estacion_interface);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 322, 22));
        Estacion_interface->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Estacion_interface);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Estacion_interface->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Estacion_interface);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Estacion_interface->setStatusBar(statusBar);

        retranslateUi(Estacion_interface);

        QMetaObject::connectSlotsByName(Estacion_interface);
    } // setupUi

    void retranslateUi(QMainWindow *Estacion_interface)
    {
        Estacion_interface->setWindowTitle(QApplication::translate("Estacion_interface", "Estaci\303\263n Meteorol\303\263gica", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Estacion_interface", "Coordenadas Geograficas", Q_NULLPTR));
        label_7->setText(QApplication::translate("Estacion_interface", "Longitud", Q_NULLPTR));
        label_6->setText(QApplication::translate("Estacion_interface", "Latitud", Q_NULLPTR));
        label->setText(QApplication::translate("Estacion_interface", "Altura", Q_NULLPTR));
        label_9->setText(QApplication::translate("Estacion_interface", "m.s.n.m", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Estacion_interface", "Datos Meteorol\303\263gicos", Q_NULLPTR));
        label_2->setText(QApplication::translate("Estacion_interface", "Temperatura", Q_NULLPTR));
        label_3->setText(QApplication::translate("Estacion_interface", "Humedad", Q_NULLPTR));
        label_4->setText(QApplication::translate("Estacion_interface", "Velocidad del viento", Q_NULLPTR));
        label_5->setText(QApplication::translate("Estacion_interface", "Direcci\303\263n del viento", Q_NULLPTR));
        label_10->setText(QApplication::translate("Estacion_interface", "\302\260C", Q_NULLPTR));
        label_11->setText(QApplication::translate("Estacion_interface", "%", Q_NULLPTR));
        label_12->setText(QApplication::translate("Estacion_interface", "km/h", Q_NULLPTR));
        label_13->setText(QApplication::translate("Estacion_interface", "\302\260", Q_NULLPTR));
        label_8->setText(QApplication::translate("Estacion_interface", "Estaci\303\263n : EMB1ECI", Q_NULLPTR));
        label_17->setText(QApplication::translate("Estacion_interface", "Dias muestreados :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Estacion_interface: public Ui_Estacion_interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESTACION_INTERFACE_H
