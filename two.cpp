#include "two.h"
#include "ui_two.h"
#include "cmath"
two::two(std::vector<int>vec1, std::vector<int> vec2, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::two)
{
    ui->setupUi(this);
    int size=vec1.size();
    ui->tableR->setRowCount(4);
    ui->tableR->setColumnCount(size);
    for (int row=0; row<ui->tableR->rowCount(); row++)
        for (int col=0; col<ui->tableR->columnCount(); col++)
            ui->tableR->setItem(row, col, new QTableWidgetItem());
    ui->tableR->setVerticalHeaderLabels(QStringList()
                                        <<"x(i)"<<"Rang"
                                        <<"y(i)"<<"Rang");
    ui->tableR->horizontalHeader()->hide();
    std::vector<int> vec1_ranging;
    std::vector<int> vec2_ranging;
    int count=0;
    if (size>15)
    {
        for (int i=0; i<(int)(log(size)/log(1.3)); i++)
        {
            if (vec1[i]==1) vec1_ranging.push_back(1);
            else vec1_ranging.push_back(2);
            if (vec2[i]==1) vec2_ranging.push_back(1);
            else vec2_ranging.push_back(2);
        }
        int first=(int)(log(size)/log(1.3));
        int last=(int)(log(size)/log(2));
        last=size-last;
        count=5;
        int temp=first+10;
        for (int i=last; i<size; i++)
        {
            if (vec1[i]==1) vec1_ranging.push_back(count);
            else vec1_ranging.push_back(count+1);
            if (vec2[i]==1) vec2_ranging.push_back(count);
            else vec2_ranging.push_back(count+1);
        }
        count+=2;
        while (temp<last)
        {
            for (int i=first; i<temp;i++)
            {
                if (vec1[i]==1) vec1_ranging.push_back(count);
                else vec1_ranging.push_back(count+1);
                if (vec2[i]==1) vec2_ranging.push_back(count);
                else vec2_ranging.push_back(count+1);
            }
            first=temp;
            temp+=10;
            count+=2;
        }
        for(int i=first; i<last; i++)
        {
            if (vec1[i]==1) vec1_ranging.push_back(3);
            else vec1_ranging.push_back(4);
            if (vec2[i]==1) vec2_ranging.push_back(3);
            else vec2_ranging.push_back(4);
        }
    }
    else
    {
        for (int i=0; i<(int)(size*0.4); i++)
        {
            if (vec1[i]==1) vec1_ranging.push_back(1);
            else vec1_ranging.push_back(2);
            if (vec2[i]==1) vec2_ranging.push_back(1);
            else vec2_ranging.push_back(2);
        }
        for (int i=(int)(size*0.4); i<(int)(size*0.75); i++)
        {
            if (vec1[i]==1) vec1_ranging.push_back(5);
            else vec1_ranging.push_back(6);
            if (vec2[i]==1) vec2_ranging.push_back(5);
            else vec2_ranging.push_back(6);
        }
        for (int i=(int)(size*0.75); i<size; i++)
        {
            if (vec1[i]==1) vec1_ranging.push_back(3);
            else vec1_ranging.push_back(4);
            if (vec2[i]==1) vec2_ranging.push_back(3);
            else vec2_ranging.push_back(4);
        }
        count=6;
    }
    for (int i=0; i<size; i++)
    {
        ui->tableR->item(0, i)->setText(QString::number(vec1[i]));
        ui->tableR->item(1, i)->setText(QString::number(vec1_ranging[i]));
        ui->tableR->item(2, i)->setText(QString::number(vec2[i]));
        ui->tableR->item(3, i)->setText(QString::number(vec2_ranging[i]));
    }
    ui->tableR->resizeColumnsToContents();

    std::vector<int> rangX;
    std::vector<int> rangY;
    rangX.resize(count-1);
    rangY.resize(count-1);
    for (int rang=1; rang<=count; rang++)
        for (int i=0; i<size; i++)
        {
            if (vec1_ranging[i]==rang) rangX[rang-1]++;
            if (vec2_ranging[i]==rang) rangY[rang-1]++;
        }

    ui->tableX->setRowCount(4);
    ui->tableX->setColumnCount(rangX.size());
    for (int row=0; row<ui->tableX->rowCount(); row++)
        for (int col=0; col<ui->tableX->columnCount(); col++)
        {
            ui->tableX->setItem(row, col, new QTableWidgetItem());
            ui->tableX->setItem(row, col, new QTableWidgetItem());
        }
    ui->tableX->setVerticalHeaderLabels(QStringList()<<"Rx(i)"<<"n(i)"<<"p*(i))"<<"F(x)");
    ui->tableX->horizontalHeader()->hide();

    ui->tableY->setRowCount(4);
    ui->tableY->setColumnCount(rangY.size());
    for (int row=0; row<ui->tableY->rowCount(); row++)
        for (int col=0; col<ui->tableY->columnCount(); col++)
        {
            ui->tableY->setItem(row, col, new QTableWidgetItem());
            ui->tableY->setItem(row, col, new QTableWidgetItem());
        }
    ui->tableY->setVerticalHeaderLabels(QStringList()<<"Ry(i)"<<"n(i)"<<"p*(i))"<<"F(y)");
    ui->tableY->horizontalHeader()->hide();

    std::vector<double> fX;
    std::vector<double> fY;
    fX.resize(count-1);
    fY.resize(count-1);
    double fucking_size=size;
    for (int i=0; i<count-1; i++)
        for(int j=0; j<=i; j++)
        {
            fX[i]+=rangX[j]/fucking_size;
            fY[i]+=rangY[j]/fucking_size;
        }
    for (int i=0; i<(int)rangX.size(); i++)
    {
        QString str;
        str=QString::number(rangX[i]/fucking_size);
        if (str.length()>5) str.resize(5);
        ui->tableX->item(0, i)->setText(QString::number(i+1));
        ui->tableX->item(1, i)->setText(QString::number(rangX[i]));
        ui->tableX->item(2, i)->setText(str);
        str=QString::number(fX[i]);
        if (str.length()>5) str.resize(5);
        ui->tableX->item(3, i)->setText(str);
        str=QString::number(rangY[i]/fucking_size);
        if (str.length()>5) str.resize(5);
        ui->tableY->item(0, i)->setText(QString::number(i+1));
        ui->tableY->item(1, i)->setText(QString::number(rangY[i]));
        ui->tableY->item(2, i)->setText(str);
        str=QString::number(fY[i]);
        if (str.length()>5) str.resize(5);
        ui->tableY->item(3, i)->setText(str);
    }
    ui->tableX->resizeRowsToContents();
    ui->tableY->resizeRowsToContents();
    ui->tableX->resizeColumnsToContents();
    ui->tableY->resizeColumnsToContents();
    int len=ui->tableX->columnWidth(0);
    int number=ui->tableX->columnCount()+1;
    int height=ui->tableX->height();
    if (number<15)
    {
        ui->tableX->resize(len*number+1, height);
        ui->tableY->resize(len*number+1, height);
    }
    len=ui->tableR->columnWidth(0);
    number=ui->tableR->columnCount()+1;
    height=ui->tableR->height();
    if (number<15)
    {
        ui->tableR->resize(len*number+1, height-20);
        resize(len*number+20, this->height());
    }
    double sum=0;
    for (int i=0; i<(int)rangX.size(); i++)
    {
        double x=fX[i]-fY[i];
        sum+=pow(x,2);
    }
    ui->lcd->display(sum);
}

two::~two()
{
    delete ui;
}
