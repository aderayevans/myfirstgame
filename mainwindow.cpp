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
        if (keyEvent->key() == Qt::Key_Left || keyEvent->key() == Qt::Key_Right)
        {
            ui->GraphicsPresenter->keyPressEvent(keyEvent);
            return true;
        }
        else if (keyEvent->isAutoRepeat()) return false;
        else if (keyEvent->key() == Qt::Key_Space    || keyEvent->key() == Qt::Key_Down  ||
            keyEvent->key() == Qt::Key_Left     || keyEvent->key() == Qt::Key_Right ||
            keyEvent->key() == Qt::Key_C        || keyEvent->key() == Qt::Key_Z     ||
            keyEvent->key() == Qt::Key_Return)
        {
            ui->GraphicsPresenter->keyPressEvent(keyEvent);
            return true;
        }
        if (keyEvent->key() == Qt::Key_Escape) close();
        //if (keyEven->isAutoRepeat())
    }
    if (eve->type() == QEvent::KeyRelease)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(eve);
        if (keyEvent->isAutoRepeat()) return false;
        else if (keyEvent->key() == Qt::Key_Space    || keyEvent->key() == Qt::Key_Down  ||
            keyEvent->key() == Qt::Key_Left     || keyEvent->key() == Qt::Key_Right ||
            keyEvent->key() == Qt::Key_C        || keyEvent->key() == Qt::Key_Z     ||
            keyEvent->key() == Qt::Key_Return)
        {
            ui->GraphicsPresenter->keyReleaseEvent(keyEvent);
            return true;
        }
    }
    return false;
}
