#ifndef M_H
#define M_H

#include <QMainWindow>

namespace Ui {
class M;
}

class M : public QMainWindow
{
    Q_OBJECT

public:
    explicit M(QWidget *parent = 0);
    ~M();

private:
    Ui::M *ui;
};

#endif // M_H
