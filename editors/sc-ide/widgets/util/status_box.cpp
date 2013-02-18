/*
    SuperCollider Qt IDE
    Copyright (c) 2012 - 2013 Jakob Leben & Tim Blechmann
    http://www.audiosynth.com

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
*/

#include "status_box.hpp"

namespace ScIDE {

StatusBox::StatusBox(QWidget *parent) : QLabel(parent)
{
    setAutoFillBackground(true);
    setMargin(3);
    setAlignment(Qt::AlignCenter);
    setBackground(Qt::black);
    setTextColor(Qt::white);

    QFont font("Monospace");
    font.setStyleHint(QFont::Monospace);
    font.setBold(true);
    setFont(font);
}

void StatusBox::setBackground(const QBrush & brush)
{
    QPalette plt(palette());
    plt.setBrush(QPalette::Window, brush);
    setPalette(plt);
}

void StatusBox::setTextColor(const QColor & color)
{
    QPalette plt(palette());
    plt.setColor(QPalette::WindowText, color);
    setPalette(plt);
}

void StatusBox::showContextMenu()
{
    QList<QAction*> actions = this->actions();
    if (actions.count()) {
        QMenu menu;
        foreach( QAction *action, actions )
            menu.addAction(action);
        menu.exec( mapToGlobal(QPoint(0, -menu.sizeHint().height() - 2)) );
    }
}

void StatusBox::mousePressEvent( QMouseEvent * )
{
    showContextMenu();
}

void StatusBox::addActionSeparator()
{
    QAction *separator = new QAction(this);
    separator->setSeparator(true);
    addAction(separator);
}

} // namespace ScIDE