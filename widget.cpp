#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout(this);

    lbl_imie = new QLabel("Imie",this);
    grid->addWidget(lbl_imie,0,0,1,2);

    lbl_nazwisko = new QLabel("Nazwisko",this);
    grid->addWidget(lbl_nazwisko,1,0,1,2);

    lbl_telefon = new QLabel("Telefon",this);
    grid->addWidget(lbl_telefon,2,0,1,2);

    lbl_email = new QLabel("Email",this);
    grid->addWidget(lbl_email,3,0,1,2);

    le_imie = new QLineEdit(this);
    grid->addWidget(le_imie,0,2);

    le_nazwisko = new QLineEdit(this);
    grid->addWidget(le_nazwisko,1,2);

    le_telefon = new QLineEdit(this);
    grid->addWidget(le_telefon,2,2);

    le_email = new QLineEdit(this);
    grid->addWidget(le_email,3,2);

    btn_otworz = new QPushButton("Otworz",this);
    connect(btn_otworz,&QPushButton::clicked,this,&Widget::otworzPlik);
    grid->addWidget(btn_otworz,4,0);

    btn_zapisz = new QPushButton("Zapisz",this);
    connect(btn_zapisz,&QPushButton::clicked,this,&Widget::zapiszPlik);
    grid->addWidget(btn_zapisz,4,1);

    btn_czysc = new QPushButton("Czysc",this);
    connect(btn_czysc,&QPushButton::clicked,this,&Widget::czysc);
    grid->addWidget(btn_czysc,4,2);

    setLayout(grid);
}

Widget::~Widget()
{
}

void Widget::otworzPlik(){
    QString nazwaPliku = QFileDialog::getOpenFileName(this,"Otworz plik","","*.wizytowka");
    if (nazwaPliku == ""){return;}
    QFile plik(nazwaPliku);
    QTextStream strumienWejscia(&plik);
    if (plik.open(QIODevice::ReadOnly)){
        le_imie->setText(strumienWejscia.readLine());
        le_nazwisko->setText(strumienWejscia.readLine());
        le_telefon->setText(strumienWejscia.readLine());
        le_email->setText(strumienWejscia.readLine());
    }else{
        QMessageBox::critical(this,"Blad","Nie mozna otworzyc pliku " + nazwaPliku + "!");
    }
    plik.close();
}

void Widget::zapiszPlik(){
    QString nazwaPliku = QFileDialog::getSaveFileName(this,"Zapisz plik","","*.wizytowka");
    if (nazwaPliku == ""){return;}
    nazwaPliku.append(".wizytowka");
    QFile plik(nazwaPliku);
    QTextStream strumienWyjscia(&plik);
    if (plik.open(QIODevice::WriteOnly)){
        strumienWyjscia << le_imie->text() << Qt::endl;
        strumienWyjscia << le_nazwisko->text() << Qt::endl;
        strumienWyjscia << le_telefon->text() << Qt::endl;
        strumienWyjscia << le_email->text() << Qt::endl;
    }else{
        QMessageBox::critical(this,"Blad","Nie mozna otworzyc pliku " + nazwaPliku + " do zapisu!");
        return;
    }
    plik.close();
    QMessageBox::information(this,"Zrobione","Zapisano pomyslnie wizytowke");
}

void Widget::czysc(){
    le_imie->setText("");
    le_nazwisko->setText("");
    le_telefon->setText("");
    le_email->setText("");
}
