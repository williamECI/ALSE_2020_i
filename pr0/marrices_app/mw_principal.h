#ifndef MW_PRINCIPAL_H
#define MW_PRINCIPAL_H

#include <QMainWindow>

namespace Ui {
class MW_principal;
}

class MW_principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit MW_principal(QWidget *parent = 0);
    ~MW_principal();

private:
    Ui::MW_principal *ui;
};

#endif // MW_PRINCIPAL_H
