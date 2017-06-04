#include <QVBoxLayout>
#include <QLabel>

#include "welcome_screen.h"

WelcomeScreen::WelcomeScreen (QWidget * parent) :
    QWidget(parent) {

    setLayout(m_verticalLayout);
    m_verticalLayout->setAlignment(Qt::AlignCenter);

    QFont font = QFont(m_label->font());
    font.setBold(true);
    font.setPixelSize(24);
    m_label->setFont(font);
    m_label->setStyleSheet("QLabel { color: gray }");

    setAcceptDrops(true);

    m_verticalLayout->addWidget(m_label);
}

QString extractFileName (const QMimeData * mimeData) {
    if (mimeData->hasUrls()) {
        foreach (const QUrl &url, mimeData->urls()) {
            QString str = url.toLocalFile();
            if(!str.isEmpty()) return str;
        }
    }

    return QString();
}

void WelcomeScreen::dragEnterEvent(QDragEnterEvent * event) {
    QString fileName = extractFileName(event->mimeData());

    if (!fileName.isEmpty()) event->accept();
}

void WelcomeScreen::dropEvent (QDropEvent * event) {
    QString fileName = extractFileName(event->mimeData());

    if (!fileName.isEmpty()) emit fileDropped(fileName);
}
