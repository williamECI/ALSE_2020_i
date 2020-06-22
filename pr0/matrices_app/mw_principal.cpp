#include "mw_principal.h"
#include "ui_mw_principal.h"

MW_principal::MW_principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW_principal)
{
    ui->setupUi(this);
}

MW_principal::~MW_principal()
{
    delete ui;
}
