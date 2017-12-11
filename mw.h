#ifndef MW_H
#define MW_H

#include <QMainWindow>
#include "one.h"
#include "two.h"

namespace Ui {
class mw;
}

class mw : public QMainWindow
{
    Q_OBJECT

public:
    explicit mw(QWidget *parent = 0);
    one *wind_one;
    two *wind_two;
    ~mw();

private:
    Ui::mw *ui;
public slots:
    void vs();
};

#endif // MW_H
