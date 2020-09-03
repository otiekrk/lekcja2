#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QFile>
#include <QTextStream>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    void otworzPlik();
    void zapiszPlik();
    void czysc();

    QPushButton *btn_zapisz;
    QPushButton *btn_otworz;
    QPushButton *btn_czysc;
    QLineEdit *le_imie;
    QLineEdit *le_nazwisko;
    QLineEdit *le_telefon;
    QLineEdit *le_email;
    QLabel *lbl_imie;
    QLabel *lbl_nazwisko;
    QLabel *lbl_telefon;
    QLabel *lbl_email;
};
#endif // WIDGET_H
