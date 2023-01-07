#include<iostream>

class Log
{
public:
    const int LogLevelError = 0;
    const int LogLevelWaning = 1;
    const int LogLevelInfo = 2;
private:
    int m_LogLevel = LogLevelInfo;

public:
    void SetLevel(int level)
    {
       m_LogLevel=level;
    }

    void Warn(const char* message)
    {  if(m_LogLevel>=LogLevelWaning)
       std::cout<<"[Warning]"<<message<<std::endl;
    }
    void Info(const char* message)
    {  if(m_LogLevel>=LogLevelInfo)
       std::cout<<"[Info]"<<message<<std::endl;
    }
    void Error(const char* message)
    {  if(m_LogLevel>=LogLevelError)
       std::cout<<"[Error]"<<message<<std::endl;
    }
     
};

int main()
{
    Log log;
    log.SetLevel(log.LogLevelWaning);
    log.Warn("hello");
    log.Error("hello");
    log.Info("hello");
    std::cin.get();
}