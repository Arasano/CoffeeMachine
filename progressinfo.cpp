#ifndef PROCESSINFO_H
#define PROCESSINFO_H

#include <QString>
#include <QMetaType>

#include <processtype.h>

struct ProgressInfo {
    ProcessType type;
    QString processName;
    int timeLeft;  // Оставшееся время в секундах
    int totalTime; // Общее время процесса
    double progress; // Прогресс 0-100%

    ProgressInfo() = default; // Конструктор по умолчанию

    ProgressInfo(ProcessType t, const QString& name, int left, int total)
        : type(t), processName(name), timeLeft(left), totalTime(total),
        progress(total > 0 ? (1.0 - static_cast<double>(left) / total) * 100 : 0) {}
};

// Регистрируем тип для использования в сигналах/слотах
Q_DECLARE_METATYPE(ProgressInfo)

#endif
