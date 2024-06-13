#include "threads.h"
#include <windows.h>

using namespace std;

HANDLE mutex;
HANDLE aSemaphore, cSemaphore, dSemaphore, eSemaphore, gSemaphore, hSemaphore, iSemaphore, kSemaphore;
HANDLE waitSemaphore, beginSemaphore;
HANDLE thread_a, thread_b, thread_c, thread_d, thread_e, thread_f, thread_g, thread_h, thread_i, thread_k, thread_m;

DWORD WINAPI aThread(LPVOID IpParam) {
    UNREFERENCED_PARAMETER(IpParam); // Параметр lpParam не используется
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(aSemaphore, INFINITE); // Уменьшаем счетчик семафора
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "a" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
        ReleaseSemaphore(cSemaphore, 1, nullptr); // Увеличиваем счетчик семафора
    }
    return 0;
}

DWORD WINAPI bThread(LPVOID IpParam) {
    UNREFERENCED_PARAMETER(IpParam); // Параметр lpParam не используется
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "b" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
    }
    return 0;
}

DWORD WINAPI cThread(LPVOID IpParam) {
    UNREFERENCED_PARAMETER(IpParam); // Параметр lpParam не используется
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(cSemaphore, INFINITE); // Уменьшаем счетчик семафора
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "c" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
        ReleaseSemaphore(eSemaphore, 1, nullptr); // Увеличиваем счетчик семафора
    }

    ReleaseSemaphore(waitSemaphore, 1, nullptr); // Увеличиваем счетчик семафора, заявляя о завершении cTread
    WaitForSingleObject(beginSemaphore, INFINITE); // Уменьшаем счетчик семафора, давая возможность началу cTread

    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "c" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
    }
    return 0;
}

DWORD WINAPI dThread(LPVOID IpParam) {
    UNREFERENCED_PARAMETER(IpParam); // Параметр lpParam не используется
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(dSemaphore, INFINITE); // Уменьшаем счетчик семафора
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "d" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
        ReleaseSemaphore(aSemaphore, 1, nullptr); // Увеличиваем счетчик семафора
    }

    ReleaseSemaphore(waitSemaphore, 1, nullptr); // Увеличиваем счетчик семафора, заявляя о завершении dTread
    WaitForSingleObject(beginSemaphore, INFINITE); // Уменьшаем счетчик семафора, давая возможность началу dTread

    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "d" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
    }

    ReleaseSemaphore(waitSemaphore, 1, nullptr); // Увеличиваем счетчик семафора, заявляя о завершении dTread
    WaitForSingleObject(beginSemaphore, INFINITE); // Уменьшаем счетчик семафора, давая возможность началу dTread

    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(dSemaphore, INFINITE); // Уменьшаем счетчик семафора
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "d" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
        ReleaseSemaphore(eSemaphore, 1, nullptr); // Увеличиваем счетчик семафора
    }
    return 0;
}

DWORD WINAPI eThread(LPVOID IpParam) {
    UNREFERENCED_PARAMETER(IpParam); // Параметр lpParam не используется
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(eSemaphore, INFINITE); // Уменьшаем счетчик семафора
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "e" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
        ReleaseSemaphore(dSemaphore, 1, nullptr);  // Увеличиваем счетчик семафора
    }

    ReleaseSemaphore(waitSemaphore, 1, nullptr); // Увеличиваем счетчик семафора, заявляя о завершении eTread
    WaitForSingleObject(beginSemaphore, INFINITE); // Уменьшаем счетчик семафора, давая возможность началу eTread

    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "e" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
    }

    ReleaseSemaphore(waitSemaphore, 1, nullptr); // Увеличиваем счетчик семафора, заявляя о завершении eTread
    WaitForSingleObject(beginSemaphore, INFINITE); // Уменьшаем счетчик семафора, давая возможность началу eTread

    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(eSemaphore, INFINITE); // Уменьшаем счетчик семафора
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "e" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
        ReleaseSemaphore(gSemaphore, 1, nullptr); // Увеличиваем счетчик семафора
    }

    ReleaseSemaphore(waitSemaphore, 1, nullptr); // Увеличиваем счетчик семафора, заявляя о завершении eTread
    WaitForSingleObject(beginSemaphore, INFINITE); // Уменьшаем счетчик семафора, давая возможность началу eTread

    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "e" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
    }
    return 0;
}

