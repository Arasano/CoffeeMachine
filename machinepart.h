#ifndef MACHINEPART_H
#define MACHINEPART_H

#include <QObject>
#include <QString>
#include <QTimer>
#include "workable.h"

class MachinePart : public QObject, public Workable
{
    Q_OBJECT

protected:
    QString partName;
    int preparationTime;

    bool m_working = false;
    QTimer* m_progressTimer;
    int m_time;
    int m_timeLeft;

public:
    MachinePart(const QString& name, int preparationTime, QObject* parent = nullptr);
    virtual ~MachinePart() = default;

    double getPreparationTime() const;
    QString getPartName() const;

    void startWork(int preparationTime) override;
    void finishWork() override;
    bool isWorking() const override;
    QString getName() const override;
    void cancelWork() override;

signals:
    void progressUpdated(const QString& name, int timeLeft, int totalTime);
    void workStarted(const QString& name);
    void workFinished(const QString& name);
    void workCancelled(const QString& name);

private slots:
    void updateProgress();
};

#endif // MACHINEPART_H
