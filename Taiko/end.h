#ifndef END_H
#define END_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class End;
}

class End : public QWidget
{
    Q_OBJECT

public:
    explicit End(QWidget *parent = 0);
    ~End();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::End *ui;
    QLabel *label;
};

#endif // END_H
