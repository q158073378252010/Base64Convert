#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QtCore>
#include <QtGui>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::convert()
{
    QString InputData = this->ui->base64_text_edit->toPlainText();
    QByteArray file_data =  QByteArray::fromBase64(InputData.trimmed().toUtf8());
    qDebug() << file_data.length() << file_data;
    QString output_filename = this->ui->file_name_line_edit->text().trimmed();
    QString path = QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).first();

    QString output = path+"/"+output_filename;
    qDebug() << output;
    QFile file(output);
    file.open(QIODevice::WriteOnly);
    file.write(file_data);
    file.close();
}
