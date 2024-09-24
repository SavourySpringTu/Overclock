#include "About.h"

About::About(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *aboutLabel = new QLabel(this);
    aboutLabel->setText(
        "<h2>About Overclock</h2>"
        "<p><strong>Version:</strong> 1.0</p>"
        "<p><strong>Author:</strong> Bùi Xuân Tú</p>"
        "<p><strong>Occupation:</strong> Software Engineer</p>"
        "<p><strong>Year of Creation:</strong> 2024</p>"
        "<p><strong>Description:</strong> Monitors the computer and supports overclocking to optimize performance.</p>"
        "<p><strong>License:</strong> LGPL</p>"
        "<p><strong>Contact:</strong> tuxuanbui1111@gmail.com</p>"
        "<p>You are free to modify this software, but please respect my copyright.</p>"
        "<p>I encourage everyone to contribute to its development while honoring the author's rights.</p>"
        );
    aboutLabel->setWordWrap(true);

    // Thêm hình ảnh
    QLabel *imageLabel = new QLabel(this);

   QPixmap pixmap(":/avt.jpg");// Đường dẫn trong qrc
    if (pixmap.isNull()) {
        qDebug() << "Failed to load image!";
    } else {
        qDebug() << "Image loaded successfully.";
    }
    imageLabel->setPixmap(pixmap);
    layout->addWidget(aboutLabel);
    layout->addWidget(imageLabel); // Thêm hình ảnh vào layout
    setLayout(layout);
}