DWORD WINAPI fThread(LPVOID IpParam) {
    UNREFERENCED_PARAMETER(IpParam); // Параметр lpParam не используется
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "f" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
    }
    return 0;
}

DWORD WINAPI gThread(LPVOID IpParam) {
    UNREFERENCED_PARAMETER(IpParam); // Параметр lpParam не используется
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(gSemaphore, INFINITE); // Уменьшаем счетчик семафора
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "g" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
        ReleaseSemaphore(hSemaphore, 1, nullptr); // Увеличиваем счетчик семафора
    }

    ReleaseSemaphore(waitSemaphore, 1, nullptr); // Увеличиваем счетчик семафора, заявляя о завершении gTread
    WaitForSingleObject(beginSemaphore, INFINITE); // Уменьшаем счетчик семафора, давая возможность началу gTread

    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "g" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
    }
    return 0;
}

DWORD WINAPI hThread(LPVOID IpParam) {
    UNREFERENCED_PARAMETER(IpParam); // Параметр lpParam не используется
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(hSemaphore, INFINITE); // Уменьшаем счетчик семафора
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "h" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
        ReleaseSemaphore(dSemaphore, 1, nullptr); // Увеличиваем счетчик семафора
    }

    ReleaseSemaphore(waitSemaphore, 1, nullptr); // Увеличиваем счетчик семафора, заявляя о завершении hTread
    WaitForSingleObject(beginSemaphore, INFINITE); // Уменьшаем счетчик семафора, давая возможность началу hTread

    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "h" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
    }

    ReleaseSemaphore(waitSemaphore, 1, nullptr); // Увеличиваем счетчик семафора, заявляя о завершении hTread
    WaitForSingleObject(beginSemaphore, INFINITE); // Уменьшаем счетчик семафора, давая возможность началу hTread

    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(hSemaphore, INFINITE); // Уменьшаем счетчик семафора
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "h" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
        ReleaseSemaphore(kSemaphore, 1, nullptr); // Увеличиваем счетчик семафора
    }
    return 0;
}

DWORD WINAPI iThread(LPVOID IpParam) {
    UNREFERENCED_PARAMETER(IpParam); // Параметр lpParam не используется
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(iSemaphore, INFINITE); // Уменьшаем счетчик семафора
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "i" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
        ReleaseSemaphore(hSemaphore, 1, nullptr); // Увеличиваем счетчик семафора
    }
    return 0;
}

DWORD WINAPI kThread(LPVOID IpParam) {
    UNREFERENCED_PARAMETER(IpParam); // Параметр lpParam не используется
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(kSemaphore, INFINITE); // Уменьшаем счетчик семафора
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "k" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
        ReleaseSemaphore(iSemaphore, 1, nullptr); // Увеличиваем счетчик семафора
    }
    return 0;
}

DWORD WINAPI mThread(LPVOID IpParam) {
    UNREFERENCED_PARAMETER(IpParam); // Параметр lpParam не используется
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(mutex, INFINITE); // Запрашиваем владение мьютексом
        cout << "m" << flush;
        ReleaseMutex(mutex); // Освобождаем mutex
        computation();
    }
    return 0;
}

unsigned int thread_graph_id() // Номер графа
{
    return 4;
}

const char* unsynchronized_threads() // Несинхронизированные потоки
{
    return "efgh";
}

const char* sequential_threads() // Потоки запускаемые в определенном порядке
{
    return "degh";
}

