#include "device.h"

Device::Device(const QString& name, int preparationTime, QObject* parent)
    : QObject(parent),
    m_name(name),
    m_preparationTime(preparationTime),
    m_timeLeft(preparationTime),
    m_isWorking(false),
    m_workTimer(new QTimer(this))
{
    connect(m_workTimer, &QTimer::timeout, this, &Device::onWorkTimer);
}

QString Device::getName() const {
    return m_name;
}

int Device::getPreparationTime() const {
    return m_preparationTime;
}

bool Device::isWorking() const {
    return m_isWorking;
}

void Device::startWork() {
    if (m_isWorking) return;

    m_isWorking = true;
    m_timeLeft = m_preparationTime;

    emit workStarted(m_name);

    // Запускаем таймер для обновления прогресса
    m_workTimer->start(1000); // Обновление каждую секунду

    // Запускаем конкретную работу устройства
    performWork();
}

void Device::cancelWork() {
    if (!m_isWorking) return;

    m_workTimer->stop();
    m_isWorking = false;
    emit workCancelled(m_name);
}

void Device::onWorkTimer() {
    m_timeLeft--;

    if (m_timeLeft <= 0) {
        m_workTimer->stop();
        m_isWorking = false;
        emit workFinished(m_name);
    } else {
        double progress = (1.0 - static_cast<double>(m_timeLeft) / m_preparationTime) * 100;
        emit progressUpdated(m_name, m_timeLeft, m_preparationTime, progress);
    }
}
