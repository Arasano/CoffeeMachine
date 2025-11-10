#include "processworker.h"
#include <QThread>

ProcessWorker::ProcessWorker(const QString& processName,
                             std::function<void()> workFunction,
                             QObject* parent)
    : QObject(parent),
    m_processName(processName),
    m_workFunction(workFunction),
    m_cancelled(false)
{
}

void ProcessWorker::process() {
    if (m_workFunction) {
        // Выполняем реальную работу объекта
        m_workFunction();
    }

    emit finished(m_processName);
}

void ProcessWorker::cancel() {
    m_cancelled = true;
    emit cancelled(m_processName);
}
