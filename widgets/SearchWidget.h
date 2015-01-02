/*
 * SearchWidget.h
 *
 *  Created on: Dec 31, 2014
 *      Author: jason
 */

#ifndef WIDGETS_SEARCHWIDGET_H_
#define WIDGETS_SEARCHWIDGET_H_

#include <QWidget>
#include <QString>

class QPushButton;
class QLineEdit;
class QTimer;

namespace Ui {class SearchWidgetBase;}


class SearchWidget : public QWidget {
    Q_OBJECT
public:
    SearchWidget(QWidget* parent);
    virtual ~SearchWidget();

    bool eventFilter(QObject * watched, QEvent * event);

protected:
    virtual void paintEvent(QPaintEvent *);

    void updateStyleSheet();

signals:
    void searchChanged(const QString& searchString);
    void searchCleared();

protected slots:

    void slot_textChanged(const QString& text);
    void slot_clear();
    void slot_timeout();

protected:
    Ui::SearchWidgetBase* ui;
    QTimer* m_timer;
};

#endif /* WIDGETS_SEARCHWIDGET_H_ */
