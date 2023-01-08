#include<iostream>

class Log
{
public:
    enum Level
    {
        Level_Error = 0,Level_Warning,Level_Info
    };
private:
    int m_LogLevel = Level_Info;

public:
    void SetLevel(int level)
    {
       m_LogLevel=level;
    }

    void Warn(const char* message)
    {  if(m_LogLevel>=Level_Warning)
       std::cout<<"[Warning]"<<message<<std::endl;
    }
    void Info(const char* message)
    {  if(m_LogLevel>=Level_Info)
       std::cout<<"[Info]"<<message<<std::endl;
    }
    void Error(const char* message)
    {  if(m_LogLevel>=Level_Error)
       std::cout<<"[Error]"<<message<<std::endl;
    }
     
};

int main()
{
    Log log;
    log.SetLevel(log.Level_Error);
    log.Warn("hello");
    log.Error("hello");
    log.Info("hello");
    std::cin.get();
}