#ifndef GPODDERANDROID_H
#define GPODDERANDROID_H

#include <QObject>

class GPodderAndroid : public QObject {
    Q_OBJECT

public:
    GPodderAndroid(QObject *parent=0);
    ~GPodderAndroid();

signals:
    void audioBecomingNoisy();
};

#endif /* GPODDERANDROID_H */
