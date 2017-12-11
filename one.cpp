#include "one.h"
#include "ui_one.h"

one::one(double s_onn, double s_rao, double s_xamman, double s_rogers, double s_gekkaard, double s_deik, double s_onn2, double s_comp, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::one)
{
    ui->setupUi(this);
    ui->lcd_onn->display(s_onn);
    ui->lcd_rao->display(s_rao);
    ui->lcd_xammana->display(s_xamman);
    ui->lcd_rogersa->display(s_rogers);
    ui->lcd_gekkarda->display(s_gekkaard);
    ui->lcd_deika->display(s_deik);
    ui->lcd_onn2->display(s_onn2);
    ui->lcd_compozition->display(s_comp);
}

one::~one()
{
    delete ui;
}
