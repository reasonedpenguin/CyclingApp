/*
 * SearchWidget.cpp
 *
 *  Created on: Dec 31, 2014
 *      Author: jason
 */


#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QPainter>
#include <QApplication>
#include <QPalette>
#include <QStyleOption>
#include <QTimer>
#include <QDebug>
#include "SearchWidget.h"

#include "ui_SearchWidgetBase.h"

SearchWidget::SearchWidget(QWidget* parent) : QWidget(parent){
    ui = new Ui::SearchWidgetBase();
    ui->setupUi(this);
    ui->lineEdit->installEventFilter(this);

    m_timer = new QTimer;
    m_timer->setSingleShot(true);

    connect(ui->lineEdit,SIGNAL(textChanged(const QString&)),this,SLOT(slot_textChanged(const QString&)));
    //connect(ui->lineEdit,SIGNAL(editingFinished()),this,SLOT(slot_timeout()));
    connect(ui->clearButton,SIGNAL(clicked()),this,SLOT(slot_clear()));
    connect(m_timer,SIGNAL(timeout()),this,SLOT(slot_timeout()));
    updateStyleSheet();
}

SearchWidget::~SearchWidget() {
    // TODO Auto-generated destructor stub
}

void SearchWidget::paintEvent(QPaintEvent *)
{
     QStyleOption opt;
     opt.init(this);
     QPainter p(this);
     style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

bool SearchWidget::eventFilter(QObject * obj, QEvent * event) {
    if(obj == ui->lineEdit) {
        if(event->type() == QEvent::QEvent::FocusIn || event->type() == QEvent::QEvent::FocusOut) {
            updateStyleSheet();
        }
    }
}


void SearchWidget::updateStyleSheet() {
    QColor background = palette().color(QPalette::Base);
    QColor borderColor = palette().color(QPalette::Dark);
    if(ui->lineEdit->hasFocus()) {
        borderColor = palette().color(QPalette::Highlight);
    }

    QString style = QString(
            "SearchWidget {"
            "background-color: %1;"
            "border-style: solid;"
            "border-width: 1px;"
            "border-color: %2;"
            "margin: 0;"
            "padding: 0;}").arg(background.name()).arg(borderColor.name());
    //qDebug() << style << endl;
    setStyleSheet(style);
}

void SearchWidget::slot_textChanged(const QString& text) {
    if(text.isEmpty()) {
        ui->clearButton->setIcon(QPixmap(":/images/search.png"));
    } else {
        ui->clearButton->setIcon(QPixmap(":/images/clear.png"));
    }
    m_timer->start(500);
}

void SearchWidget::slot_clear() {
    ui->lineEdit->setText(QString());
    emit searchCleared();
    slot_timeout();
}

void SearchWidget::slot_timeout() {
    m_timer->stop();
    emit searchChanged(ui->lineEdit->text());
}

