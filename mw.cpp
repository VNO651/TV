#include "mw.h"
#include "ui_mw.h"

mw::mw(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mw)
{
    ui->setupUi(this);
    connect(ui->pb, SIGNAL(clicked(bool)), this, SLOT(vs()));
}

mw::~mw()
{
    delete ui;
}

void mw::vs()
{
    ui->label_error->clear();
    if (ui->le1->text().isEmpty()==true
            || ui->le2->text().isEmpty()==true)
    {
        ui->label_error->setText("Error! Fill both fields!");
        return;
    }
    if (ui->le1->text().length()!=ui->le2->text().length())
    {
        ui->label_error->setText("Error! Different lenght!");
        return;
    }
    QString str;
    std::vector<int> vec1;
    std::vector<int> vec2;
    str=ui->le1->text();
    for (int i=0; i<str.length(); i++)
    {
        bool ok;
        QString temp;
        temp=str[i];
        int x=temp.toInt(&ok);
        if (ok==false)
        {
            ui->label_error->setText("Error! Not int!");
            return;
        }
        if (x>1)
        {
            ui->label_error->setText("Error! Not 0,1 combination!");
            return;
        }
        vec1.push_back(x);
    }
    str=ui->le2->text();
    for (int i=0; i<str.length(); i++)
    {
        bool ok;
        QString temp;
        temp=str[i];
        int x=temp.toInt(&ok);
        if (ok==false)
        {

            ui->label_error->setText("Error! Not int!");
            return;
        }
        if (x>1)
        {
            ui->label_error->setText("Error! Not 0,1 combination!");
            return;
        }
        vec2.push_back(x);
    }
    int n11=0, n00=0, n10=0, n01=0;
    int p=0, q=0, n;
    int a1=0, a0=0, b1=0, b0=0;
    for (int i=0; i<(int)vec1.size(); i++)
    {
        if (vec1[i]==vec2[i])
            if (vec1[i]==1) n11++;
            else n00++;
        else
            if (vec1[i]==1) n10++;
            else n01++;
        if (vec1[i]==1) a1++;
        else a0++;
        if (vec2[i]==1) b1++;
        else b0++;

    }
    p=n11+n00;
    q=n10+n01;
    n=vec1.size();
//    str="n11="+QString::number(n11)+" n00="+QString::number(n00)
//            +" n10="+QString::number(n10)+" n01="+QString::number(n01)
//            +" a1="+QString::number(a1)+" a0="+QString::number(a0)
//            +" b1="+QString::number(b1)+" b0="+QString::number(b0)
//            +" p="+QString::number(p)+" q="+QString::number(q)
//            +" n="+QString::number(n);
//    ui->lineEdit->setText(str);

    double s_onn=p;
    s_onn/=n;
    double s_rao=n11;
    s_rao/=n;
    double s_xamman=(p-q);
    s_xamman/=n;
    double s_rogers=n11;
    s_rogers/=(a1+b1-n11);
    double s_gekkaard=n11;
    s_gekkaard/=(n11+q);
    double s_deik=2*n11;
    s_deik/=(2*n11+q);
    double s_onn2=n11;
    s_onn2/=(n11+2*q);
    double s_comp=p;
    s_comp/=(2*n-p);
    str="s_onn="+QString::number(s_onn)+" s_rao="+QString::number(s_rao)
            +" s_xam="+QString::number(s_xamman)+" s_roger="+QString::number(s_rogers)
            +" s_gekkard"+QString::number(s_gekkaard)+" s_deik="+QString::number(s_deik)
            +" s_onn2"+QString::number(s_onn2)+" s_comp="+QString::number(s_comp);
//    ui->label_error->setText(str);
    wind_one=new one(s_onn, s_rao, s_xamman, s_rogers, s_gekkaard, s_deik, s_onn2, s_comp);
    wind_one->show();
    wind_two=new two(vec1, vec2);
    wind_two->show();
}
