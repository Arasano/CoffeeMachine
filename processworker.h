#ifndef PROCESSWORKER_H
#define PROCESSWORKER_H

#include <QObject>
#include <QString>
#include <functional>

class ProcessWorker : public QObject {
    Q_OBJECT

public:
    // Конструктор принимает название процесса и функцию для выполнения работы
    explicit ProcessWorker(const QString& processName,
                           std::function<void()> workFunction,
                           QObject* parent = nullptr);

public slots:
    void process();
    void cancel();

signals:
    void progressUpdated(const QString& processName, int timeLeft, int totalTime, double progress);
    void finished(const QString& processName);
    void cancelled(const QString& processName);

private:
    QString m_processName;
    std::function<void()> m_workFunction;
    bool m_cancelled;
};

#endif
