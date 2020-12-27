#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter( QObject * object, QEvent * eve ){
    if (eve->type() == QEvent::KeyPress)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(eve);
        if (keyEvent->key() == Qt::Key_Left || keyEvent->key() == Qt::Key_Right || keyEvent->key() == Qt::Key_Z)
        {
            ui->GraphicsPresenter->keyPressEvent(keyEvent);
            return true;
        }
        else if (keyEvent->key() == Qt::Key_C)
        {
            QKeyEvent tempKeyEvent(QEvent::KeyRelease, Qt::Key_Left, Qt::NoModifier);
            ui->GraphicsPresenter->keyReleaseEvent(&tempKeyEvent);
            tempKeyEvent = QKeyEvent(QEvent::KeyRelease, Qt::Key_Right, Qt::NoModifier);
            ui->GraphicsPresenter->keyReleaseEvent(&tempKeyEvent);

            ui->GraphicsPresenter->keyPressEvent(keyEvent);
            return true;
        }
        else if (keyEvent->isAutoRepeat()) return false;
        else if (keyEvent->key() == Qt::Key_Space    || keyEvent->key() == Qt::Key_Down  ||
                 keyEvent->key() == Qt::Key_H        || keyEvent->key() == Qt::Key_5 ||
                 keyEvent->key() == Qt::Key_1        || keyEvent->key() == Qt::Key_2 ||
                 keyEvent->key() == Qt::Key_3        || keyEvent->key() == Qt::Key_4 ||
                 keyEvent->key() == Qt::Key_Return)
        {
            ui->GraphicsPresenter->keyPressEvent(keyEvent);
            return true;
        }
        if (keyEvent->key() == Qt::Key_Escape) close();
    }
    if (eve->type() == QEvent::KeyRelease)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(eve);
        if (keyEvent->key() == Qt::Key_Space    || keyEvent->key() == Qt::Key_Down  ||
            keyEvent->key() == Qt::Key_Left     || keyEvent->key() == Qt::Key_Right ||
            keyEvent->key() == Qt::Key_H        || keyEvent->key() == Qt::Key_5 ||
            keyEvent->key() == Qt::Key_1        || keyEvent->key() == Qt::Key_2 ||
            keyEvent->key() == Qt::Key_3        || keyEvent->key() == Qt::Key_4 ||
            keyEvent->key() == Qt::Key_C        || keyEvent->key() == Qt::Key_Z ||
            keyEvent->key() == Qt::Key_Return)
        {
            ui->GraphicsPresenter->keyReleaseEvent(keyEvent);
            return true;
        }
    }
    return false;
}
