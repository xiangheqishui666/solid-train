#ifndef LYB_H
#define LYB_H

#include <QWidget>

namespace Ui {
class lyb;
}

class lyb : public QWidget
{
    Q_OBJECT

public:
    explicit lyb(QWidget *parent = nullptr);
    ~lyb();

private:
    Ui::lyb *ui;
};

#endif // LYB_H
