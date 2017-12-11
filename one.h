#ifndef ONE_H
#define ONE_H

#include <QMainWindow>

namespace Ui {
class one;
}

class one : public QMainWindow
{
    Q_OBJECT

public:
    explicit one(double s_onn, double s_rao,
    double s_xamman, double s_rogers,
    double s_gekkaard, double s_deik,
    double s_onn2, double s_comp, QWidget *parent = 0);
    ~one();

private:
    Ui::one *ui;
};

#endif // ONE_H
