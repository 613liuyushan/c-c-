#include <thread>
#include <iostream>
#include <functional>
#include <condition_variable>

class CTimer
{
public:
    CTimer() = default;
    void starTimer(int lastime, std::function<void()> task) {


        m_thr = std::thread([this, lastime, task] {
            std::unique_lock<std::mutex> locker(m_mtx);
            while (!m_condVal.wait_for(locker, std::chrono::seconds(lastime), [this] {return !m_isRun; })) {
                //std::this_thread::sleep_for(std::chrono::seconds(5000));
                task();
            }
            });
        // 		std::thread t(&CTimer::func, this, lastime, task);
        // 		t.join();
    };
    ~CTimer() = default;

    void stopTimer() {
        m_isRun = false;
        m_condVal.notify_all();
        if (m_thr.joinable()) {
            m_thr.join();
        }
    };

    //  	void func(int time, std::function<void()> task) {
    //  			while (m_isRun) {
    //  				std::this_thread::sleep_for(std::chrono::seconds(time));
    //  				task();
    //  			}
    //  	}
private:
    bool m_isRun = true;
    std::thread m_thr;

    std::mutex m_mtx;
    std::condition_variable m_condVal;

};

