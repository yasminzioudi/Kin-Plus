#ifndef BUTTONDELEGATE_H
#define BUTTONDELEGATE_H


#include <QItemDelegate>
#include <QPainter>
#include <QPushButton>

class ButtonDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit ButtonDelegate(QObject *parent = nullptr) : QItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        if (index.column() == 5) // Changez cela pour correspondre à la colonne où vous voulez les boutons
        {
            QPushButton button1;
            button1.resize(40, 40);
            button1.setIcon(QIcon(":/icon_tabN/ressource/icon_n/icon_tabN/delete.png"));
            button1.setIconSize(QSize(30, 30));
            button1.setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                  "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");

            // Ajoutez d'autres boutons ici si nécessaire...

            painter->save();

            painter->translate(option.rect.topLeft());
            button1.render(painter);

            painter->restore();
        }
        else
        {
            QItemDelegate::paint(painter, option, index);
        }
    }
};

#endif // BUTTONDELEGATE_H