int threads_init()
{
    mutex = CreateMutex(nullptr, 0, nullptr);
    if (mutex == nullptr) {
        cout << "CreateMutex error: " <<  GetLastError() << endl;
        return 1;
    }
    
    aSemaphore = CreateSemaphore(nullptr, 0, 1, nullptr);
    if (aSemaphore == nullptr) {
        cout << "CreateSemaphore (aSemaphore) error: " << GetLastError() << endl;
        return 1;
    }
    cSemaphore = CreateSemaphore(nullptr, 0, 1, nullptr);
    if (cSemaphore == nullptr) {
        cout << "CreateSemaphore (cSemaphore) error: " << GetLastError() << endl;
        return 1;
    }
    dSemaphore = CreateSemaphore(nullptr, 1, 1, nullptr);
    if (dSemaphore == nullptr) {
        cout << "CreateSemaphore (dSemaphore) error: " << GetLastError() << endl;
        return 1;
    }
    eSemaphore = CreateSemaphore(nullptr, 0, 1, nullptr);
    if (eSemaphore == nullptr) {
        cout << "CreateSemaphore (eSemaphore) error: " << GetLastError() << endl;
        return 1;
    }
    gSemaphore = CreateSemaphore(nullptr, 0, 1, nullptr);
    if (gSemaphore == nullptr) {
        cout << "CreateSemaphore (gSemaphore) error: " << GetLastError() << endl;
        return 1;
    }
    hSemaphore = CreateSemaphore(nullptr, 0, 1, nullptr);
    if (hSemaphore == nullptr) {
        cout << "CreateSemaphore (hSemaphore) error: " << GetLastError() << endl;
        return 1;
    }
    iSemaphore = CreateSemaphore(nullptr, 1, 1, nullptr);
    if (iSemaphore == nullptr) {
        cout << "CreateSemaphore (iSemaphore) error: " << GetLastError() << endl;
        return 1;
    }
    kSemaphore = CreateSemaphore(nullptr, 0, 1, nullptr);
    if (kSemaphore == nullptr) {
        cout << "CreateSemaphore (kSemaphore) error: " << GetLastError() << endl;
        return 1;
    }
    waitSemaphore = CreateSemaphore(nullptr, 0, 3, nullptr);
    if (waitSemaphore == nullptr) {
        cout << "CreateSemaphore (waitSemaphore) error: " << GetLastError() << endl;
        return 1;
    }
    beginSemaphore = CreateSemaphore(nullptr, 0, 3, nullptr);
    if (beginSemaphore == nullptr) {
        cout << "CreateSemaphore (beginSemaphore) error: " << GetLastError() << endl;
        return 1;
    }

    //_____1-ый интервал
    thread_a = CreateThread(nullptr, 0, aThread, nullptr, 0, nullptr);
    if (thread_a == nullptr) {
        cout << "CreateThread (aTread) error: " << GetLastError() << endl;
        return 1;
    }
    thread_c = CreateThread(nullptr, 0, cThread, nullptr, 0, nullptr);
    if (thread_c == nullptr) {
        cout << "CreateThread (cTread) error: " << GetLastError() << endl;
        return 1;
    }
    thread_d = CreateThread(nullptr, 0, dThread, nullptr, 0, nullptr);
    if (thread_d == nullptr) {
        cout << "CreateThread (dTread) error: " << GetLastError() << endl;
        return 1;
    }
    thread_e = CreateThread(nullptr, 0, eThread, nullptr, 0, nullptr);
    if (thread_e == nullptr) {
        cout << "CreateThread (eTread) error: " << GetLastError() << endl;
        return 1;
    }

    WaitForSingleObject(thread_a, INFINITE); // Ожидаем окончания потока aTread

    CloseHandle(thread_a); // Закрываем поток a
    CloseHandle(aSemaphore); // Закрываем семафор a

    // Уменьшаем счетчик семафора ожидания на -3, после прохождения 1-го интервала потокамм cTread, dTread, eTread
    WaitForSingleObject(waitSemaphore, INFINITE);
    WaitForSingleObject(waitSemaphore, INFINITE);
    WaitForSingleObject(waitSemaphore, INFINITE);

    //_____2-ой интервал
    ReleaseSemaphore(beginSemaphore, 3, nullptr); // Увеличиваем счетчик семафора начала на 3

    thread_b = CreateThread(nullptr, 0, bThread, nullptr, 0, nullptr);
    if (thread_b == nullptr) {
        cout << "CreateThread (bTread) error: " << GetLastError() << endl;
        return 1;
    }

    WaitForSingleObject(thread_b, INFINITE); // Ожидаем окончания потока bTread
    WaitForSingleObject(thread_c, INFINITE); // Ожидаем окончания потока cTread

    CloseHandle(thread_b); // Закрываем поток b
    CloseHandle(thread_c); // Закрываем поток c
    CloseHandle(cSemaphore); // Закрываем семафор c

    // Уменьшаем счетчик семафора ожидания на -2, после прохождения 2-го интервала потокамм dTread, eTread
    WaitForSingleObject(waitSemaphore, INFINITE);
    WaitForSingleObject(waitSemaphore, INFINITE);

    //_____3-ий интервал
    ReleaseSemaphore(beginSemaphore, 2, nullptr); // Увеличиваем счетчик семафора начала на 2

    thread_g = CreateThread(nullptr, 0, gThread, nullptr, 0, nullptr);
    if (thread_g == nullptr) {
        cout << "CreateThread (gTread) error: " << GetLastError() << endl;
        return 1;
    }
    thread_h = CreateThread(nullptr, 0, hThread, nullptr, 0, nullptr);
    if (thread_h == nullptr) {
        cout << "CreateThread (hTread) error: " << GetLastError() << endl;
        return 1;
    }

    WaitForSingleObject(thread_d, INFINITE); // Ожидаем окончания потока dTread

    CloseHandle(thread_d); // Закрываем поток d
    CloseHandle(dSemaphore); // Закрываем семафор d

    // Уменьшаем счетчик семафора ожидания на -3, после прохождения 3-го интервала потоками eTread, gTread, hTread
    WaitForSingleObject(waitSemaphore, INFINITE);
    WaitForSingleObject(waitSemaphore, INFINITE);
    WaitForSingleObject(waitSemaphore, INFINITE);

    //_____4-ый интервал
    ReleaseSemaphore(beginSemaphore, 3, nullptr); // Увеличиваем счетчик семафора начала на 3

    thread_f = CreateThread(nullptr, 0, fThread, nullptr, 0, nullptr);
    if (thread_f == nullptr) {
        cout << "CreateThread (fTread) error: " << GetLastError() << endl;
        return 1;
    }

    WaitForSingleObject(thread_e, INFINITE); // Ожидаем окончания потока eTread
    WaitForSingleObject(thread_f, INFINITE); // Ожидаем окончания потока fTread
    WaitForSingleObject(thread_g, INFINITE); // Ожидаем окончания потока gTread

    CloseHandle(thread_e); // Закрываем поток e
    CloseHandle(thread_f); // Закрываем поток f
    CloseHandle(thread_g); // Закрываем поток g
    CloseHandle(eSemaphore); // Закрываем семафор e
    CloseHandle(gSemaphore); // Закрываем семафор g

    // Уменьшаем счетчик семафора ожидания на -1, после прохождения 4-го интервала потоком hTread
    WaitForSingleObject(waitSemaphore, INFINITE);

    //_____5-ый интервал
    ReleaseSemaphore(beginSemaphore, 1, nullptr);

    thread_i = CreateThread(nullptr, 0, iThread, nullptr, 0, nullptr);
    if (thread_i == nullptr) {
        cout << "CreateThread (iTread) error: " << GetLastError() << endl;
        return 1;
    }
    thread_k = CreateThread(nullptr, 0, kThread, nullptr, 0, nullptr);
    if (thread_k == nullptr) {
        cout << "CreateThread (kTread) error: " << GetLastError() << endl;
        return 1;
    }

    WaitForSingleObject(thread_h, INFINITE); // Ожидаем окончания потока hTread
    WaitForSingleObject(thread_i, INFINITE); // Ожидаем окончания потока iTread
    WaitForSingleObject(thread_k, INFINITE); // Ожидаем окончания потока kTread

    CloseHandle(thread_h); // Закрываем поток h
    CloseHandle(thread_i); // Закрываем поток i
    CloseHandle(thread_k); // Закрываем поток k
    CloseHandle(hSemaphore); // Закрываем семафор h
    CloseHandle(iSemaphore); // Закрываем семафор i
    CloseHandle(kSemaphore); // Закрываем семафор k

    //_____6-ой интервал
    thread_m = CreateThread(nullptr, 0, mThread, nullptr, 0, nullptr);
    if (thread_m == nullptr) {
        cout << "CreateThread (mTread) error: " << GetLastError() << endl;
        return 1;
    }

    WaitForSingleObject(thread_m, INFINITE); // Ожидаем окончания потока mTread

    CloseHandle(thread_m); // Закрываем поток m
    CloseHandle(waitSemaphore); // Закрываем семафор wait
    CloseHandle(beginSemaphore); // Закрываем семафор begin
    CloseHandle(mutex); // Закрываем mutex

    return 0;
}