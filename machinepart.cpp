#include "machinepart.h"
#include <QThread>
#include <qdebug.h>

MachinePart::MachinePart(const QString& name, int preparationTime, QObject* parent)
    : QObject(parent),
    partName(name),
    preparationTime(preparationTime),
    m_working(false)
{
}

double MachinePart::getPreparationTime() const {
    return this->preparationTime;
}

QString MachinePart::getPartName() const {
    return this->partName;
}

void MachinePart::startWork(int time) {
    if (m_working) return;

    m_working = true;
    m_time = time;
    m_timeLeft = time;

    emit workStarted(partName);

    m_progressTimer = new QTimer(this);
    connect(m_progressTimer, &QTimer::timeout, this, &MachinePart::updateProgress);
    m_progressTimer->start(1000);
}

void MachinePart::finishWork() {
    if (m_progressTimer) {
        m_progressTimer->stop();
        m_progressTimer->deleteLater();
    }
    m_working = false;

    emit workFinished(partName);
}

bool MachinePart::isWorking() const {
    return m_working;
}

QString MachinePart::getName() const {
    return partName;
}

void MachinePart::cancelWork() {
    if (m_progressTimer) {
        m_progressTimer->stop();
        m_progressTimer->deleteLater();
    }
    m_working = false;

    emit workCancelled(partName);
}

void MachinePart::updateProgress() {
    if (m_timeLeft > 0) {
        m_timeLeft--;
        emit progressUpdated(partName, m_timeLeft, m_time);
    }else{
        finishWork();
    }
}
