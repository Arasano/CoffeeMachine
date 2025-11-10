#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QTimer>

class Device : public QObject {
    Q_OBJECT

public:
    explicit Device(const QString& name, int preparationTime, QObject* parent = nullptr);
    virtual ~Device() = default;

    QString getName() const;
    int getPreparationTime() const;
    bool isWorking() const;

public slots:
    virtual void startWork();
    virtual void cancelWork();

signals:
    void progressUpdated(const QString& deviceName, int timeLeft, int totalTime, double progress);
    void workStarted(const QString& deviceName);
    void workFinished(const QString& deviceName);
    void workCancelled(const QString& deviceName);

protected:
    virtual void performWork() = 0; // Абстрактный метод - должны реализовать потомки

private slots:
    void onWorkTimer();

protected:
    QString m_name;
    int m_preparationTime;
    int m_timeLeft;
    bool m_isWorking;
    QTimer* m_workTimer;
};

#endif
