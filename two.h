#ifndef TWO_H
#define TWO_H

#include <QMainWindow>

namespace Ui {
class two;
}

class two : public QMainWindow
{
    Q_OBJECT

public:
    explicit two(std::vector<int> vec1, std::vector<int> vec2, QWidget *parent = 0);
    ~two();

private:
    Ui::two *ui;
};

#endif // TWO_H
