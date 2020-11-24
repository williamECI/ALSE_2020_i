#ifndef ESTACION_INTERFACE_H
#define ESTACION_INTERFACE_H

#include <QMainWindow>

namespace Ui {
class Estacion_interface;
}

class Estacion_interface : public QMainWindow
{
    Q_OBJECT

public:
    void escribir_GUI(int dia, float t , unsigned char h , float v , int d , double la , double lo , double a);
    explicit Estacion_interface(QWidget *parent = 0);
    ~Estacion_interface();

private:
    Ui::Estacion_interface *ui;
};

#endif // ESTACION_INTERFACE_H
